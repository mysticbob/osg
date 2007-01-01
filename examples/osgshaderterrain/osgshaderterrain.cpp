#include <osg/AlphaFunc>
#include <osg/Billboard>
#include <osg/BlendFunc>
#include <osg/Depth>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/GL2Extensions>
#include <osg/Material>
#include <osg/Math>
#include <osg/MatrixTransform>
#include <osg/PolygonOffset>
#include <osg/Program>
#include <osg/Projection>
#include <osg/Shader>
#include <osg/ShapeDrawable>
#include <osg/StateSet>
#include <osg/Switch>
#include <osg/Texture2D>
#include <osg/Uniform>

#include <osgDB/ReadFile>
#include <osgDB/FileUtils>

#include <osgUtil/IntersectVisitor>
#include <osgUtil/SmoothingVisitor>

#include <osgText/Text>

#include <osgProducer/Viewer>

// for the grid data..
#include "../osghangglide/terrain_coords.h"

osg::Node* createScene()
{
    osg::Group* scene = new osg::Group;
    
    unsigned int numColumns = 38;
    unsigned int numRows = 39;
    unsigned int r;
    unsigned int c;

    osg::Vec3 origin(0.0f,0.0f,0.0f);
    osg::Vec3 size(1000.0f,1000.0f,250.0f);
    osg::Vec3 scaleDown(1.0f/size.x(),1.0f/size.y(),1.0f/size.z());

    // ---------------------------------------
    // Set up a StateSet to texture the objects
    // ---------------------------------------
    osg::StateSet* stateset = new osg::StateSet();


    osg::Uniform* originUniform = new osg::Uniform("terrainOrigin",origin);
    stateset->addUniform(originUniform);

    osg::Uniform* sizeUniform = new osg::Uniform("terrainSize",size);
    stateset->addUniform(sizeUniform);

    osg::Uniform* scaleDownUniform = new osg::Uniform("terrainScaleDown",scaleDown);
    stateset->addUniform(scaleDownUniform);

    osg::Uniform* terrainTextureSampler = new osg::Uniform("terrainTexture",0);
    stateset->addUniform(terrainTextureSampler);

    osg::Uniform* baseTextureSampler = new osg::Uniform("baseTexture",1);
    stateset->addUniform(baseTextureSampler);

    osg::Uniform* treeTextureSampler = new osg::Uniform("treeTexture",1);
    stateset->addUniform(treeTextureSampler);


    // compute z range of z values of grid data so we can scale it.
    float min_z = FLT_MAX;
    float max_z = -FLT_MAX;
    for(r=0;r<numRows;++r)
    {
        for(c=0;c<numColumns;++c)
        {
            min_z = osg::minimum(min_z,vertex[r+c*numRows][2]);
            max_z = osg::maximum(max_z,vertex[r+c*numRows][2]);
        }
    }
        
    float scale_z = size.z()/(max_z-min_z);

    osg::Image* terrainImage = new osg::Image;
    terrainImage->allocateImage(numColumns,numRows,1,GL_LUMINANCE, GL_FLOAT);
    terrainImage->setInternalTextureFormat(GL_LUMINANCE_FLOAT32_ATI);
    for(r=0;r<numRows;++r)
    {
        for(c=0;c<numColumns;++c)
        {
            *((float*)(terrainImage->data(c,r))) = (vertex[r+c*numRows][2]-min_z)*scale_z;
        }
    }
    
    osg::Texture2D* terrainTexture = new osg::Texture2D;
    terrainTexture->setImage(terrainImage);
    terrainTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::NEAREST);
    terrainTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::NEAREST);
    terrainTexture->setResizeNonPowerOfTwoHint(false);
    stateset->setTextureAttributeAndModes(0,terrainTexture,osg::StateAttribute::ON);


    osg::Image* image = osgDB::readImageFile("Images/lz.rgb");
    if (image)
    {
        osg::Texture2D* texture = new osg::Texture2D;
        
        texture->setImage(image);
        stateset->setTextureAttributeAndModes(1,texture,osg::StateAttribute::ON);
    }

    {    
        std::cout<<"Creating terrain...";

        osg::Geode* geode = new osg::Geode();
        geode->setStateSet( stateset );


        {
            osg::Program* program = new osg::Program;
            stateset->setAttribute(program);

#if 0
            // use inline shaders
            
            ///////////////////////////////////////////////////////////////////
            // vertex shader using just Vec4 coefficients
            char vertexShaderSource[] = 
               "uniform float osg_FrameTime;\n"
               "uniform sampler2D terrainTexture;\n"
               "uniform vec3 terrainOrigin;\n"
               "uniform vec3 terrainScaleDown;\n"
               "\n"
               "varying vec2 texcoord;\n"
               "\n"
               "void main(void)\n"
               "{\n"
               "    texcoord = gl_Vertex.xy - terrainOrigin.xy;\n"
               "    texcoord.x *= terrainScaleDown.x;\n"
               "    texcoord.y *= terrainScaleDown.y;\n"
               "\n"
               "    vec4 position;\n"ttm->
               "    position.x = gl_Vertex.x;\n"
               "    position.y = gl_Vertex.y;\n"
               "    position.z = texture2D(terrainTexture, texcoord).r;\n"
               "    position.w = 1.0;\n"
               " \n"
               "    gl_Position     = gl_ModelViewProjectionMatrix * position;\n"
                "   gl_FrontColor = vec4(1.0,1.0,1.0,1.0);\n"
               "}\n";

            //////////////////////////////////////////////////////////////////
            // fragment shader
            //
            char fragmentShaderSource[] = 
                "uniform sampler2D baseTexture; \n"
                "varying vec2 texcoord;\n"
                "\n"
                "void main(void) \n"
                "{\n"
                "    gl_FragColor = texture2D( baseTexture, texcoord); \n"
                "}\n";

            program->addShader(new osg::Shader(osg::Shader::VERTEX, vertexShaderSource));
            program->addShader(new osg::Shader(osg::Shader::FRAGMENT, fragmentShaderSource));
            
#else

            // get shaders from source
            program->addShader(osg::Shader::readShaderFile(osg::Shader::VERTEX, osgDB::findDataFile("shaders/terrain.vert")));
            program->addShader(osg::Shader::readShaderFile(osg::Shader::FRAGMENT, osgDB::findDataFile("shaders/terrain.frag")));

#endif

            // get shaders from source
        }


        {
            osg::Geometry* geometry = new osg::Geometry;

            osg::Vec3Array& v = *(new osg::Vec3Array(numColumns*numRows));
            osg::Vec4ubArray& color = *(new osg::Vec4ubArray(1));

            color[0].set(255,255,255,255);

            float rowCoordDelta = size.y()/(float)(numRows-1);
            float columnCoordDelta = size.x()/(float)(numColumns-1);

            float rowTexDelta = 1.0f/(float)(numRows-1);
            float columnTexDelta = 1.0f/(float)(numColumns-1);

            osg::Vec3 pos = origin;
            osg::Vec2 tex(0.0f,0.0f);
            int vi=0;
            for(r=0;r<numRows;++r)
            {
                pos.x() = origin.x();
                tex.x() = 0.0f;
                for(c=0;c<numColumns;++c)
                {
                    v[vi].set(pos.x(),pos.y(),pos.z());
                    pos.x()+=columnCoordDelta;
                    tex.x()+=columnTexDelta;
                    ++vi;
                }
                pos.y() += rowCoordDelta;
                tex.y() += rowTexDelta;
            }

            geometry->setVertexArray(&v);
            geometry->setColorArray(&color);
            geometry->setColorBinding(osg::Geometry::BIND_OVERALL);

            for(r=0;r<numRows-1;++r)
            {
                osg::DrawElementsUShort& drawElements = *(new osg::DrawElementsUShort(GL_QUAD_STRIP,2*numColumns));
                geometry->addPrimitiveSet(&drawElements);
                int ei=0;
                for(c=0;c<numColumns;++c)
                {
                    drawElements[ei++] = (r+1)*numColumns+c;
                    drawElements[ei++] = (r)*numColumns+c;
                }
            }
            
            geometry->setInitialBound(osg::BoundingBox(origin, origin+size));

            geode->addDrawable(geometry);

            scene->addChild(geode);
        }
    }
        
    std::cout<<"done."<<std::endl;
    
    return scene;
}

