#include <osg/Image>
#include <osg/Notify>
#include <osg/Geode>
#include <osg/GL>
#include <osg/Endian>

#include <osgDB/Registry>
#include <osgDB/FileUtils>
#include <osgDB/FileNameUtils>

using namespace osg;

extern "C"
{
    #include <zlib.h>
    #include <png.h>
}


/* Transparency parameters */
#define PNG_ALPHA     -2         /* Use alpha channel in PNG file, if there is one */
#define PNG_SOLID     -1         /* No transparency                                */
#define PNG_STENCIL    0         /* Sets alpha to 0 for r=g=b=0, 1 otherwise       */

typedef struct
{
    unsigned int Width;
    unsigned int Height;
    unsigned int Depth;
    unsigned int Alpha;
} pngInfo;

void png_read_istream(png_structp png_ptr, png_bytep data, png_size_t length)
{
    std::istream *stream = (std::istream*)png_get_io_ptr(png_ptr); //Get pointer to istream
    stream->read((char*)data,length); //Read requested amount of data
}

void png_write_ostream(png_structp png_ptr, png_bytep data, png_size_t length)
{
    std::ostream *stream = (std::ostream*)png_get_io_ptr(png_ptr); //Get pointer to ostream
    stream->write((char*)data,length); //Write requested amount of data
}

void png_flush_ostream(png_structp png_ptr)
{
    std::ostream *stream = (std::ostream*)png_get_io_ptr(png_ptr); //Get pointer to ostream
    stream->flush();
}

class ReaderWriterPNG : public osgDB::ReaderWriter
{
    public:
        virtual const char* className() const { return "PNG Image Reader/Writer"; }
        virtual bool acceptsExtension(const std::string& extension) const { return osgDB::equalCaseInsensitive(extension,"png"); }

