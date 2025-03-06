#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "common.h"

template <GLenum type, typename T>
class Buffer
{

private:

    GLuint m_buffer;
    GLuint m_usage;

    std::size_t m_count;

    const void* m_data;

    Buffer();

    bool initBuffer(const void* data, size_t count, GLuint usage);


public:

    ~Buffer();

    static Buffer* Create(const void* data, size_t count);

    void bind() const;
    void unbind() const;

    std::size_t getCount()  const { return m_count; }
    const GLuint get()      const { return m_buffer; }
};

using VertexBuffer = Buffer<GL_ARRAY_BUFFER, glm::vec3>;
using IndexBuffer = Buffer<GL_ELEMENT_ARRAY_BUFFER, unsigned int>;


#endif //__BUFFER_H__
