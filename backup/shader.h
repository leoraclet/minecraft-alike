/*
 * The shader class read shader files at the
 * given path, import their code, compile it
 * and link it to the shader program created
 * for rendering.
 */

#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include "glm/glm.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


class Shader {

public:

    // Shader program ID
    GLuint ID;

    // Class constructor
    Shader(const char *vPath, const char *fPath);

    // Activate the shader
    void use() const;

    // Utility uniform functions
    void setBool(const char *name, bool value) const;
    void setInt(const char *name, int value) const;
    void setFloat(const char *name, float value) const;
    void setVec2(const char *name, const glm::vec2 &value) const;
    void setVec3(const char *name, const glm::vec3 &value) const;
    void setVec4(const char *name, const glm::vec4 &value) const;
    void setMat2(const char *name, const glm::mat2 &mat) const;
    void setMat3(const char *name, const glm::mat3 &mat) const;
    void setMat4(const char *name, const glm::mat4 &mat) const;

    // Delete shader
    void destroy() const;

private:

    // Check for shaders compile or linking errors
    static void checkShaderErrors(GLuint shader, bool isProgram);

};

#endif // SHADER_H
