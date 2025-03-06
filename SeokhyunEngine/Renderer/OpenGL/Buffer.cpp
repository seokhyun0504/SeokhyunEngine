#include "Buffer.h"

template<GLenum type, typename T>
Buffer<type, T>::Buffer()
{

}

template<GLenum type, typename T>
Buffer<type, T>::~Buffer()
{
    if (m_buffer)
    {
        glDeleteBuffers(1, &m_buffer);
    }
}

template<GLenum type, typename T>
bool Buffer<type, T>::initBuffer(const void* data, size_t count, GLuint usage)
{
    m_data = data; m_count = count; m_usage = usage;

    glGenBuffers(1, &m_buffer);
    bind();

    glBufferData(type, sizeof(T) * m_count, data, m_usage);

    return true;
}

template<GLenum type, typename T>
Buffer<type, T> *Buffer<type, T>::Create(const void *data, size_t count)
{
    auto buffer = new Buffer<type, T>();
    buffer->initBuffer(data, count, GL_STATIC_DRAW);

    return buffer;
}

template<GLenum type, typename T>
void Buffer<type, T>::bind() const
{
    glBindBuffer(type, m_buffer);
}

template<GLenum type, typename T>
void Buffer<type, T>::unbind() const
{
    glBindBuffer(type, 0);
}

template class Buffer<GL_ARRAY_BUFFER, glm::vec3>;
template class Buffer<GL_ELEMENT_ARRAY_BUFFER, unsigned int>;