#include "Mesh.h"

Mesh::Mesh()
{

}

void Mesh::initMesh(const std::vector<glm::vec3> &vertices, const std::vector<uint32_t> &indices)
{
    m_vertexArray = VertexArray::Create();

//    m_vertexBuffer = Buffer::Create(GL_ARRAY_BUFFER, GL_STATIC_DRAW, vertices.data(), sizeof(glm::vec3), vertices.size());
//    m_indexBuffer = Buffer::Create(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, indices.data(), sizeof(uint32_t), indices.size());

    m_vertexBuffer = VertexBuffer::Create(vertices.data(), vertices.size());
    m_indexBuffer = IndexBuffer::Create(indices.data(), indices.size());

    m_vertexArray->setAttrib(0, 3, GL_FLOAT, false, sizeof(glm::vec3), 0);
}

Mesh *Mesh::Create(const std::vector<glm::vec3> &vertices, const std::vector<uint32_t> &indices)
{
    auto mesh = new Mesh();
    mesh->initMesh(vertices, indices);

    return mesh;
}

Mesh *Mesh::CreateSquare()
{
    std::vector<glm::vec3> recVert =
    {
        glm::vec3(-0.5f,  0.5f, 0.0f),
        glm::vec3( 0.5f,  0.5f, 0.0f),
        glm::vec3(-0.5f, -0.5f, 0.0f),
        glm::vec3( 0.5f, -0.5f, 0.0f)
    };

    std::vector<unsigned int> recIndic =
    {
        0, 1, 2,
        2, 1, 3
    };

    return Create(recVert, recIndic);
}

void Mesh::draw()
{
    m_vertexArray->bind();
    glDrawElements(m_primitiveType, m_indexBuffer->getCount(), GL_UNSIGNED_INT, 0);
}

