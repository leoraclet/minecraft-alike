// Libs
#include <glad/glad.h>
// Local
#include "vbo.h"
#include "vao.h"


/*
 * @brief: VAO constructor
 */

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}

/*
 * @brief: Links a VBO attribute to the VAO
 *
 * @param vbo    : Vertex buffer object reference
 * @param layout : Layout to use
 * @param nbCmp  : Number of components
 * @param type   : Data type
 * @param stride : ?
 * @param offset : ?
 */

void VAO::link_attrib(VBO &vbo, GLuint layout, GLint nbCmp, GLenum type, GLsizei stride, void *offset)
{
    vbo.bind();
    glVertexAttribPointer(layout, nbCmp, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
    vbo.unbind();
}

/*
 * @brief: Binds the VAO
 */

void VAO::bind() const
{
    glBindVertexArray(ID);
}

/*
 * @brief: Deletes the VAO
 */

void VAO::remove() const
{
    glDeleteVertexArrays(1, &ID);
}

/*
 * @brief: Unbinds the VAO
 */

void VAO::unbind()
{
    glBindVertexArray(0);
}