        WriteResult::WriteStatus writePngStream(std::ostream& fout, const osg::Image& img) const
        {
            png_structp png = NULL;
            png_infop   info = NULL;
            int color;
            png_bytep *rows = NULL;

            //Create write structure
            png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
            if(!png) return WriteResult::ERROR_IN_WRITING_FILE;

            //Create infr structure
            info = png_create_info_struct(png);
            if(!info) return WriteResult::ERROR_IN_WRITING_FILE;

            //Set custom write function so it will write to ostream
            png_set_write_fn(png,&fout,png_write_ostream,png_flush_ostream);

            switch(img.getPixelFormat()) {
                case(GL_LUMINANCE): color = PNG_COLOR_TYPE_GRAY; break;
                case(GL_ALPHA): color = PNG_COLOR_TYPE_GRAY; break; //Couldn't find a color type for pure alpha, using gray instead
                case(GL_LUMINANCE_ALPHA): color = PNG_COLOR_TYPE_GRAY_ALPHA ; break;
                case(GL_RGB): color = PNG_COLOR_TYPE_RGB; break;
                case(GL_RGBA): color = PNG_COLOR_TYPE_RGB_ALPHA; break;
                default: return WriteResult::ERROR_IN_WRITING_FILE; break;                
            }

            //Create row data
            rows = new png_bytep[img.t()];
            for(int i = 0; i < img.t(); ++i) {
                rows[i] = (png_bytep)img.data(0,img.t() - i - 1);
            }

            //Write header info
            png_set_IHDR(png, info, img.s(), img.t(),
                        8, color, PNG_INTERLACE_NONE,
                        PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

            png_write_info(png, info);

            //Write data
            png_write_image(png, rows);

            //End write
            png_write_end(png, NULL);

            //Cleanup
            png_destroy_write_struct(&png,&info);
            delete [] rows;

            return WriteResult::FILE_SAVED;
        }

        ReadResult readPNGStream(std::istream& fin) const
        {
            int trans = PNG_ALPHA;
            pngInfo pInfo;
            pngInfo *pinfo = &pInfo;

            unsigned char header[8];
            png_structp png;
            png_infop   info;
            png_infop   endinfo;
            png_bytep   data;    //, data2;
            png_bytep  *row_p;
            double  fileGamma;

            png_uint_32 width, height;
            int depth, color;

            png_uint_32 i;
            png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
            info = png_create_info_struct(png);
            endinfo = png_create_info_struct(png);

            fin.read((char*)header,8);
            if (fin.gcount() == 8 && png_check_sig(header, 8))
                png_set_read_fn(png,&fin,png_read_istream); //Use custom read function that will get data from istream
            else
            {
                png_destroy_read_struct(&png, &info, &endinfo);
                return ReadResult::FILE_NOT_HANDLED;
            }
            png_set_sig_bytes(png, 8);

            png_read_info(png, info);
            png_get_IHDR(png, info, &width, &height, &depth, &color, NULL, NULL, NULL);

            if (pinfo != NULL)
            {
                pinfo->Width  = width;
                pinfo->Height = height;
                pinfo->Depth  = depth;
            }

            osg::notify(osg::INFO)<<"width="<<width<<" height="<<height<<" depth="<<depth<<std::endl;
            if ( color == PNG_COLOR_TYPE_RGB) osg::notify(osg::INFO) << "color == PNG_COLOR_TYPE_RGB "<<std::endl;
            if ( color == PNG_COLOR_TYPE_GRAY) osg::notify(osg::INFO) << "color == PNG_COLOR_TYPE_GRAY "<<std::endl;
            if ( color == PNG_COLOR_TYPE_GRAY_ALPHA) osg::notify(osg::INFO) << "color ==  PNG_COLOR_TYPE_GRAY_ALPHA"<<std::endl;

            // png default to big endian, so we'll need to swap bytes if on a little endian machine.
            if (depth>8 && getCpuByteOrder()==osg::LittleEndian)
                png_set_swap(png);


            if (color == PNG_COLOR_TYPE_GRAY || color == PNG_COLOR_TYPE_GRAY_ALPHA)
            {
                //png_set_gray_to_rgb(png);
            }

            if (color&PNG_COLOR_MASK_ALPHA && trans != PNG_ALPHA)
            {
                png_set_strip_alpha(png);
                color &= ~PNG_COLOR_MASK_ALPHA;
            }



            //    if (!(PalettedTextures && mipmap >= 0 && trans == PNG_SOLID))
            //if (color == PNG_COLOR_TYPE_PALETTE)
            //    png_set_expand(png);

            // In addition to expanding the palette, we also need to check
            // to expand greyscale and alpha images.  See libpng man page.
            if (color == PNG_COLOR_TYPE_PALETTE)
                png_set_palette_to_rgb(png);
            if (color == PNG_COLOR_TYPE_GRAY && depth < 8)
                png_set_gray_1_2_4_to_8(png);
            if (png_get_valid(png, info, PNG_INFO_tRNS))
                png_set_tRNS_to_alpha(png);

            // Make sure that files of small depth are packed properly.
            if (depth < 8)
                png_set_packing(png);


            /*--GAMMA--*/
            //    checkForGammaEnv();
            double screenGamma = 2.2 / 1.0;
            if (png_get_gAMA(png, info, &fileGamma))
                png_set_gamma(png, screenGamma, fileGamma);
            else
                png_set_gamma(png, screenGamma, 1.0/2.2);

            png_read_update_info(png, info);

            data = (png_bytep) new unsigned char [png_get_rowbytes(png, info)*height];
            row_p = new png_bytep [height];

            bool StandardOrientation = true;
            for (i = 0; i < height; i++)
            {
                if (StandardOrientation)
                    row_p[height - 1 - i] = &data[png_get_rowbytes(png, info)*i];
                else
                    row_p[i] = &data[png_get_rowbytes(png, info)*i];
            }

            png_read_image(png, row_p);
            delete [] row_p;
            png_read_end(png, endinfo);

            GLenum pixelFormat = 0;
            GLenum dataType = depth<=8?GL_UNSIGNED_BYTE:GL_UNSIGNED_SHORT;
            switch(color)
            {
              case(PNG_SOLID): pixelFormat = GL_LUMINANCE; break;
              case(PNG_ALPHA): pixelFormat = GL_ALPHA; break;
              case(PNG_COLOR_TYPE_GRAY): pixelFormat =GL_LUMINANCE ; break;
              case(PNG_COLOR_TYPE_GRAY_ALPHA): pixelFormat = GL_LUMINANCE_ALPHA; break;
              case(PNG_COLOR_TYPE_RGB): pixelFormat = GL_RGB; break;
              case(PNG_COLOR_TYPE_PALETTE): pixelFormat = GL_RGB; break;
              case(PNG_COLOR_TYPE_RGB_ALPHA): pixelFormat = GL_RGBA; break;
              default: break;                
            }

            // Some paletted images contain alpha information.  To be
            // able to give that back to the calling program, we need to
            // check the number of channels in the image.  However, the
            // call might not return correct information unless
            // png_read_end is called first.  See libpng man page.
            if (pixelFormat == GL_RGB && png_get_channels(png, info) == 4)
                pixelFormat = GL_RGBA;

            int internalFormat = pixelFormat;

            png_destroy_read_struct(&png, &info, &endinfo);

            //    delete [] data;

            if (pixelFormat==0) 
                return ReadResult::FILE_NOT_HANDLED;

            osg::Image* pOsgImage = new osg::Image();

            pOsgImage->setImage(width, height, 1,
                internalFormat,
                pixelFormat, 
                dataType,
                data,
                osg::Image::USE_NEW_DELETE);

            return pOsgImage;
        }

        virtual ReadResult readImage(std::istream& fin,const Options* =NULL) const
        {
            return readPNGStream(fin);
        }

        virtual ReadResult readImage(const std::string& file, const osgDB::ReaderWriter::Options* options) const
        {
            std::string ext = osgDB::getLowerCaseFileExtension(file);
            if (!acceptsExtension(ext)) return ReadResult::FILE_NOT_HANDLED;

            std::string fileName = osgDB::findDataFile( file, options );
            if (fileName.empty()) return ReadResult::FILE_NOT_FOUND;

            std::ifstream istream(fileName.c_str(), std::ios::in | std::ios::binary);
            if(!istream) return ReadResult::FILE_NOT_HANDLED;
            ReadResult rr = readPNGStream(istream);
            if(rr.validImage()) rr.getImage()->setFileName(file);
            return rr;
        }

        virtual WriteResult writeImage(const osg::Image& img,std::ostream& fout,const osgDB::ReaderWriter::Options *options) const
        {
            WriteResult::WriteStatus ws = writePngStream(fout,img);
            return ws;
        }

        virtual WriteResult writeImage(const osg::Image &img,const std::string& fileName, const osgDB::ReaderWriter::Options *options) const
        {
            std::string ext = osgDB::getFileExtension(fileName);
            if (!acceptsExtension(ext)) return WriteResult::FILE_NOT_HANDLED;

            std::ofstream fout(fileName.c_str(), std::ios::out | std::ios::binary);
            if(!fout) return WriteResult::ERROR_IN_WRITING_FILE;

            return writeImage(img,fout,options);
        }
};

// now register with Registry to instantiate the above
// reader/writer.
osgDB::RegisterReaderWriterProxy<ReaderWriterPNG> g_readerWriter_PNG_Proxy;
