#include <osgProducer/KeyboardMouseCallback>

#ifdef WIN32
    #include <windows.h>
#else
    #include <X11/keysym.h>
#endif


using namespace osgProducer;

void KeyboardMouseCallback::keyPress( Producer::KeySymbol key )
{

           
    osg::ref_ptr<EventAdapter> event = new EventAdapter;
    event->adaptKeyPress(getTime(),key);

    // check against adapted key symbol.    
    if (_escapeKeySetsDone && 
        event->getKey()==osgGA::GUIEventAdapter::KEY_Escape) _done = true;

    _eventQueueMutex.lock();
    _eventQueue.push_back(event);
    _eventQueueMutex.unlock();
}

void KeyboardMouseCallback::keyRelease( Producer::KeySymbol key )
{

    osg::ref_ptr<EventAdapter> event = new EventAdapter;
    event->adaptKeyRelease(getTime(),key);
    
    _eventQueueMutex.lock();
    _eventQueue.push_back(event);
    _eventQueueMutex.unlock();
}

void KeyboardMouseCallback::mouseMotion( float mx, float my) 
{
    _mx = mx;
    _my = my;
    
    osg::ref_ptr<EventAdapter> event = new EventAdapter;
    event->adaptMouseMotion(getTime(),mx,my);
    
    _eventQueueMutex.lock();
    _eventQueue.push_back(event);
    _eventQueueMutex.unlock();

}

void KeyboardMouseCallback::passiveMouseMotion( float mx, float my) 
{
    _mx = mx;
    _my = my;
    
    osg::ref_ptr<EventAdapter> event = new EventAdapter;
    event->adaptMouseMotion(getTime(),mx,my);
    
    _eventQueueMutex.lock();
    _eventQueue.push_back(event);
    _eventQueueMutex.unlock();

}

void KeyboardMouseCallback::buttonPress( float mx, float my, unsigned int mbutton ) 
{
    _mx = mx;
    _my = my;
    _mbutton |= (1<<(mbutton-1));
    
    
    osg::ref_ptr<EventAdapter> event = new EventAdapter;
    event->adaptButtonPress(getTime(),mx,my,mbutton);
    
    _eventQueueMutex.lock();
    _eventQueue.push_back(event);
    _eventQueueMutex.unlock();
}

void KeyboardMouseCallback::buttonRelease( float mx, float my, unsigned int mbutton ) 
{
    _mx = mx;
    _my = my;
    _mbutton &= ~(1<<(mbutton-1));
    
    
    osg::ref_ptr<EventAdapter> event = new EventAdapter;
    event->adaptButtonRelease(getTime(),mx,my,mbutton);
    
    _eventQueueMutex.lock();
    _eventQueue.push_back(event);
    _eventQueueMutex.unlock();
}

void KeyboardMouseCallback::getEventQueue(EventQueue& queue)
{
    queue.clear();
    _eventQueueMutex.lock();
    _eventQueue.swap(queue);
    _eventQueueMutex.unlock();
    
}
