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

#include <osg/Object>
#include <osgDB/Options>
#include <osgDB/Output>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_ENUM_REFLECTOR(osgDB::Output::PathNameHint)
	I_DeclaringFile("osgDB/Output");
	I_EnumLabel(osgDB::Output::AS_IS);
	I_EnumLabel(osgDB::Output::FULL_PATH);
	I_EnumLabel(osgDB::Output::RELATIVE_PATH);
	I_EnumLabel(osgDB::Output::FILENAME_ONLY);
END_REFLECTOR

