#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Material>
#include <osg/Vec3>
#include <osg/MatrixTransform>

#include <osgGA/TrackballManipulator>

#include <osgGLUT/Viewer>
#include <osgGLUT/glut>

#include <osg/Math>

// ----------------------------------------------------------------------
// Global variables - this is basically the stuff wh    ich will be animated
// ----------------------------------------------------------------------


class MyTransformCallback : public osg::NodeCallback{

    public:

        MyTransformCallback(osg::MatrixTransform* node,float angularVelocity)
        {
            _nodeToOperateOn = node;
            _angular_velocity = angularVelocity;
            _previousTraversalNumber = -1;
            _orig_t = _timer.tick();
        }

        virtual void operator() (osg::Node* node, osg::NodeVisitor* nv)
        {
            if (nv)
            {
                if (_nodeToOperateOn && node==_nodeToOperateOn)
                {
                    // ensure that we do not operate on this node more than
                    // once during this traversal.  This is an issue since node
                    // can be shared between multiple parents.
                    if (nv->getTraversalNumber()!=_previousTraversalNumber)
                    {
                        osg::Timer_t new_t = _timer.tick();
                        float delta_angle = _angular_velocity*_timer.delta_s(_orig_t,new_t);
                        
                        osg::Matrix matrix;
                        matrix.makeRotate(delta_angle,1.0f,1.0f,1.0f);
                        matrix *= osg::Matrix::translate(1.0f,0.0f,0.0f);
                        matrix *= osg::Matrix::rotate(delta_angle,0.0f,0.0f,1.0f);
                                                
                        _nodeToOperateOn->setMatrix(matrix);

                        _previousTraversalNumber = nv->getTraversalNumber();

                    }
                }
            }
            
            // must continue subgraph traversal.
            traverse(node,nv);            
            
        }
        
    protected:
    
        osg::MatrixTransform*     _nodeToOperateOn;
        float               _angular_velocity;

        int                 _previousTraversalNumber;
        osg::Timer          _timer;
        osg::Timer_t        _orig_t;

};

osg::Geode* createGeometryCube()
{
    osg::Geode* geode = osgNew osg::Geode();

    // -------------------------------------------
    // Set up a new Geometry which will be our cube
    // -------------------------------------------
    osg::Geometry* cube = osgNew osg::Geometry();

    // set up the primitives
    
    cube->addPrimitiveSet(osgNew osg::DrawArrays(osg::PrimitiveSet::POLYGON,0,4));
    cube->addPrimitiveSet(osgNew osg::DrawArrays(osg::PrimitiveSet::POLYGON,4,4));
    cube->addPrimitiveSet(osgNew osg::DrawArrays(osg::PrimitiveSet::POLYGON,8,4));
    cube->addPrimitiveSet(osgNew osg::DrawArrays(osg::PrimitiveSet::POLYGON,12,4));
    cube->addPrimitiveSet(osgNew osg::DrawArrays(osg::PrimitiveSet::POLYGON,16,4));
    cube->addPrimitiveSet(osgNew osg::DrawArrays(osg::PrimitiveSet::POLYGON,20,4));
    

    // set up coords.
    osg::Vec3Array* coords = osgNew osg::Vec3Array;
    coords->resize(24);
    
    (*coords)[0].set( -1.0000f,   1.0000f,  -1.000f );
    (*coords)[1].set( 1.0000f,   1.0000f,  -1.0000f );
    (*coords)[2].set( 1.0000f,  -1.0000f,  -1.0000f );
    (*coords)[3].set( -1.0000f,  -1.0000f,  -1.000 );

    (*coords)[4].set( 1.0000f,   1.0000f,  -1.0000f );
    (*coords)[5].set( 1.0000f,   1.0000f,   1.0000f );
    (*coords)[6].set( 1.0000f,  -1.0000f,   1.0000f );
    (*coords)[7].set( 1.0000f,  -1.0000f,  -1.0000f );

    (*coords)[8].set( 1.0000f,   1.0000f,   1.0000f );
    (*coords)[9].set( -1.0000f,   1.0000f,   1.000f );
    (*coords)[10].set( -1.0000f,  -1.0000f,   1.000f );
    (*coords)[11].set( 1.0000f,  -1.0000f,   1.0000f );

    (*coords)[12].set( -1.0000f,   1.0000f,   1.000 );
    (*coords)[13].set( -1.0000f,   1.0000f,  -1.000 );
    (*coords)[14].set( -1.0000f,  -1.0000f,  -1.000 );
    (*coords)[15].set( -1.0000f,  -1.0000f,   1.000 );

    (*coords)[16].set( -1.0000f,   1.0000f,   1.000 );
    (*coords)[17].set( 1.0000f,   1.0000f,   1.0000f );
    (*coords)[18].set( 1.0000f,   1.0000f,  -1.0000f );
    (*coords)[19].set( -1.0000f,   1.0000f,  -1.000f );

    (*coords)[20].set( -1.0000f,  -1.0000f,   1.000f );
    (*coords)[21].set( -1.0000f,  -1.0000f,  -1.000f );
    (*coords)[22].set( 1.0000f,  -1.0000f,  -1.0000f );
    (*coords)[23].set( 1.0000f,  -1.0000f,   1.0000f );


    cube->setVertexArray( coords );
    
    
    // set up the normals.
    osg::Vec3Array* cubeNormals = osgNew osg::Vec3Array;
    cubeNormals->resize(6);
    
    (*cubeNormals)[0].set(0.0f,0.0f,-1.0f);
    (*cubeNormals)[1].set(1.0f,0.0f,0.0f);
    (*cubeNormals)[2].set(0.0f,0.0f,1.0f);
    (*cubeNormals)[3].set(-1.0f,0.0f,0.0f);
    (*cubeNormals)[4].set(0.0f,1.0f,0.0f);
    (*cubeNormals)[5].set(0.0f,-1.0f,0.0f);
    
    cube->setNormalArray( cubeNormals );    
    cube->setNormalBinding( osg::Geometry::BIND_PER_PRIMITIVE );

    // ---------------------------------------
    // Set up a StateSet to make the cube red
    // ---------------------------------------
    osg::StateSet* cubeState = osgNew osg::StateSet();
    osg::Material* redMaterial = osgNew osg::Material();
    osg::Vec4 red( 1.0f, 0.0f, 0.0f, 1.0f );
    redMaterial->setDiffuse( osg::Material::FRONT_AND_BACK, red );
    cubeState->setAttribute( redMaterial );

    cube->setStateSet( cubeState );

    geode->addDrawable( cube );
    
    return geode;
}

int main( int argc, char **argv )
{

    glutInit( &argc, argv );

    // create the commandline args.
    std::vector<std::string> commandLine;
    for(int i=1;i<argc;++i) commandLine.push_back(argv[i]);

    // create the viewer and the model to it.
    osgGLUT::Viewer viewer;

    viewer.setWindowTitle(argv[0]);

 
    // configure the viewer from the commandline arguments, and eat any
    // parameters that have been matched.
    viewer.readCommandLine(commandLine);
    
    osg::MatrixTransform* myTransform = osgNew osg::MatrixTransform();
    myTransform->addChild( createGeometryCube() );

    // move node in a circle at 90 degrees a sec.
    myTransform->setAppCallback(osgNew MyTransformCallback(myTransform,osg::inDegrees(90.0f)));

    // add model to viewer.
    viewer.addViewport( myTransform );

    // register trackball maniupulators.
    viewer.registerCameraManipulator(osgNew osgGA::TrackballManipulator);
    
    viewer.open();

    viewer.run();

    return 0;
}
