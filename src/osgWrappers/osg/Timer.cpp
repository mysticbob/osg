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

#include <osg/Timer>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_VALUE_REFLECTOR(osg::Timer)
	I_DeclaringFile("osg/Timer");
	I_Constructor0(____Timer,
	               "",
	               "");
	I_Method0(osg::Timer_t, tick,
	          Properties::NON_VIRTUAL,
	          __Timer_t__tick,
	          "Get the timers tick value. ",
	          "");
	I_Method0(void, setStartTick,
	          Properties::NON_VIRTUAL,
	          __void__setStartTick,
	          "Set the start. ",
	          "");
	I_Method1(void, setStartTick, IN, osg::Timer_t, t,
	          Properties::NON_VIRTUAL,
	          __void__setStartTick__Timer_t,
	          "",
	          "");
	I_Method0(osg::Timer_t, getStartTick,
	          Properties::NON_VIRTUAL,
	          __Timer_t__getStartTick,
	          "",
	          "");
	I_Method0(double, time_s,
	          Properties::NON_VIRTUAL,
	          __double__time_s,
	          "Get elapsed time in seconds. ",
	          "");
	I_Method0(double, time_m,
	          Properties::NON_VIRTUAL,
	          __double__time_m,
	          "Get elapsed time in milliseconds. ",
	          "");
	I_Method0(double, time_u,
	          Properties::NON_VIRTUAL,
	          __double__time_u,
	          "Get elapsed time in micoseconds. ",
	          "");
	I_Method0(double, time_n,
	          Properties::NON_VIRTUAL,
	          __double__time_n,
	          "Get elapsed time in nanoseconds. ",
	          "");
	I_Method2(double, delta_s, IN, osg::Timer_t, t1, IN, osg::Timer_t, t2,
	          Properties::NON_VIRTUAL,
	          __double__delta_s__Timer_t__Timer_t,
	          "Get the time in seconds between timer ticks t1 and t2. ",
	          "");
	I_Method2(double, delta_m, IN, osg::Timer_t, t1, IN, osg::Timer_t, t2,
	          Properties::NON_VIRTUAL,
	          __double__delta_m__Timer_t__Timer_t,
	          "Get the time in milliseconds between timer ticks t1 and t2. ",
	          "");
	I_Method2(double, delta_u, IN, osg::Timer_t, t1, IN, osg::Timer_t, t2,
	          Properties::NON_VIRTUAL,
	          __double__delta_u__Timer_t__Timer_t,
	          "Get the time in microseconds between timer ticks t1 and t2. ",
	          "");
	I_Method2(double, delta_n, IN, osg::Timer_t, t1, IN, osg::Timer_t, t2,
	          Properties::NON_VIRTUAL,
	          __double__delta_n__Timer_t__Timer_t,
	          "Get the time in nanoseconds between timer ticks t1 and t2. ",
	          "");
	I_Method0(double, getSecondsPerTick,
	          Properties::NON_VIRTUAL,
	          __double__getSecondsPerTick,
	          "Get the the number of seconds per tick. ",
	          "");
	I_StaticMethod0(osg::Timer *, instance,
	                __Timer_P1__instance_S,
	                "",
	                "");
	I_SimpleProperty(double, SecondsPerTick, 
	                 __double__getSecondsPerTick, 
	                 0);
	I_SimpleProperty(osg::Timer_t, StartTick, 
	                 __Timer_t__getStartTick, 
	                 __void__setStartTick__Timer_t);
END_REFLECTOR

TYPE_NAME_ALIAS(unsigned long long, osg::Timer_t)

