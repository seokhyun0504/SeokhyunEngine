#include "VertexArray.h"

VertexArray::VertexArray()
{

}

VertexArray::~VertexArray()
{
    if (m_vertexArray)
    {
        glDeleteVertexArrays(1, &m_vertexArray);
    }
}

void VertexArray::initVAO()
{
    glGenVertexArrays(1, &m_vertexArray);
    bind();
}

VertexArray *VertexArray::Create()
{
    auto va = new VertexArray();
    va->initVAO();

    return va;
}

void VertexArray::bind() const
{
    glBindVertexArray(m_vertexArray);
}

void VertexArray::setAttrib(unsigned int attribIndex, int count, unsigned int type, bool normalized, int stride, uint64_t offset) const
{
    glEnableVertexAttribArray(attribIndex);
    glVertexAttribPointer(attribIndex, count, type, normalized, stride, (const void*) offset);
}

