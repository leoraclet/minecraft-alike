#ifndef VAO_H
#define VAO_H

/*
 * @brief: Vertex Array Object
 */

class VAO
{
private:
    // ID reference of EBO
    GLuint ID = 0;
public:
    // Class constructor
    VAO();

    void bind() const;
    void remove() const;

    static void link_attrib(VBO &vbo, GLuint layout, GLint nbCmp, GLenum type, GLsizei stride, void* offset);
    static void unbind();
};

#endif // VAO_H
