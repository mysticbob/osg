// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/StaticMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/Camera>
#include <osg/GraphicsContext>
#include <osg/Object>
#include <osg/State>
#include <osg/Stats>
#include <osg/Timer>
#include <osgUtil/SceneView>
#include <osgViewer/Renderer>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::pair< GLuint COMMA  int >, osgViewer::OpenGLQuerySupport::QueryFrameNumberPair)

TYPE_NAME_ALIAS(std::list< osgViewer::OpenGLQuerySupport::QueryFrameNumberPair >, osgViewer::OpenGLQuerySupport::QueryFrameNumberList)

TYPE_NAME_ALIAS(std::vector< GLuint >, osgViewer::OpenGLQuerySupport::QueryList)

BEGIN_VALUE_REFLECTOR(osgViewer::OpenGLQuerySupport)
	I_DeclaringFile("osgViewer/Renderer");
	I_Constructor0(____OpenGLQuerySupport,
	               "",
	               "");
	I_Method1(void, setStartTick, IN, osg::Timer_t, startTick,
	          Properties::NON_VIRTUAL,
	          __void__setStartTick__osg_Timer_t,
	          "",
	          "");
	I_Method0(osg::Timer_t, getStartTick,
	          Properties::NON_VIRTUAL,
	          __osg_Timer_t__getStartTick,
	          "",
	          "");
	I_Method1(void, checkQuery, IN, osg::Stats *, stats,
	          Properties::NON_VIRTUAL,
	          __void__checkQuery__osg_Stats_P1,
	          "",
	          "");
	I_Method0(GLuint, createQueryObject,
	          Properties::NON_VIRTUAL,
	          __GLuint__createQueryObject,
	          "",
	          "");
	I_Method1(void, beginQuery, IN, int, frameNumber,
	          Properties::NON_VIRTUAL,
	          __void__beginQuery__int,
	          "",
	          "");
	I_Method0(void, endQuery,
	          Properties::NON_VIRTUAL,
	          __void__endQuery,
	          "",
	          "");
	I_Method1(void, initialize, IN, osg::State *, state,
	          Properties::NON_VIRTUAL,
	          __void__initialize__osg_State_P1,
	          "",
	          "");
	I_SimpleProperty(osg::Timer_t, StartTick, 
	                 __osg_Timer_t__getStartTick, 
	                 __void__setStartTick__osg_Timer_t);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgViewer::Renderer)
	I_DeclaringFile("osgViewer/Renderer");
	I_BaseType(osg::GraphicsOperation);
	I_BaseType(osgViewer::OpenGLQuerySupport);
	I_Constructor1(IN, osg::Camera *, camera,
	               Properties::NON_EXPLICIT,
	               ____Renderer__osg_Camera_P1,
	               "",
	               "");
	I_Method1(osgUtil::SceneView *, getSceneView, IN, unsigned int, i,
	          Properties::NON_VIRTUAL,
	          __osgUtil_SceneView_P1__getSceneView__unsigned_int,
	          "",
	          "");
	I_Method1(void, setDone, IN, bool, done,
	          Properties::NON_VIRTUAL,
	          __void__setDone__bool,
	          "",
	          "");
	I_Method0(bool, getDone,
	          Properties::NON_VIRTUAL,
	          __bool__getDone,
	          "",
	          "");
	I_Method1(void, setGraphicsThreadDoesCull, IN, bool, flag,
	          Properties::NON_VIRTUAL,
	          __void__setGraphicsThreadDoesCull__bool,
	          "",
	          "");
	I_Method0(bool, getGraphicsThreadDoesCull,
	          Properties::NON_VIRTUAL,
	          __bool__getGraphicsThreadDoesCull,
	          "",
	          "");
	I_Method0(void, cull,
	          Properties::NON_VIRTUAL,
	          __void__cull,
	          "",
	          "");
	I_Method0(void, draw,
	          Properties::NON_VIRTUAL,
	          __void__draw,
	          "",
	          "");
	I_Method0(void, cull_draw,
	          Properties::NON_VIRTUAL,
	          __void__cull_draw,
	          "",
	          "");
	I_Method0(void, release,
	          Properties::VIRTUAL,
	          __void__release,
	          "if this operation is a barrier then release it. ",
	          "");
	I_SimpleProperty(bool, Done, 
	                 __bool__getDone, 
	                 __void__setDone__bool);
	I_SimpleProperty(bool, GraphicsThreadDoesCull, 
	                 __bool__getGraphicsThreadDoesCull, 
	                 __void__setGraphicsThreadDoesCull__bool);
END_REFLECTOR

STD_LIST_REFLECTOR(std::list< osgViewer::OpenGLQuerySupport::QueryFrameNumberPair >)

STD_PAIR_REFLECTOR(std::pair< GLuint COMMA  int >)

