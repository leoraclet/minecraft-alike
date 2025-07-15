// C++
#include <iostream>
#include <fstream>
#include <sstream>
// Libs
#include <glad/glad.h>
#include <glm/glm.hpp>
// Local
#include "shader.h"


/*
 * @brief: Read shader files, compile them and attach them to the shader program
 *
 * @param vPath: Path to the vertex shader file
 * @param fPath: Path to the fragment shader file
 */

Shader::Shader(const char *vPath, const char *fPath)
{

    // Strings to store shaders code
    std::string vCode;
    std::string fCode;

    // File streams
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // Ensure file streams can throw exceptions
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        // Open shader files
        vShaderFile.open(vPath);
        fShaderFile.open(fPath);

        // String streams
        std::stringstream vShaderStream;
        std::stringstream fShaderStream;

        // Read files
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        // Close files
        vShaderFile.close();
        fShaderFile.close();

        // Convert string streams to string
        vCode = vShaderStream.str();
        fCode = fShaderStream.str();

    }
    catch(std::ifstream::failure &e)
    {
        std::cout << "READ::SHADER::FILE::ERROR" << std::endl;
    }

    // Shaders code as arrays of char
    const char *vShaderCode = vCode.c_str();
    const char *fShaderCode = fCode.c_str();

    // Shaders references
    GLuint vShader;
    GLuint fShader;

    // Compile vertex shader
    vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vShaderCode, nullptr);
    glCompileShader(vShader);
    checkShaderErrors(vShader, false);

    // Compile fragment shader
    fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fShaderCode, nullptr);
    glCompileShader(fShader);
    checkShaderErrors(fShader, false);

    // Create shader program
    ID = glCreateProgram();

    // Attach shaders to the shader program
    glAttachShader(ID, vShader);
    glAttachShader(ID, fShader);

    // Links the shader program
    glLinkProgram(ID);
    checkShaderErrors(ID, true);

    // Delete shaders
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

/*
 * @brief: Use shader program
 */

void Shader::use() const
{
    glUseProgram(ID);
}

/*
 * @brief: Delete shader program
 */

void Shader::destroy() const
{
    glDeleteProgram(ID);
}

/*
 * @brief: Check for shader compile or linking errors
 *
 * @param shader    : Shader reference
 * @param isProgram : Is it a shader program ?
 */

void Shader::checkShaderErrors(GLuint shader, bool isProgram)
{
    GLint success;
    GLchar infoLog[512];

    // If it's a shader program
    if (isProgram)
    {
        // Check for linking errors on shaders
        glGetProgramiv(shader, GL_LINK_STATUS, &success);

        if (!success) {
            glGetProgramInfoLog(shader, 512, nullptr, infoLog);
            std::cout << "SHADER::LINKING:ERROR" << infoLog << std::endl;
        }
    }
    else
    {
        // Check for compilation error on shader
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success)
        {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cout << "SHADER::COMPILATION::ERROR" << infoLog << std::endl;
        }
    }
}

/*
 * @brief: Pass a boolean as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Value of the boolean variable
 */

void Shader::setUniform(const char *name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name), (int)value);
}

/*
 * @brief: Pass an integer as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Value of the integer variable
 */

void Shader::setUniform(const char *name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name), value);
}

/*
 * @brief: Pass a float as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Value of the float variable
 */

void Shader::setUniform(const char *name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name), value);
}

/*
 * @brief: Pass a 2D vector as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Vector variable reference
 */

void Shader::setUniform(const char *name, const glm::vec2 &vec) const
{
    glUniform2fv(glGetUniformLocation(ID, name), 1, &vec[0]);
}

/*
 * @brief: Pass a 3D vector as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Vector variable reference
 */

void Shader::setUniform(const char *name, const glm::vec3 &vec) const
{
    glUniform3fv(glGetUniformLocation(ID, name), 1, &vec[0]);
}

/*
 * @brief: Pass a 4D vector as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Vector variable reference
 */

void Shader::setUniform(const char *name, const glm::vec4 &vec) const
{
    glUniform4fv(glGetUniformLocation(ID, name), 1, &vec[0]);
}

/*
 * @brief: Pass a 2D matrix as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Matrix variable reference
 */

void Shader::setUniform(const char *name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &mat[0][0]);
}

/*
 * @brief: Pass a 3D matrix as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Matrix variable reference
 */

void Shader::setUniform(const char *name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &mat[0][0]);
}

/*
 * @brief: Pass a 4D matrix as a uniform
 *
 * @param name  : Name of the uniform
 * @param value : Matrix variable reference
 */

void Shader::setUniform(const char *name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &mat[0][0]);
}
