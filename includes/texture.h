#ifndef TEXTURE_H
#define TEXTURE_H


class Texture
{
private:
    // ID reference of the texture
    GLuint ID = 0;
    // Texture type
    GLenum type;
    // Texture unit
    GLuint unit;
public:
    // Class constructor
    Texture(const char *path, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

    // Assigns a texture unit to the texture
    static void texUnit(Shader& shader, const char* uniform, GLint unit);

    void bind() const;
    void unbind() const;
    void remove() const;
};

#endif // TEXTURE_H
