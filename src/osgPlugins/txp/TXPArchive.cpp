#include <osg/Notify>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/AlphaFunc>
#include <osg/Group>
#include <osg/Image>
#include <osg/Texture2D>
#include <osg/Material>
#include <osg/TexEnv>
#include <osg/CullFace>
#include <osg/Light>
#include <osg/StateSet>
#include <osg/Point>
#include <osg/BlendFunc>
#include <osgDB/FileUtils>
#include <osgDB/FileUtils>
#include <osgDB/FileNameUtils>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgSim/Sector>
#include <osgSim/LightPoint>
#include <osgSim/LightPointNode>
#include <osgSim/BlinkSequence>
#include <iostream>
#include <fstream>


#include "TXPArchive.h"
#include "TXPParser.h"

#include <OpenThreads/ScopedLock>

using namespace txp;

#define TXPArchiveERROR(s) osg::notify(osg::NOTICE) << "txp::TXPArchive::" << (s) << " error: "

TXPArchive::TXPArchive():
trpgr_Archive(),
_id(-1),
_numLODs(0),
_swExtents(0.0,0.0),
_neExtents(0.0,0.0)
{
}

TXPArchive::~TXPArchive()
{
    CloseFile();
}



bool TXPArchive::openFile(const std::string& archiveName)
{
    std::string path = osgDB::getFilePath(archiveName);
    std::string name = osgDB::getSimpleFileName(archiveName);
    
    if(path.empty())
    {
        SetDirectory(".");
    }
    else
    {
        // push the path to the front of the list so that all subsequenct
        // files get loaded relative to this if possible.
        osgDB::getDataFilePathList().push_front(path);
        SetDirectory(path.c_str());
    }
    
    if (!OpenFile(name.c_str()))
    {
        TXPArchiveERROR("openFile()") << "couldn't open archive: " << archiveName << std::endl;
        return false;
    }

    if (!ReadHeader())
    {
        TXPArchiveERROR("openFile()") << "couldn't read header for archive: " << archiveName << std::endl;
        return false;
    }

    const trpgHeader *header = GetHeader();
    if (header)
    {
        header->GetNumLods(_numLODs);
        header->GetExtents(_swExtents,_neExtents);
    }

    int numTextures;
    texTable.GetNumTextures(numTextures);
    _textures.resize(numTextures);

    int numModel;
    modelTable.GetNumModels(numModel);
    _models.resize(numModel);

    int numMaterials;
    materialTable.GetNumMaterial(numMaterials);
    _gstates.resize(numMaterials);

    return true;
}

