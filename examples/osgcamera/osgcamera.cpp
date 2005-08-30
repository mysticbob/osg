// C++ source file - (C) 2003 Robert Osfield, released under the OSGPL.
//
// Simple example of use of Producer::RenderSurface to create an OpenGL
// graphics window, and OSG for rendering.

#include <osg/Timer>
#include <osg/GraphicsContext>
#include <osg/GraphicsThread>

#include <osgUtil/UpdateVisitor>
#include <osgUtil/CullVisitor>
#include <osgUtil/SceneView>
#include <osgUtil/GLObjectsVisitor>

#include <osgDB/ReadFile>

#include <map>
#include <list>
#include <iostream>



////////////////////////////////////////////////////////////////////////////////
//
//
//  **************** THIS IS AN EXPERIMENTAL IMPLEMENTATION ***************
//  ************************** PLEASE DO NOT COPY  ************************
//
//
///////////////////////////////////////////////////////////////////////////////


struct CompileOperation : public osg::GraphicsThread::Operation
{
    CompileOperation(osg::Node* scene):
        osg::GraphicsThread::Operation("Compile",false),
        _scene(scene)
    {
    }
    
    virtual void operator () (osg::GraphicsContext* context)
    {
        std::cout<<"Compile"<<std::endl;
    
        osgUtil::GLObjectsVisitor compileVisitor;
        compileVisitor.setState(context->getState());

        // do the compile traversal
        _scene->accept(compileVisitor);
    }
    
    osg::ref_ptr<osg::Node> _scene;
};

struct FrameOperation : public osg::GraphicsThread::Operation
{
    FrameOperation(osg::CameraNode* camera, osg::FrameStamp* frameStamp):
        osg::GraphicsThread::Operation("Frame",true),
        _camera(camera),
        _frameStamp(frameStamp)
    {
        _sceneView = new osgUtil::SceneView;
        _sceneView->setDefaults();
        _sceneView->setFrameStamp(_frameStamp.get());
            
        if (camera->getNumChildren()>=1)
        {
            _sceneView->setSceneData(camera->getChild(0));
        }
    }
    
    virtual void operator () (osg::GraphicsContext* context)
    {
        _sceneView->setState(context->getState());
        _sceneView->setProjectionMatrix(_camera->getProjectionMatrix());
        _sceneView->setViewMatrix(_camera->getViewMatrix());
        _sceneView->setViewport(_camera->getViewport());
        
        _sceneView->cull();
        _sceneView->draw();
    }
    
    osg::ref_ptr<osg::CameraNode>    _camera;
    osg::ref_ptr<osg::FrameStamp>    _frameStamp;
    osg::ref_ptr<osgUtil::SceneView> _sceneView;
};

