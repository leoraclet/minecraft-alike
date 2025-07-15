//
// Created by Neutronys on 09/02/2022.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include <vector>

#include "window.h"
#include "camera.h"
#include "shader.h"
#include "texture.h"


class Renderer {

public:

    // Buffers and arrays
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    Window *window;
    Camera *camera;

    std::vector<Shader> shaders;
    std::vector<Texture> textures;

    // Class constructor
    Renderer(Window *window, Camera *camera);

    // Render scene
    void render();

    // Delete
    void destroy();

};

#endif // RENDERER_H