bool TXPArchive::loadMaterial(int ix)
{
    int i = ix;

    if (_gstates[ix].get()) return true;

    osg::StateSet* osg_state_set = new osg::StateSet;
            
    const trpgMaterial *mat;
    mat = materialTable.GetMaterialRef(0,i);

    // Set texture
    int numMatTex;
    mat->GetNumTexture(numMatTex);
    
    // TODO : multitextuting
    // also note that multitexturing in terrapage can came from two sides
    // - multiple textures per material, and multiple materials per geometry
    // Note: Only in theory.  The only type you'll encounter is multiple
    //         materials per polygon.
    if( numMatTex )
    {
        osg::Material *osg_material     = new osg::Material;
        
        float64 alpha;
        mat->GetAlpha(alpha);
        
        trpgColor color;
        mat->GetAmbient(color);
        osg_material->setAmbient( osg::Material::FRONT_AND_BACK , 
            osg::Vec4(color.red, color.green, color.blue, alpha));
        mat->GetDiffuse(color);
        osg_material->setDiffuse(osg::Material::FRONT_AND_BACK , 
            osg::Vec4(color.red, color.green, color.blue, alpha));
        
        mat->GetSpecular(color);
        osg_material->setSpecular(osg::Material::FRONT_AND_BACK , 
            osg::Vec4(color.red, color.green, color.blue, alpha));
        mat->GetEmission(color);
        osg_material->setEmission(osg::Material::FRONT_AND_BACK , 
            osg::Vec4(color.red, color.green, color.blue, alpha));

        float64 shinines;
        mat->GetShininess(shinines);
        osg_material->setShininess(osg::Material::FRONT_AND_BACK , (float)shinines);
        
        osg_material->setAlpha(osg::Material::FRONT_AND_BACK ,(float)alpha);
        osg_state_set->setAttributeAndModes(osg_material, osg::StateAttribute::ON);
        
        if( alpha < 1.0f )
        {
            osg_state_set->setMode(GL_BLEND,osg::StateAttribute::ON);
            osg_state_set->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
        }
        
        int alphaFunc;
        mat->GetAlphaFunc(alphaFunc);
        if( alphaFunc>=GL_NEVER && alphaFunc<=GL_ALWAYS)
        {
            float64 ref;
            mat->GetAlphaRef(ref);
            osg::AlphaFunc *osg_alpha_func = new osg::AlphaFunc;
            osg_alpha_func->setFunction((osg::AlphaFunc::ComparisonFunction)alphaFunc,(float)ref);
            osg_state_set->setAttributeAndModes(osg_alpha_func, osg::StateAttribute::ON);
        }
        
        for (int ntex = 0; ntex < numMatTex; ntex ++ )
        {
            int texId;
            trpgTextureEnv texEnv;
            mat->GetTexture(ntex,texId,texEnv);
        
            // Set up texture environment
            osg::TexEnv       *osg_texenv       = new osg::TexEnv();
            int32 te_mode;
            texEnv.GetEnvMode(te_mode);
            switch( te_mode )
            {
            case trpgTextureEnv::Alpha :
                osg_texenv->setMode(osg::TexEnv::REPLACE);
                break;
            case trpgTextureEnv::Decal:
                osg_texenv->setMode(osg::TexEnv::DECAL);
                break;
            case trpgTextureEnv::Blend :
                osg_texenv->setMode(osg::TexEnv::BLEND);
                break;
            case trpgTextureEnv::Modulate :
                osg_texenv->setMode(osg::TexEnv::MODULATE);
                break;
            }
        
            osg_state_set->setTextureAttribute(ntex,osg_texenv);

            int wrap_s, wrap_t;   
            texEnv.GetWrap(wrap_s, wrap_t);

            loadTexture(texId);
            osg::Texture2D* osg_texture = _textures[texId].get();
            if(osg_texture)
            {

                osg_texture->setWrap(osg::Texture2D::WRAP_S, wrap_s == trpgTextureEnv::Repeat ? osg::Texture2D::REPEAT: osg::Texture2D::CLAMP_TO_EDGE );
                osg_texture->setWrap(osg::Texture2D::WRAP_T, wrap_t == trpgTextureEnv::Repeat ? osg::Texture2D::REPEAT: osg::Texture2D::CLAMP_TO_EDGE );

                // -----------
                // Min filter
                // -----------
                int32 minFilter;
                texEnv.GetMinFilter(minFilter);
                switch (minFilter)
                {
                case trpgTextureEnv::Point:
                case trpgTextureEnv::Nearest:
                    osg_texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::NEAREST);
                    break;
                case trpgTextureEnv::Linear:
                    osg_texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
                    break;
                case trpgTextureEnv::MipmapPoint:
                    osg_texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::NEAREST_MIPMAP_NEAREST);
                    break;
                case trpgTextureEnv::MipmapLinear:
                    osg_texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::NEAREST_MIPMAP_LINEAR);
                    break;
                case trpgTextureEnv::MipmapBilinear:
                    osg_texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_NEAREST);
                    break;
                case trpgTextureEnv::MipmapTrilinear:
                    osg_texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
                    break;
                default:
                    osg_texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
                    break;
                }


                // -----------
                // Mag filter
                // -----------
                int32 magFilter;
                texEnv.GetMagFilter(magFilter);
                switch (magFilter)
                {
                case trpgTextureEnv::Point:
                case trpgTextureEnv::Nearest:
                    osg_texture->setFilter(osg::Texture2D::MAG_FILTER,osg::Texture2D::NEAREST);
                    break;
                case trpgTextureEnv::Linear:
                default:
                    osg_texture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
                    break;
                }

                // pass on to the stateset.                
                osg_state_set->setTextureAttributeAndModes(ntex,osg_texture, osg::StateAttribute::ON);

                if(osg_texture->getImage() &&  osg_texture->getImage()->isImageTranslucent())
                { 
                    osg_state_set->setMode(GL_BLEND,osg::StateAttribute::ON);
                    osg_state_set->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
                }
            }        
        }
        
        int cullMode;
        mat->GetCullMode(cullMode);
        
        // Culling mode in txp means opposite from osg i.e. Front-> show front face
        if( cullMode != trpgMaterial::FrontAndBack)
        {
            osg::CullFace* cull_face = new osg::CullFace;
            switch (cullMode)
            {
            case trpgMaterial::Front:
                cull_face->setMode(osg::CullFace::BACK);
                break;
            case trpgMaterial::Back:
                cull_face->setMode(osg::CullFace::FRONT);
                break;
            }
            osg_state_set->setAttributeAndModes(cull_face, osg::StateAttribute::ON);
        }
    }
    _gstates[i] = osg_state_set;

    return true;
}

