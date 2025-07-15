// C++
#include <vector>
// Libs
#include <glad/glad.h>
// Local
#include "ebo.h"


/*
 * @brief: EBO constructor
 *
 * @param indices : Element indices
 * @param size    : Number of indices
 */

EBO::EBO(std::vector<GLuint> &indices)
{
    unsigned long size = indices.size() * sizeof(GLuint);

    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)size, indices.data(), GL_STATIC_DRAW);
};

/*
 * @brief: Binds the EBO
 */

void EBO::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

/*
 * @brief: Deletes the EBO
 */

void EBO::remove() const
{
    glDeleteBuffers(1, &ID);
}

/*
 * @brief: Unbinds the EBO
 */

void EBO::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
