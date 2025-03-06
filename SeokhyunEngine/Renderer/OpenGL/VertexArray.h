#ifndef __VERTEXARRAY_H__
#define __VERTEXARRAY_H__

#include "common.h"

class VertexArray
{

private:

    GLuint m_vertexArray = 0;

    VertexArray();

    void initVAO();

public:

    static VertexArray* Create();

    ~VertexArray();

    void bind() const;

    void setAttrib(uint attribIndex, int count, uint type, bool normalized, int stride, uint64_t offset) const;
    void disableAttrib(int attribIndex) const;
};


#endif //__VERTEXARRAY_H__