bool TXPArchive::loadMaterials()
{
    return true;
}

bool TXPArchive::loadTexture(int i)
{
    if (_textures[i].get()) return true;

    trpgrImageHelper image_helper(this->GetEndian(),getDir(),materialTable,texTable);

    const trpgTexture *tex;
    tex = texTable.GetTextureRef(i);
    if (!tex) return false;

    trpgTexture::ImageMode mode;
    tex->GetImageMode(mode);
    if(mode == trpgTexture::External)
    {
        char texName[1024];  texName[0] = 0;
        tex->GetName(texName,1023);

        // Create a texture by name.
        osg::ref_ptr<osg::Texture2D> osg_texture = new osg::Texture2D();

        // make sure the Texture unref's the Image after apply, when it is no longer needed.                
        osg_texture->setUnRefImageDataAfterApply(true);
        
        // Load Texture and Create Texture State
        std::string filename = osgDB::getSimpleFileName(texName);
        std::string path(getDir());
#ifdef _WIN32
        const char _PATHD = '\\';
#elif defined(macintosh)
        const char _PATHD = ':';
#else
        const char _PATHD = '/';
#endif
        if( path == "." ) 
            path = "";
        else
            path += _PATHD ;
        
        std::string theFile = path + filename ;
        osg::Image* image = osgDB::readImageFile(theFile);
        if (image)
        {
            osg_texture->setImage(image);
        }
        else
        {
            osg::notify(osg::WARN) << "TrPageArchive::LoadMaterials() error: "
                << "couldn't open image: " << filename << std::endl;
        }
        _textures[i] = osg_texture;
    }
    else if( mode == trpgTexture::Local )
    {
        _textures[i] = getLocalTexture(image_helper,tex);
    }
    else if( mode == trpgTexture::Template )
    {
        _textures[i] = 0L; //GetTemplateTexture(image_helper,0, tex);
    }
    else
    {
        _textures[i] = 0;
    }

    return (_textures[i].get() != 0);
}

bool TXPArchive::loadModel(int ix)
{
    trpgModel *mod = modelTable.GetModelRef(ix);
    int type;
    mod->GetType(type);

    // Only dealing with external models currently
    if (type == trpgModel::External)
    {
        char name[1024];
        mod->GetName(name,1023);

        // Load the model.  It's probably not TerraPage
        osg::Node *osg_model = osgDB::readNodeFile(name);
        if (!osg_model)
        {
            osg::notify(osg::WARN) << "TrPageArchive::LoadModels() error: "
                            << "failed to load model: "
                            << name << std::endl;
        }
        // Do this even if it's NULL
        _models[ix] = osg_model;
    }
/*
    else
    {
        trpgMemReadBuffer buf(GetEndian());
        mod->Read(buf);
        Group *osg_model = parse->ParseScene(buf, m_gstates , m_models);
        m_models.push_back(osg_model);  
    }
*/
    return true;
}

bool TXPArchive::loadModels()
{
    osg::notify(osg::NOTICE) << "txp:: Loading models ..." << std::endl;

    int numModel;
    modelTable.GetNumModels(numModel);
    _models.resize(numModel);

    // Iterate over the models
    for (int i=0; i< numModel; i++)
    {
        loadModel(i);
    }

    osg::notify(osg::NOTICE) << "txp:: ... done." << std::endl;
    return true;
}

