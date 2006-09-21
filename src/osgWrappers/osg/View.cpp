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

#include <osg/CameraNode>
#include <osg/CopyOp>
#include <osg/Matrix>
#include <osg/Matrixd>
#include <osg/Matrixf>
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osg/Vec3>
#include <osg/View>

// Must undefine IN and OUT macros defined in Windows headers
#ifdef IN
#undef IN
#endif
#ifdef OUT
#undef OUT
#endif

BEGIN_OBJECT_REFLECTOR(osg::View)
	I_BaseType(osg::Transform);
	I_BaseType(osg::CullSettings);
	I_Constructor0();
	I_ConstructorWithDefaults2(IN, const osg::View &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	I_Method0(osg::Object *, cloneType);
	I_Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	I_Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	I_Method0(const char *, className);
	I_Method0(const char *, libraryName);
	I_Method1(void, accept, IN, osg::NodeVisitor &, nv);
	I_Method1(void, setProjectionMatrix, IN, const osg::Matrixf &, matrix);
	I_Method1(void, setProjectionMatrix, IN, const osg::Matrixd &, matrix);
	I_Method6(void, setProjectionMatrixAsOrtho, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top, IN, double, zNear, IN, double, zFar);
	I_Method4(void, setProjectionMatrixAsOrtho2D, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top);
	I_Method6(void, setProjectionMatrixAsFrustum, IN, double, left, IN, double, right, IN, double, bottom, IN, double, top, IN, double, zNear, IN, double, zFar);
	I_Method4(void, setProjectionMatrixAsPerspective, IN, double, fovy, IN, double, aspectRatio, IN, double, zNear, IN, double, zFar);
	I_Method0(osg::Matrixd &, getProjectionMatrix);
	I_Method0(const osg::Matrixd &, getProjectionMatrix);
	I_Method6(bool, getProjectionMatrixAsOrtho, IN, double &, left, IN, double &, right, IN, double &, bottom, IN, double &, top, IN, double &, zNear, IN, double &, zFar);
	I_Method6(bool, getProjectionMatrixAsFrustum, IN, double &, left, IN, double &, right, IN, double &, bottom, IN, double &, top, IN, double &, zNear, IN, double &, zFar);
	I_Method4(bool, getProjectionMatrixAsPerspective, IN, double &, fovy, IN, double &, aspectRatio, IN, double &, zNear, IN, double &, zFar);
	I_Method1(void, setViewMatrix, IN, const osg::Matrixf &, matrix);
	I_Method1(void, setViewMatrix, IN, const osg::Matrixd &, matrix);
	I_Method3(void, setViewMatrixAsLookAt, IN, const osg::Vec3 &, eye, IN, const osg::Vec3 &, center, IN, const osg::Vec3 &, up);
	I_Method0(osg::Matrixd &, getViewMatrix);
	I_Method0(const osg::Matrixd &, getViewMatrix);
	I_MethodWithDefaults4(void, getViewMatrixAsLookAt, IN, osg::Vec3 &, eye, , IN, osg::Vec3 &, center, , IN, osg::Vec3 &, up, , IN, float, lookDistance, 1.0f);
	I_Method0(osg::Matrixd, getInverseViewMatrix);
	I_Method1(bool, addCamera, IN, osg::CameraNode *, camera);
	I_Method3(bool, addCamera, IN, osg::CameraNode *, camera, IN, const osg::Matrix &, projectionOffset, IN, const osg::Matrix &, viewOffse);
	I_Method1(bool, removeCamera, IN, unsigned int, pos);
	I_Method0(unsigned int, getNumCameras);
	I_Method1(osg::CameraNode *, getCamera, IN, unsigned int, pos);
	I_Method1(const osg::CameraNode *, getCamera, IN, unsigned int, pos);
	I_Method1(osg::View::CameraData &, getCameraData, IN, unsigned int, pos);
	I_Method1(const osg::View::CameraData &, getCameraData, IN, unsigned int, pos);
	I_Method2(bool, computeLocalToWorldMatrix, IN, osg::Matrix &, matrix, IN, osg::NodeVisitor *, x);
	I_Method2(bool, computeWorldToLocalMatrix, IN, osg::Matrix &, matrix, IN, osg::NodeVisitor *, x);
	I_ArrayProperty_GA(osg::CameraNode *, Camera, Cameras, unsigned int, bool);
	I_ReadOnlyProperty(osg::Matrixd, InverseViewMatrix);
	I_Property(const osg::Matrixd &, ProjectionMatrix);
	I_Property(const osg::Matrixd &, ViewMatrix);
END_REFLECTOR

BEGIN_VALUE_REFLECTOR(osg::View::CameraData)
	I_Constructor0();
	I_Constructor3(IN, osg::CameraNode *, camera, IN, const osg::Matrixd &, projectionOffset, IN, const osg::Matrixd &, viewOffset);
	I_Constructor1(IN, const osg::View::CameraData &, rhs);
	I_PublicMemberProperty(osg::ref_ptr< osg::CameraNode >, _camera);
	I_PublicMemberProperty(osg::Matrixd, _projectionOffset);
	I_PublicMemberProperty(osg::Matrixd, _viewOffset);
END_REFLECTOR