int main( int argc, char **argv )
{
    if (argc<2) 
    {
        std::cout << argv[0] <<": requires filename argument." << std::endl;
        return 1;
    }

    // load the scene.
    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(argv[1]);
    if (!loadedModel) 
    {
        std::cout << argv[0] <<": No data loaded." << std::endl;
        return 1;
    }

    
    // set up the frame stamp for current frame to record the current time and frame number so that animtion code can advance correctly
    osg::ref_ptr<osg::FrameStamp> frameStamp = new osg::FrameStamp;

    unsigned int frameNum = 0;

    osgUtil::UpdateVisitor updateVisitor;
    updateVisitor.setFrameStamp(frameStamp.get());


    unsigned int numberCameras = 3;
    unsigned int xpos = 0;
    unsigned int ypos = 400;
    unsigned int width = 400;
    unsigned int height = 400;
    
    typedef std::map< osg::ref_ptr<osg::CameraNode>, osg::ref_ptr<FrameOperation> > CameraMap;
    typedef std::set< osg::GraphicsContext* > GraphicsContextSet;

    CameraMap cameraMap;
    GraphicsContextSet graphicsContextSet;


    bool shareContexts = false;
    osg::GraphicsContext* previousContext = 0;
    for(unsigned int i=0; i< numberCameras; ++i)
    {
        osg::ref_ptr<osg::CameraNode> camera = new osg::CameraNode;
        camera->addChild(loadedModel.get());

        osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
        traits->_windowName = "osgcamera";
        traits->_x = xpos;
        traits->_y = ypos;
        traits->_width = width;
        traits->_height = height;
        traits->_windowDecoration = true;
        traits->_doubleBuffer = true;
        traits->_sharedContext = shareContexts ? previousContext : 0;
        
        xpos += width;

        osg::ref_ptr<osg::GraphicsContext> gfxc = osg::GraphicsContext::createGraphicsContext(traits.get());

        if (!gfxc)
        {
            std::cout<<"Unable to create window."<<std::endl;
            return 1;
        }

        camera->setGraphicsContext(gfxc.get());

        // initialize the view to look at the center of the scene graph
        const osg::BoundingSphere& bs = loadedModel->getBound();
        osg::Matrix viewMatrix;
        viewMatrix.makeLookAt(bs.center()-osg::Vec3(0.0,2.0f*bs.radius(),0.0),bs.center(),osg::Vec3(0.0f,0.0f,1.0f));

        camera->setViewport(0,0,traits->_width,traits->_height);
        camera->setProjectionMatrixAsPerspective(50.0f,1.4f,1.0f,10000.0f);
        camera->setViewMatrix(viewMatrix);

        // graphics thread will realize the window.
        gfxc->createGraphicsThread();

        cameraMap[camera] = new FrameOperation(camera.get(), frameStamp.get());

        previousContext = gfxc.get();
    }


    CameraMap::iterator citr;
    for(citr = cameraMap.begin();
        citr != cameraMap.end();
        ++citr)
    {
        graphicsContextSet.insert(const_cast<osg::GraphicsContext*>(citr->first->getGraphicsContext()));
    }

    osg::ref_ptr<CompileOperation> compileOp = new CompileOperation(loadedModel.get());

    osg::ref_ptr<osg::BarrierOperation> frameBeginBarrierOp = new osg::BarrierOperation(graphicsContextSet.size()+1, osg::BarrierOperation::NO_OPERATION);
    osg::ref_ptr<osg::BarrierOperation> frameEndBarrierOp = new osg::BarrierOperation(graphicsContextSet.size()+1, osg::BarrierOperation::NO_OPERATION);
    osg::ref_ptr<osg::BarrierOperation> preSwapBarrierOp = new osg::BarrierOperation(graphicsContextSet.size(), osg::BarrierOperation::GL_FLUSH);
    osg::ref_ptr<osg::SwapBuffersOperation> swapOp = new osg::SwapBuffersOperation();

    std::cout<<"nubmer of gfx."<<graphicsContextSet.size()<<std::endl;

    // record the timer tick at the start of rendering.    
    osg::Timer_t start_tick = osg::Timer::instance()->tick();
    osg::Timer_t previous_tick = start_tick;
    
    bool done = false;    

    // first the compile of the GL Objects, do it syncronously.
    GraphicsContextSet::iterator gitr;
    for(gitr = graphicsContextSet.begin();
        gitr != graphicsContextSet.end();
        ++gitr)
    {
        osg::GraphicsContext* context = *gitr;
        context->getGraphicsThread()->add(compileOp.get(), true);
    }


    // second the begin frame barrier to all graphics threads
    for(gitr = graphicsContextSet.begin();
        gitr != graphicsContextSet.end();
        ++gitr)
    {
        osg::GraphicsContext* context = *gitr;
        context->getGraphicsThread()->add(frameBeginBarrierOp.get(), false);
    }

    // third add the frame for each camera.
    for(citr = cameraMap.begin();
        citr != cameraMap.end();
        ++citr)
    {
        osg::CameraNode* camera = const_cast<osg::CameraNode*>(citr->first.get());
        camera->getGraphicsContext()->getGraphicsThread()->add( citr->second.get(), false); 
    }

    // fourth add the frame end barrier, the pre swap barrier and finally the swap buffers to each graphics thread
    for(gitr = graphicsContextSet.begin();
        gitr != graphicsContextSet.end();
        ++gitr)
    {
        osg::GraphicsContext* context = *gitr;
        context->getGraphicsThread()->add(frameEndBarrierOp.get(), false);
        context->getGraphicsThread()->add(preSwapBarrierOp.get(), false);
        context->getGraphicsThread()->add(swapOp.get(), false);
    }

    // main loop -  update scene graph, dispatch frame, wait for frame done.
    while( !done )
    {

        osg::Timer_t current_tick = osg::Timer::instance()->tick();

        frameStamp->setReferenceTime(osg::Timer::instance()->delta_s(start_tick,current_tick));
        frameStamp->setFrameNumber(frameNum++);
        
        std::cout<<"Frame rate "<<1.0/osg::Timer::instance()->delta_s(previous_tick,current_tick)<<std::endl;
        previous_tick = current_tick;


        // do the update traversal.
        loadedModel->accept(updateVisitor);

        // dispatch the frame.
        frameBeginBarrierOp->block();
        
        // wait till the frame is done.
        frameEndBarrierOp->block();

        // check if any of the windows are closed
        for(gitr = graphicsContextSet.begin();
            gitr != graphicsContextSet.end();
            ++gitr)
        {
            osg::GraphicsContext* context = *gitr;
            if (!context->isRealized()) done = true;
        }

    }
    return 0;
}
