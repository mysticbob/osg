// ***************************************************************************
//
//   Generated automatically by genwrapper.
//   Please DO NOT EDIT this file!
//
// ***************************************************************************

#include <osgIntrospection/ReflectionMacros>
#include <osgIntrospection/TypedMethodInfo>
#include <osgIntrospection/Attributes>

#include <osg/CopyOp>
#include <osg/Object>
#include <osg/Vec3>
#include <osgParticle/Particle>
#include <osgParticle/Placer>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ABSTRACT_OBJECT_REFLECTOR(osgParticle::Placer)
	I_BaseType(osg::Object);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, const osgParticle::Placer &, copy, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(const char *, libraryName);
	I_Method0(const char *, className);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method1(void, place, IN, osgParticle::Particle *, P);
	I_Method0(osg::Vec3, getControlPosition);
	I_ReadOnlyProperty(osg::Vec3, ControlPosition);
END_REFLECTOR

