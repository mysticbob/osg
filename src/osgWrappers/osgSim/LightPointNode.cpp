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
#include <osg/NodeVisitor>
#include <osg/Object>
#include <osgSim/LightPoint>
#include <osgSim/LightPointNode>
#include <osgSim/LightPointSystem>

TYPE_NAME_ALIAS(std::vector< osgSim::LightPoint >, osgSim::LightPointNode::LightPointList);

BEGIN_OBJECT_REFLECTOR(osgSim::LightPointNode)
	BaseType(osg::Node);
	Constructor0();
	ConstructorWithDefaults2(IN, const osgSim::LightPointNode &, x, , IN, const osg::CopyOp &, copyop, osg::CopyOp::SHALLOW_COPY);
	Method0(osg::Object *, cloneType);
	Method1(osg::Object *, clone, IN, const osg::CopyOp &, copyop);
	Method1(bool, isSameKindAs, IN, const osg::Object *, obj);
	Method0(const char *, className);
	Method0(const char *, libraryName);
	Method1(void, accept, IN, osg::NodeVisitor &, nv);
	Method1(void, traverse, IN, osg::NodeVisitor &, nv);
	Method0(unsigned int, getNumLightPoints);
	Method1(unsigned int, addLightPoint, IN, const osgSim::LightPoint &, lp);
	Method1(void, removeLightPoint, IN, unsigned int, pos);
	Method1(osgSim::LightPoint &, getLightPoint, IN, unsigned int, pos);
	Method1(const osgSim::LightPoint &, getLightPoint, IN, unsigned int, pos);
	Method1(void, setLightPointList, IN, const osgSim::LightPointNode::LightPointList &, lpl);
	Method0(osgSim::LightPointNode::LightPointList &, getLightPointList);
	Method0(const osgSim::LightPointNode::LightPointList &, getLightPointList);
	Method1(void, setMinPixelSize, IN, float, minPixelSize);
	Method0(float, getMinPixelSize);
	Method1(void, setMaxPixelSize, IN, float, maxPixelSize);
	Method0(float, getMaxPixelSize);
	Method1(void, setMaxVisibleDistance2, IN, float, maxVisibleDistance2);
	Method0(float, getMaxVisibleDistance2);
	Method1(void, setLightPointSystem, IN, osgSim::LightPointSystem *, lps);
	Method0(osgSim::LightPointSystem *, getLightPointSystem);
	ArrayProperty_GA(const osgSim::LightPoint &, LightPoint, LightPoints, unsigned int, unsigned int);
	Property(const osgSim::LightPointNode::LightPointList &, LightPointList);
	Property(osgSim::LightPointSystem *, LightPointSystem);
	Property(float, MaxPixelSize);
	Property(float, MaxVisibleDistance2);
	Property(float, MinPixelSize);
END_REFLECTOR

STD_VECTOR_REFLECTOR(std::vector< osgSim::LightPoint >);

