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

#include <osg/Array>
#include <osg/Matrix>
#include <osg/Shader>
#include <osg/Uniform>
#include <osgAnimation/RigGeometry>
#include <osgAnimation/RigTransformHardware>
#include <osgAnimation/VertexInfluence>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

TYPE_NAME_ALIAS(osg::Matrix, osgAnimation::RigTransformHardware::MatrixType)

TYPE_NAME_ALIAS(osgAnimation::Bone, osgAnimation::RigTransformHardware::BoneType)

TYPE_NAME_ALIAS(osgAnimation::Bone::BoneMap, osgAnimation::RigTransformHardware::BoneMap)

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osg::Vec4Array > >, osgAnimation::RigTransformHardware::BoneWeightAttribList)

TYPE_NAME_ALIAS(std::vector< osg::ref_ptr< osgAnimation::RigTransformHardware::BoneType > >, osgAnimation::RigTransformHardware::BonePalette)

TYPE_NAME_ALIAS(std::vector< osg::Matrix >, osgAnimation::RigTransformHardware::MatrixPalette)

TYPE_NAME_ALIAS(std::vector< std::vector< osgAnimation::RigTransformHardware::IndexWeightEntry > >, osgAnimation::RigTransformHardware::VertexIndexWeightList)

BEGIN_OBJECT_REFLECTOR(osgAnimation::RigTransformHardware)
	I_DeclaringFile("osgAnimation/RigTransformHardware");
	I_BaseType(osgAnimation::RigTransform);
	I_Constructor0(____RigTransformHardware,
	               "",
	               "");
	I_Method1(osg::Vec4Array *, getVertexAttrib, IN, int, index,
	          Properties::NON_VIRTUAL,
	          __osg_Vec4Array_P1__getVertexAttrib__int,
	          "",
	          "");
	I_Method0(int, getNumVertexAttrib,
	          Properties::NON_VIRTUAL,
	          __int__getNumVertexAttrib,
	          "",
	          "");
	I_Method0(osg::Uniform *, getMatrixPaletteUniform,
	          Properties::NON_VIRTUAL,
	          __osg_Uniform_P1__getMatrixPaletteUniform,
	          "",
	          "");
	I_Method2(void, computeMatrixPaletteUniform, IN, const osg::Matrix &, transformFromSkeletonToGeometry, IN, const osg::Matrix &, invTransformFromSkeletonToGeometry,
	          Properties::NON_VIRTUAL,
	          __void__computeMatrixPaletteUniform__C5_osg_Matrix_R1__C5_osg_Matrix_R1,
	          "",
	          "");
	I_Method0(int, getNumBonesPerVertex,
	          Properties::NON_VIRTUAL,
	          __int__getNumBonesPerVertex,
	          "",
	          "");
	I_Method0(int, getNumVertexes,
	          Properties::NON_VIRTUAL,
	          __int__getNumVertexes,
	          "",
	          "");
	I_Method3(bool, createPalette, IN, int, nbVertexes, IN, osgAnimation::RigTransformHardware::BoneMap, boneMap, IN, const osgAnimation::VertexInfluenceSet::VertexIndexToBoneWeightMap &, vertexIndexToBoneWeightMap,
	          Properties::NON_VIRTUAL,
	          __bool__createPalette__int__BoneMap__C5_VertexInfluenceSet_VertexIndexToBoneWeightMap_R1,
	          "",
	          "");
	I_Method1(bool, init, IN, osgAnimation::RigGeometry &, x,
	          Properties::VIRTUAL,
	          __bool__init__RigGeometry_R1,
	          "",
	          "");
	I_Method1(void, update, IN, osgAnimation::RigGeometry &, x,
	          Properties::VIRTUAL,
	          __void__update__RigGeometry_R1,
	          "",
	          "");
	I_Method1(void, setShader, IN, osg::Shader *, x,
	          Properties::NON_VIRTUAL,
	          __void__setShader__osg_Shader_P1,
	          "",
	          "");
	I_ProtectedMethod0(osgAnimation::RigTransformHardware::BoneWeightAttribList, createVertexAttribList,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __BoneWeightAttribList__createVertexAttribList,
	                   "",
	                   "");
	I_ProtectedMethod0(osg::Uniform *, createVertexUniform,
	                   Properties::NON_VIRTUAL,
	                   Properties::NON_CONST,
	                   __osg_Uniform_P1__createVertexUniform,
	                   "",
	                   "");
	I_SimpleProperty(osg::Uniform *, MatrixPaletteUniform, 
	                 __osg_Uniform_P1__getMatrixPaletteUniform, 
	                 0);
	I_SimpleProperty(osg::Shader *, Shader, 
	                 0, 
	                 __void__setShader__osg_Shader_P1);
	I_ArrayProperty(osg::Vec4Array *, VertexAttrib, 
	                __osg_Vec4Array_P1__getVertexAttrib__int, 
	                0, 
	                __int__getNumVertexAttrib, 
	                0, 
	                0, 
	                0);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osgAnimation::RigTransformHardware::IndexWeightEntry)
	I_DeclaringFile("osgAnimation/RigTransformHardware");
	I_Constructor0(____IndexWeightEntry,
	               "",
	               "");
	I_Constructor2(IN, int, index, IN, float, weight,
	               ____IndexWeightEntry__int__float,
	               "",
	               "");
	I_Method0(int, getIndex,
	          Properties::NON_VIRTUAL,
	          __int__getIndex,
	          "",
	          "");
	I_Method0(float, getWeight,
	          Properties::NON_VIRTUAL,
	          __float__getWeight,
	          "",
	          "");
	I_SimpleProperty(int, Index, 
	                 __int__getIndex, 
	                 0);
	I_SimpleProperty(float, Weight, 
	                 __float__getWeight, 
	                 0);
	I_PublicMemberProperty(int, _boneIndex);
	I_PublicMemberProperty(float, _boneWeight);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osg::Vec4Array >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osg::Vec4Array *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osg::Vec4Array > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osg::Vec4Array *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osg::Vec4Array *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osg::Vec4Array > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osg::Vec4Array *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::ref_ptr< osgAnimation::RigTransformHardware::BoneType >)
	I_DeclaringFile("osg/ref_ptr");
	I_Constructor0(____ref_ptr,
	               "",
	               "");
	I_Constructor1(IN, osgAnimation::RigTransformHardware::BoneType *, ptr,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__T_P1,
	               "",
	               "");
	I_Constructor1(IN, const osg::ref_ptr< osgAnimation::RigTransformHardware::BoneType > &, rp,
	               Properties::NON_EXPLICIT,
	               ____ref_ptr__C5_ref_ptr_R1,
	               "",
	               "");
	I_Method0(osgAnimation::RigTransformHardware::BoneType *, get,
	          Properties::NON_VIRTUAL,
	          __T_P1__get,
	          "",
	          "");
	I_Method0(bool, valid,
	          Properties::NON_VIRTUAL,
	          __bool__valid,
	          "",
	          "");
	I_Method0(osgAnimation::RigTransformHardware::BoneType *, release,
	          Properties::NON_VIRTUAL,
	          __T_P1__release,
	          "",
	          "");
	I_Method1(void, swap, IN, osg::ref_ptr< osgAnimation::RigTransformHardware::BoneType > &, rp,
	          Properties::NON_VIRTUAL,
	          __void__swap__ref_ptr_R1,
	          "",
	          "");
	I_SimpleProperty(osgAnimation::RigTransformHardware::BoneType *, , 
	                 __T_P1__get, 
	                 0);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osg::Vec4Array > >)

STD_VECTOR_REFLECTOR(std::vector< osg::ref_ptr< osgAnimation::RigTransformHardware::BoneType > >)

STD_VECTOR_REFLECTOR(std::vector< osgAnimation::RigTransformHardware::IndexWeightEntry >)

STD_VECTOR_REFLECTOR(std::vector< std::vector< osgAnimation::RigTransformHardware::IndexWeightEntry > >)

