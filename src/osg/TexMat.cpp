#include "osg/GL"
#include "osg/TexMat"

using namespace osg;

TexMat::TexMat()
{
}


TexMat::~TexMat()
{
}

void TexMat::apply(State&) const
{
    glMatrixMode( GL_TEXTURE );
    glLoadMatrixf( _matrix.ptr() );
}