class TestSupportCallback : public osgProducer::OsgCameraGroup::RealizeCallback
{
    public:
        TestSupportCallback():_supported(true),_errorMessage() {}
        
        virtual void operator()( osgProducer::OsgCameraGroup&, osgProducer::OsgSceneHandler& sh, const Producer::RenderSurface& )
        {
            {
                OpenThreads::ScopedLock<OpenThreads::Mutex> lock(_mutex);

                unsigned int contextID = sh.getSceneView()->getState()->getContextID();
                osg::GL2Extensions* gl2ext = osg::GL2Extensions::Get(contextID,true);
                if( gl2ext )
                {
                    if( !gl2ext->isGlslSupported() )
                    {
                        _supported = false;
                        _errorMessage = "ERROR: GLSL not supported by OpenGL driver.";
                    }

                    GLint numVertexTexUnits = 0;
                    glGetIntegerv( GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &numVertexTexUnits );
                    if( numVertexTexUnits <= 0 )
                    {
                        _supported = false;
                        _errorMessage = "ERROR: vertex texturing not supported by OpenGL driver.";
                    }
                }
            }
                        
            sh.init();
        }
        
        OpenThreads::Mutex  _mutex;
        bool                _supported;
        std::string         _errorMessage;
        
};

int main( int argc, char **argv )
{

    // use an ArgumentParser object to manage the program arguments.
    osg::ArgumentParser arguments(&argc,argv);

    // set up the usage document, in case we need to print out how to use this program.
    arguments.getApplicationUsage()->setDescription(arguments.getApplicationName()+" is the example which demonstrates the osg::Shape classes.");
    arguments.getApplicationUsage()->setCommandLineUsage(arguments.getApplicationName()+" [options] filename ...");
    arguments.getApplicationUsage()->addCommandLineOption("-h or --help","Display this information");
    arguments.getApplicationUsage()->addCommandLineOption("--trees <number>","Set the number of trees to create");
   
    // construct the viewer.
    osgProducer::Viewer viewer(arguments);

    // set up the value with sensible default event handlers.
    viewer.setUpViewer(osgProducer::Viewer::STANDARD_SETTINGS);
    
    // get details on keyboard and mouse bindings used by the viewer.
    viewer.getUsage(*arguments.getApplicationUsage());

    // if user request help write it out to cout.
    if (arguments.read("-h") || arguments.read("--help"))
    {
        arguments.getApplicationUsage()->write(std::cout);
        return 1;
    }

    // any option left unread are converted into errors to write out later.
    arguments.reportRemainingOptionsAsUnrecognized();

    // report any errors if they have occured when parsing the program aguments.
    if (arguments.errors())
    {
        arguments.writeErrorMessages(std::cout);
        return 1;
    }
    
    osg::Node* node = createScene();

    // add model to viewer.
    viewer.setSceneData( node );

    // register a test extension callback to be called when app realizes and gets a valid graphics context
    osg::ref_ptr<TestSupportCallback> testSupportCallback = new TestSupportCallback();
    viewer.setRealizeCallback(testSupportCallback.get());

    // create the windows and run the threads.
    viewer.realize();

    // exit if we don't have the extensions this example needs.
    if (!testSupportCallback->_supported)
    {
        osg::notify(osg::WARN)<<testSupportCallback->_errorMessage<<std::endl;

        exit(1);
    }

    while( !viewer.done() )
    {
        // wait for all cull and draw threads to complete.
        viewer.sync();

        // update the scene by traversing it with the the update visitor which will
        // call all node update callbacks and animations.
        viewer.update();
         
        // fire off the cull and draw traversals of the scene.
        viewer.frame();
        
    }
    
    // wait for all cull and draw threads to complete.
    viewer.sync();

    // run a clean up frame to delete all OpenGL objects.
    viewer.cleanup_frame();

    // wait for all the clean up frame to complete.
    viewer.sync();

    return 0;
}
