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
#include <osg/Vec3>
#include <osgUtil/HalfWayMapGenerator>

BEGIN_OBJECT_REFLECTOR(osgUtil::HalfWayMapGenerator)
	BaseType(osgUtil::CubeMapGenerator);
	ConstructorWithDefaults2(IN, const osg::Vec3 &, light_direction, , IN, int, texture_size, 64);
	Constructor2(IN, const osgUtil::HalfWayMapGenerator &, copy, IN, const osg::CopyOp &, copyop);
END_REFLECTOR

