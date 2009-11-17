/**********************************************************************
 *
 *    FILE:            LOD.cpp
 *
 *    DESCRIPTION:    Read/Write osg::LOD in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerate
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 24.3.2003
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "LOD.h"
#include "Group.h"

using namespace ive;

void LOD::write(DataOutputStream* out){
    // Write LOD's identification.
    out->writeInt(IVELOD);
    // If the osg class is inherited by any other class we should also write this to file.
    osg::Group*  group = dynamic_cast<osg::Group*>(this);
    if(group){
        ((ive::Group*)(group))->write(out);
    }
    else
        out_THROW_EXCEPTION("LOD::write(): Could not cast this osg::LOD to an osg::Group.");
    // Write LOD's properties.

        out->writeFloat(getRadius());

    // Write centermode
    out->writeInt(getCenterMode());
    out->writeVec3(getCenter());

        out->writeInt(getRangeMode());

    // Write rangelist
    int size = getNumRanges();
    out->writeInt(size);
    for(int i=0;i<size;i++){
        out->writeFloat(getMinRange(i));
        out->writeFloat(getMaxRange(i));
    }
}

void LOD::read(DataInputStream* in){
    // Peek on LOD's identification.
    int id = in->peekInt();
    if(id == IVELOD){
        // Read LOD's identification.
        id = in->readInt();

        // If the osg class is inherited by any other class we should also read this from file.
        osg::Group*  group = dynamic_cast<osg::Group*>(this);
        if(group){
            ((ive::Group*)(group))->read(in);
        }
        else
            in_THROW_EXCEPTION("LOD::read(): Could not cast this osg::LOD to an osg::Group.");
        // Read LOD's properties

                if ( in->getVersion() > VERSION_0002 )
                    setRadius(in->readFloat());

        // Read centermode
        setCenterMode((osg::LOD::CenterMode)in->readInt());
        setCenter(in->readVec3());

                if ( in->getVersion() > VERSION_0002 )
                    setRangeMode((RangeMode)in->readInt());

        // Read rangelist
        int size = in->readInt();;
        for(int i=0;i<size;i++){
            float min = in->readFloat();
            float max = in->readFloat();
            setRange(i, min, max);
        }
    }
    else{
        in_THROW_EXCEPTION("LOD::read(): Expected LOD identification.");
    }
}
