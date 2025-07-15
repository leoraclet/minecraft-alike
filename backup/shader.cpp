#include "shader.h"

/*
 * Shader class constructor
 * Read shaders from files and compile them
 */

Shader::Shader(const char *vPath, const char *fPath)
{

    // Create strings
    std::string vCode;
    std::string fCode;

    // Create file objects
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // Ensure file objects can throw exceptions
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {

        // OPen shader files
        vShaderFile.open(vPath);
        fShaderFile.open(fPath);

        // Create string streams
        std::stringstream vShaderStream;
        std::stringstream fShaderStream;

        // Rad opened files
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        // Close files
        vShaderFile.close();
        fShaderFile.close();

        // String streams to string
        vCode = vShaderStream.str();
        fCode = fShaderStream.str();

    }
    catch(std::ifstream::failure &e) {
        std::cout << "READ::SHADER::FILE::ERROR" << std::endl;
    }

    // Shaders code as char array
    const char *vShaderCode = vCode.c_str();
    const char *fShaderCode = fCode.c_str();

    // Shaders
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

    // Link shaders
    glAttachShader(ID, vShader);
    glAttachShader(ID, fShader);
    glLinkProgram(ID);
    checkShaderErrors(ID, true);

    // Delete shaders
    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

/*
 * Use shader program
 */

void Shader::use() const
{
    glUseProgram(ID);
}

/*
 * Delete shader program
 */

void Shader::destroy() const
{
    glDeleteProgram(ID);
}

/*
 * Uniform utility functions
 */

void Shader::setBool(const char *name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name), (int)value);
}

void Shader::setInt(const char *name, int value) const
{
    glUniform1i(glGetUniformLocation(ID, name), value);
}

void Shader::setFloat(const char *name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name), value);
}

void Shader::setVec2(const char *name, const glm::vec2 &value) const
{
    glUniform2fv(glGetUniformLocation(ID, name), 1, &value[0]);
}

void Shader::setVec3(const char *name, const glm::vec3 &value) const
{
    glUniform3fv(glGetUniformLocation(ID, name), 1, &value[0]);
}

void Shader::setVec4(const char *name, const glm::vec4 &value) const
{
    glUniform4fv(glGetUniformLocation(ID, name), 1, &value[0]);
}

void Shader::setMat2(const char *name, const glm::mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat3(const char *name, const glm::mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat4(const char *name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, &mat[0][0]);
}

/*
 * Check for shader compile or linking errors
 */

void Shader::checkShaderErrors(GLuint shader, bool isProgram)
{
    GLint success;
    GLchar infoLog[512];

    // If it's a shade program
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
