// C++
#include <iostream>
// Libs
#include <glad/glad.h>
#include <stb/stb_image.h>
// Local
#include "shader.h"
#include "texture.h"


/*
 * @brief: Create a texture from an image file
 *
 * @param path      : Path to the image
 * @param texType   : Texture type
 * @pram slot       : Slot of the activated texture
 * @param format    : Image color format
 * @param pixelType : Pixels data type
 */

Texture::Texture(const char *path, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
    Texture::type = texType;
    Texture::unit = slot;

    // Generates a texture, activates and binds it
    glGenTextures(1, &ID);
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(texType, ID);

    // Set the texture wrapping parameters
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Set the texture filtering parameters
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLint width, height;
    unsigned char *data;

    // Flips the image so it appears right side up
    stbi_set_flip_vertically_on_load(true);

    // Load image data into an array of chars
    data = stbi_load(path, &width, &height, nullptr, 0);

    // Check the loaded data
    if (data)
    {
        // Create the texture
        glTexImage2D(texType, 0, GL_RGB, width, height, 0, format, pixelType, data);
        glGenerateMipmap(texType);
    }
    else
    {
        std::cout << "LOAD::TEXTURE::ERROR" << std::endl;
    }

    // Free memory
    stbi_image_free(data);
    unbind();
}

/*
 * @brief: Assigns a texture unit to the texture
 *
 * @param shader  : Shader program reference
 * @param uniform : Uniform name
 * @param unit    : Texture unit
 */

void Texture::texUnit(Shader& shader, const char* uniform, GLint unit)
{
    // Gets the location of the uniform
    GLint texUni = glGetUniformLocation(shader.getID(), uniform);
    // Shader needs to be activated before changing the value of a uniform
    shader.use();
    // Sets the value of the uniform
    glUniform1i(texUni, unit);
}

/*
 * @brief: Binds the texture
 */

void Texture::bind() const
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(type, ID);
}

/*
 * @brief: Unbinds the texture
 */

void Texture::unbind() const
{
    glBindTexture(type, 0);
}

/*
 * @brief: Deletes the texture
 */

void Texture::remove() const
{
    glDeleteTextures(1, &ID);
}