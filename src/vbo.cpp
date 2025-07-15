// C++
#include <vector>
// Libs
#include <glad/glad.h>
#include <glm/glm.hpp>
// Local
#include "vbo.h"


/*
 * @brief: VBO constructor
 *
 * @param vertices : Vertex vertices
 * @param size     : Number of vertices
 */

VBO::VBO(std::vector<Vertex> &vertices)
{
    unsigned long size = vertices.size() * sizeof(Vertex);

    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, (GLsizeiptr)size, vertices.data(), GL_STATIC_DRAW);
}

/*
 * @brief: Binds the VBO
 */

void VBO::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

/*
 * @brief: Deletes the VBO
 */

void VBO::remove() const
{
    glDeleteBuffers(1, &ID);
}

/*
 * @brief: Unbinds the VBO
 */

void VBO::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