bool TXPArchive::loadLightAttributes()
{
    osg::notify(osg::NOTICE) << "txp:: Loading light attributes ..." << std::endl;

    int num;
    lightTable.GetNumLightAttrs(num);
    for ( int attr_num = 0; attr_num < num; attr_num++    )
    {
        trpgLightAttr* ref = const_cast<trpgLightAttr*>(lightTable.GetLightAttrRef(attr_num));

        osgSim::LightPointNode* osgLight = new osgSim::LightPointNode();

        osg::Point* osgPoint = new osg::Point();

        osgSim::LightPoint lp ;
        lp._on = true;

        trpgColor col;
        ref->GetFrontColor(col);
        lp._color = osg::Vec4(col.red, col.green,col.blue, 1.0);

        float64 inten;
        ref->GetFrontIntensity(inten);
        lp._intensity = inten;

        trpgLightAttr::PerformerAttr perfAttr;
        ref->GetPerformerAttr(perfAttr);

        // point part
        //osgPoint->setSize(perfAttr.actualSize);
        osgPoint->setSize(5);
        osgPoint->setMaxSize(perfAttr.maxPixelSize);
        osgPoint->setMinSize(perfAttr.minPixelSize);    
        osgPoint->setFadeThresholdSize(perfAttr.transparentFallofExp);
        //numbers that are going to appear are "experimental"
        osgPoint->setDistanceAttenuation(osg::Vec3(0.0001, 0.0005, 0.00000025));
//        osgPoint->setDistanceAttenuation(osg::Vec3(1.0, 0.0, 1.0));

        osg::StateSet* stateSet = new osg::StateSet();
        stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
        stateSet->setMode(GL_POINT_SMOOTH, osg::StateAttribute::ON);
        stateSet->setAttributeAndModes(osgPoint, osg::StateAttribute::ON );
        stateSet->setAttributeAndModes(new osg::BlendFunc, osg::StateAttribute::ON);

        osgLight->setMaxPixelSize(perfAttr.maxPixelSize);
        osgLight->setMinPixelSize(perfAttr.minPixelSize);    

//        float64 clamp;
//        ref->GetPerformerTpClamp(clamp);
//        osgLight->setMaxVisibleDistance2(clamp);

        trpg3dPoint normal;
        ref->GetNormal(normal);

//        lp._radius = clamp;

        trpgLightAttr::LightDirectionality direc;
        ref->GetDirectionality(direc);
        if( direc == trpgLightAttr::trpg_Unidirectional)
        {
            osgSim::AzimElevationSector*  sec = new osgSim::AzimElevationSector();
            float64 tmp;
            ref->GetHLobeAngle(tmp);
            float64 tmpfade;
            ref->GetLobeFalloff(tmpfade);
            sec->setAzimuthRange(-tmp/2.0,tmp/2.0,tmpfade);

            ref->GetVLobeAngle(tmp);
            sec->setElevationRange(0,tmp, tmpfade);

            lp._sector = sec;
            osgLight->addLightPoint(lp);
        }
        else if( direc == trpgLightAttr::trpg_Bidirectional )
        {
            osgSim::AzimElevationSector*  front = new osgSim::AzimElevationSector();
            float64 tmp;
            ref->GetHLobeAngle(tmp);
            float64 tmpfade;
            ref->GetLobeFalloff(tmpfade);
            front->setAzimuthRange(-tmp/2.0,tmp/2.0,tmpfade);

            ref->GetVLobeAngle(tmp);
            front->setElevationRange(0,tmp, tmpfade);

            lp._sector = front;
            osgLight->addLightPoint(lp);

            osgSim::AzimElevationSector*  back = new osgSim::AzimElevationSector();
            back->setAzimuthRange(osg::PI-tmp/2.0,osg::PI+tmp/2.0,tmpfade);
            back->setElevationRange(0,tmp, tmpfade);
            lp._sector = back;
            osgLight->addLightPoint(lp);
        } 
        else{
            osgLight->addLightPoint(lp);
        }

        addLightAttribute(osgLight, stateSet, osg::Vec3(normal.x,normal.y,normal.z));
    }

    osg::notify(osg::NOTICE) << "txp:: ... done." << std::endl;
    return true;
}

void trim(std::string& str)
{
    while (!str.empty() && isspace(str[str.length()-1]))
        str.erase(str.length()-1);
    while (!str.empty() && isspace(str[0]))
        str.erase(0,1);
}
bool TXPArchive::loadTextStyles()
{
    const trpgTextStyleTable *textStyleTable = GetTextStyleTable();
    if (!textStyleTable) return false;
    if (textStyleTable->GetNumStyle() < 1) return true;

    // try fontmap.txt
    std::map< std::string, std::string > fontmap;

    std::string fmapfname = std::string(getDir())+"\\fontmap.txt";
    std::ifstream fmapfile;
    fmapfile.open(fmapfname.c_str(),std::ios::in);

    if (fmapfile.is_open())
    {
        osg::notify(osg::NOTICE) << "txp:: Font map file found: " << fmapfname << std::endl;
        std::string line;
        while (std::getline(fmapfile,line))
        {
            unsigned int ix = line.find_first_of('=');
            if (ix != std::string::npos)
            {
                std::string fontname = line.substr(0,ix);
                std::string fontfilename = line.substr(ix+1,line.length()-ix+1);

                trim(fontname);
                trim(fontfilename);

                fontmap[fontname] = fontfilename;

            }
        }
        fmapfile.close();
    }
    else
    {
        osg::notify(osg::NOTICE) << "txp:: No font map file found: " << fmapfname << std::endl;        
        osg::notify(osg::NOTICE) << "txp:: All fonts defaulted to arial.ttf" << std::endl;        
    }

    _fonts.resize(textStyleTable->GetNumStyle());
    _fcolors.resize(textStyleTable->GetNumStyle());
    for (int i = 0; i < textStyleTable->GetNumStyle(); i++)
    {
        const trpgTextStyle *textStyle = textStyleTable->GetStyleRef(i);
        if (!textStyle) continue;

        const std::string *fontName = textStyle->GetFont();
        if (!fontName) continue;

        std::string fontfilename = fontmap[*fontName];
        if (!fontfilename.length()) fontfilename = "arial.ttf";
        osg::ref_ptr< osgText::Font > font = osgText::readFontFile(fontfilename);

        _fonts[i] = font;

        const trpgMatTable* matTable = GetMaterialTable();
        if (matTable)
        {
            int matId = textStyle->GetMaterial();
            const trpgMaterial* mat = matTable->GetMaterialRef(0,matId);
            if (mat)
            {
                trpgColor faceColor;
                mat->GetColor(faceColor);

                float64 alpha;
                mat->GetAlpha(alpha);

                _fcolors[i] = osg::Vec4(faceColor.red, faceColor.green, faceColor.blue, alpha );
            }
        }
    }

    return true;
}

