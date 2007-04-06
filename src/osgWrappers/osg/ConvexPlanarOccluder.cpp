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

#include <osg/ConvexPlanarOccluder>
#include <osg/ConvexPlanarPolygon>
#include <osg/CopyOp>
#include <osg/Object>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< osg::ConvexPlanarPolygon >, osg::ConvexPlanarOccluder::HoleList)

BEGIN_OBJECT_REFLECTOR(osg::ConvexPlanarOccluder)
	I_BaseType(osg::Object);
	I_Constructor0(____ConvexPlanarOccluder,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osg::ConvexPlanarOccluder &, cpo, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____ConvexPlanarOccluder__C5_ConvexPlanarOccluder_R1__C5_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __osg_Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __osg_Object_P1__clone__C5_osg_CopyOp_R1,
	          "Clone an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj,
	          Properties::VIRTUAL,
	          __bool__isSameKindAs__C5_osg_Object_P1,
	          "",
	          "");
	I_Method0(const char *, libraryName,
	          Properties::VIRTUAL,
	          __C5_char_P1__libraryName,
	          "return the name of the object's library. ",
	          "Must be defined by derived classes. The OpenSceneGraph convention is that the namespace of a library is the same as the library name. ");
	I_Method0(const char *, className,
	          Properties::VIRTUAL,
	          __C5_char_P1__className,
	          "return the name of the object's class type. ",
	          "Must be defined by derived classes. ");
	I_Method1(void, setOccluder, IN, const osg::ConvexPlanarPolygon &, cpp,
	          Properties::NON_VIRTUAL,
	          __void__setOccluder__C5_ConvexPlanarPolygon_R1,
	          "",
	          "");
	I_Method0(osg::ConvexPlanarPolygon &, getOccluder,
	          Properties::NON_VIRTUAL,
	          __ConvexPlanarPolygon_R1__getOccluder,
	          "",
	          "");
	I_Method0(const osg::ConvexPlanarPolygon &, getOccluder,
	          Properties::NON_VIRTUAL,
	          __C5_ConvexPlanarPolygon_R1__getOccluder,
	          "",
	          "");
	I_Method1(void, addHole, IN, const osg::ConvexPlanarPolygon &, cpp,
	          Properties::NON_VIRTUAL,
	          __void__addHole__C5_ConvexPlanarPolygon_R1,
	          "",
	          "");
	I_Method1(void, setHoleList, IN, const osg::ConvexPlanarOccluder::HoleList &, holeList,
	          Properties::NON_VIRTUAL,
	          __void__setHoleList__C5_HoleList_R1,
	          "",
	          "");
	I_Method0(osg::ConvexPlanarOccluder::HoleList &, getHoleList,
	          Properties::NON_VIRTUAL,
	          __HoleList_R1__getHoleList,
	          "",
	          "");
	I_Method0(const osg::ConvexPlanarOccluder::HoleList &, getHoleList,
	          Properties::NON_VIRTUAL,
	          __C5_HoleList_R1__getHoleList,
	          "",
	          "");
	I_SimpleProperty(const osg::ConvexPlanarOccluder::HoleList &, HoleList, 
	                 __C5_HoleList_R1__getHoleList, 
	                 __void__setHoleList__C5_HoleList_R1);
	I_SimpleProperty(const osg::ConvexPlanarPolygon &, Occluder, 
	                 __C5_ConvexPlanarPolygon_R1__getOccluder, 
	                 __void__setOccluder__C5_ConvexPlanarPolygon_R1);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::ConvexPlanarPolygon >)

