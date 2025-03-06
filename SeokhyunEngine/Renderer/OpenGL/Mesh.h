#ifndef __MESH_H__
#define __MESH_H__

#include "common.h"

#include "Renderer/OpenGL/Buffer.h"
#include "Renderer/OpenGL/VertexArray.h"

class Mesh
{

private:

    GLuint m_primitiveType = GL_TRIANGLES;

    VertexArray *m_vertexArray;

//    std::vector<Buffer*> m_buffer;
//    Buffer* m_vertexBuffer;
//    Buffer* m_indexBuffer;

    VertexBuffer* m_vertexBuffer;
    IndexBuffer * m_indexBuffer;

    Mesh();

    void initMesh(const std::vector<glm::vec3> &vertices, const std::vector<uint32_t> &indices);

public:

    static Mesh* Create(const std::vector<glm::vec3> &vertices, const std::vector<uint32_t> &indices);
    static Mesh* CreateSquare();

    void draw();
};


#endif //__MESH_H__