void TXPArchive::addLightAttribute(osgSim::LightPointNode* lpn, osg::StateSet* fallback, const osg::Vec3& att)
{
    DeferredLightAttribute la;
    la.lightPoint = lpn;
    la.fallback = fallback;
    la.attitude = att;
    _lights.push_back(la);
}

bool TXPArchive::getTileInfo(int x, int y, int lod, TileInfo& info)
{
    info.minRange = 0.0;
    info.maxRange = 0.0;
    info.radius = 0.f;
    info.center.set(0.f,0.f,0.f);
    info.bbox.set(0.f,0.f,0.f,0.f,0.f,0.f);

    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_mutex);

    header.GetLodRange(lod,info.maxRange);
    header.GetLodRange(lod+1,info.minRange);
    header.GetLodRange(0,info.lod0Range);

    trpg2dPoint sw,ne;
    header.GetExtents(sw,ne);

    trpg2dPoint size;
    header.GetTileSize(lod,size);

    info.size.x() = size.x;
    info.size.y() = size.y;
    info.size.z() = 0.f;

    trpgwAppAddress addr;
    float minz = 0.f;
    float maxz = 0.f;
    tileTable.GetTile(x,y,lod,addr,minz,maxz);

    info.center.set(
        sw.x+(x*size.x)+(size.x/2.f),
        sw.y+(y*size.y)+(size.y/2.f),
        (minz+maxz)/2.f
    );
    info.bbox.set(
        osg::Vec3(
            info.center.x()-(size.x/2.f),
            info.center.y()-(size.y/2.f),
            minz
        ),
        osg::Vec3(
            info.center.x()+(size.x/2.f),
            info.center.y()+(size.y/2.f),
            maxz
        )
    );
    info.radius = osg::Vec3(size.x/2.f, size.y/2.f,0.f).length() * 1.3;

    return true;
}

osg::Group* TXPArchive::getTileContent(
    int x, int y, int lod,
    double realMinRange, 
    double realMaxRange, 
    double usedMaxRange,
    osg::Vec3& tileCenter)
{
    if (_parser.get() == 0) 
    {
        _parser = new TXPParser();
        _parser->setArchive(this);
    }

    trpgMemReadBuffer buf(GetEndian());
    if (!ReadTile(x,y,lod,buf))
    {
        return new osg::Group;
    }

    osg::Group *tileGroup = _parser->parseScene(buf,_gstates,_models,realMinRange,realMaxRange,usedMaxRange);
    tileCenter = _parser->getTileCenter();

    // Prune
    unsigned int i = 0;
    for (i = 0; i < _gstates.size(); i++) 
    {
        if (_gstates[i].valid() && (_gstates[i]->referenceCount()==1)) _gstates[i] = 0;
    }

    for (i = 0; i < _textures.size(); i++) 
    {
        if (_textures[i].valid() && (_textures[i]->referenceCount()==1)) _textures[i] = 0;
    }

    return tileGroup;
}

bool TXPArchive::getLODSize(int lod, int& x, int& y)
{
    x = y = 0;

    OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_mutex);

    trpg2iPoint size;
    if (header.GetLodSize(lod,size))
    {
        x = size.x;
        y = size.y;
    }
    
    return true;
}
