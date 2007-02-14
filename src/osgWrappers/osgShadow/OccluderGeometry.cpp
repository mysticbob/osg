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

#include <osg/BoundingBox>
#include <osg/CopyOp>
#include <osg/Drawable>
#include <osg/Matrix>
#include <osg/Node>
#include <osg/Object>
#include <osg/Polytope>
#include <osg/RenderInfo>
#include <osg/Vec4>
#include <osgShadow/OccluderGeometry>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(std::vector< osg::Vec3 >, osgShadow::OccluderGeometry::Vec3List);

TYPE_NAME_ALIAS(std::vector< GLuint >, osgShadow::OccluderGeometry::UIntList);

BEGIN_OBJECT_REFLECTOR(osgShadow::OccluderGeometry)
	I_BaseType(osg::Drawable);
	I_Constructor0(____OccluderGeometry,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgShadow::OccluderGeometry &, oc, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____OccluderGeometry__C5_OccluderGeometry_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __Object_P1__clone__C5_osg_CopyOp_R1,
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
	I_MethodWithDefaults3(void, computeOccluderGeometry, IN, osg::Node *, subgraph, , IN, osg::Matrix *, matrix, 0, IN, float, sampleRatio, 1.0f,
	                      Properties::NON_VIRTUAL,
	                      __void__computeOccluderGeometry__osg_Node_P1__osg_Matrix_P1__float,
	                      "Compute an occluder geometry containing all the geometry in specified subgraph. ",
	                      "");
	I_MethodWithDefaults3(void, computeOccluderGeometry, IN, osg::Drawable *, drawable, , IN, osg::Matrix *, matrix, 0, IN, float, sampleRatio, 1.0f,
	                      Properties::NON_VIRTUAL,
	                      __void__computeOccluderGeometry__osg_Drawable_P1__osg_Matrix_P1__float,
	                      "Compute an occluder geometry containing the geometry in specified drawable. ",
	                      "");
	I_Method2(void, computeShadowVolumeGeometry, IN, const osg::Vec4 &, lightpos, IN, osgShadow::ShadowVolumeGeometry &, svg,
	          Properties::NON_VIRTUAL,
	          __void__computeShadowVolumeGeometry__C5_osg_Vec4_R1__ShadowVolumeGeometry_R1,
	          "Compute ShadowVolumeGeometry. ",
	          "");
	I_Method1(void, setBoundingPolytope, IN, const osg::Polytope &, polytope,
	          Properties::NON_VIRTUAL,
	          __void__setBoundingPolytope__C5_osg_Polytope_R1,
	          "Set the bounding polytope of the OccluderGeometry. ",
	          "");
	I_Method0(osg::Polytope &, getBoundingPolytope,
	          Properties::NON_VIRTUAL,
	          __osg_Polytope_R1__getBoundingPolytope,
	          "Get the bounding polytope of the OccluderGeometry. ",
	          "");
	I_Method0(const osg::Polytope &, getBoundingPolytope,
	          Properties::NON_VIRTUAL,
	          __C5_osg_Polytope_R1__getBoundingPolytope,
	          "Get the const bounding polytope of the OccluderGeometry. ",
	          "");
	I_Method1(void, drawImplementation, IN, osg::RenderInfo &, renderInfo,
	          Properties::VIRTUAL,
	          __void__drawImplementation__osg_RenderInfo_R1,
	          "Render the occluder geometry. ",
	          "");
	I_Method0(osg::BoundingBox, computeBound,
	          Properties::VIRTUAL,
	          __osg_BoundingBox__computeBound,
	          "Compute the bounding box around occluder geometry. ",
	          "");
	I_MethodWithDefaults3(void, processGeometry, IN, osg::Drawable *, drawable, , IN, osg::Matrix *, matrix, 0, IN, float, sampleRatio, 1.0f,
	                      Properties::NON_VIRTUAL,
	                      __void__processGeometry__osg_Drawable_P1__osg_Matrix_P1__float,
	                      "",
	                      "");
	I_SimpleProperty(const osg::Polytope &, BoundingPolytope, 
	                 __C5_osg_Polytope_R1__getBoundingPolytope, 
	                 __void__setBoundingPolytope__C5_osg_Polytope_R1);
END_REFLECTOR

TYPE_NAME_ALIAS(std::vector< osg::Vec3 >, osgShadow::ShadowVolumeGeometry::Vec3List);

TYPE_NAME_ALIAS(std::vector< GLuint >, osgShadow::ShadowVolumeGeometry::UIntList);

BEGIN_ENUM_REFLECTOR(osgShadow::ShadowVolumeGeometry::DrawMode)
	I_EnumLabel(osgShadow::ShadowVolumeGeometry::GEOMETRY);
	I_EnumLabel(osgShadow::ShadowVolumeGeometry::STENCIL_TWO_PASS);
	I_EnumLabel(osgShadow::ShadowVolumeGeometry::STENCIL_TWO_SIDED);
END_REFLECTOR

BEGIN_OBJECT_REFLECTOR(osgShadow::ShadowVolumeGeometry)
	I_BaseType(osg::Drawable);
	I_Constructor0(____ShadowVolumeGeometry,
	               "",
	               "");
	I_ConstructorWithDefaults2(IN, const osgShadow::ShadowVolumeGeometry &, oc, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY,
	                           ____ShadowVolumeGeometry__C5_ShadowVolumeGeometry_R1__C5_osg_CopyOp_R1,
	                           "",
	                           "");
	I_Method0(osg::Object *, cloneType,
	          Properties::VIRTUAL,
	          __Object_P1__cloneType,
	          "Clone the type of an object, with Object* return type. ",
	          "Must be defined by derived classes. ");
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop,
	          Properties::VIRTUAL,
	          __Object_P1__clone__C5_osg_CopyOp_R1,
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
	I_Method1(void, setDrawMode, IN, osgShadow::ShadowVolumeGeometry::DrawMode, mode,
	          Properties::NON_VIRTUAL,
	          __void__setDrawMode__DrawMode,
	          "",
	          "");
	I_Method0(osgShadow::ShadowVolumeGeometry::DrawMode, getDrawMode,
	          Properties::NON_VIRTUAL,
	          __DrawMode__getDrawMode,
	          "",
	          "");
	I_Method1(void, setVertices, IN, const osgShadow::ShadowVolumeGeometry::Vec3List &, vertices,
	          Properties::NON_VIRTUAL,
	          __void__setVertices__C5_Vec3List_R1,
	          "",
	          "");
	I_Method0(osgShadow::ShadowVolumeGeometry::Vec3List &, getVertices,
	          Properties::NON_VIRTUAL,
	          __Vec3List_R1__getVertices,
	          "",
	          "");
	I_Method0(const osgShadow::ShadowVolumeGeometry::Vec3List &, getVertices,
	          Properties::NON_VIRTUAL,
	          __C5_Vec3List_R1__getVertices,
	          "",
	          "");
	I_Method1(void, setNormals, IN, const osgShadow::ShadowVolumeGeometry::Vec3List &, normals,
	          Properties::NON_VIRTUAL,
	          __void__setNormals__C5_Vec3List_R1,
	          "",
	          "");
	I_Method0(osgShadow::ShadowVolumeGeometry::Vec3List &, getNormals,
	          Properties::NON_VIRTUAL,
	          __Vec3List_R1__getNormals,
	          "",
	          "");
	I_Method0(const osgShadow::ShadowVolumeGeometry::Vec3List &, getNormals,
	          Properties::NON_VIRTUAL,
	          __C5_Vec3List_R1__getNormals,
	          "",
	          "");
	I_Method1(void, drawImplementation, IN, osg::RenderInfo &, renderInfo,
	          Properties::VIRTUAL,
	          __void__drawImplementation__osg_RenderInfo_R1,
	          "Render the occluder geometry. ",
	          "");
	I_Method0(osg::BoundingBox, computeBound,
	          Properties::VIRTUAL,
	          __osg_BoundingBox__computeBound,
	          "Compute the bounding box around occluder geometry. ",
	          "");
	I_SimpleProperty(osgShadow::ShadowVolumeGeometry::DrawMode, DrawMode, 
	                 __DrawMode__getDrawMode, 
	                 __void__setDrawMode__DrawMode);
	I_SimpleProperty(const osgShadow::ShadowVolumeGeometry::Vec3List &, Normals, 
	                 __C5_Vec3List_R1__getNormals, 
	                 __void__setNormals__C5_Vec3List_R1);
	I_SimpleProperty(const osgShadow::ShadowVolumeGeometry::Vec3List &, Vertices, 
	                 __C5_Vec3List_R1__getVertices, 
	                 __void__setVertices__C5_Vec3List_R1);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< GLuint >);

