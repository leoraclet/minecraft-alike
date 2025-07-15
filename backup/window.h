/*
 * The window class create a new window
 * with given parameters and initialize
 * GLFW and GLAD libraries.
 */

#ifndef WINDOW_H
#define WINDOW_H

#include "glad/glad.h"
#include "glfw/glfw3.h"
#include <iostream>


class Window {

public:

    // Window handler
    GLFWwindow *handler;

    // class constructor
    Window(int width, int height, const char *title);

};

#endif // WINDOW_H
