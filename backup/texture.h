/*
 * The class texture read the image file at
 * the given path using the "stb_image.h" header
 * and create a new texture out of the data.
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include <iostream>

#include "stb/stb_image.h"


class Texture {

public:

    // Texture
    GLuint ID;

    // Class constructor
    explicit Texture(const char *path);

};

#endif // TEXTURE_H
