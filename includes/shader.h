#ifndef SHADER_H
#define SHADER_H


#include "glm/fwd.hpp"
#include <glad/glad.h>

class Shader
{
private:
    // ID reference of the Shader Program
    GLuint ID;
    // Check for shaders compile or linking errors
    static void checkShaderErrors(GLuint shader, bool isProgram);
public:
    // Class constructor
    Shader(const char *vPath, const char *fPath);

    void use() const;
    void destroy() const;

    // Pass uniforms to the shader program
    void setUniform(const char *name, bool value) const;
    void setUniform(const char *name, int value) const;
    void setUniform(const char *name, float value) const;
    void setUniform(const char *name, const glm::vec2 &vec) const;
    void setUniform(const char *name, const glm::vec3 &vec) const;
    void setUniform(const char *name, const glm::vec4 &vec) const;
    void setUniform(const char *name, const glm::mat2 &mat) const;
    void setUniform(const char *name, const glm::mat3 &mat) const;
    void setUniform(const char *name, const glm::mat4 &mat) const;

    // Getter
    GLuint getID() const {return ID;};
};

#endif // SHADER_H
