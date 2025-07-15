#include "window.h"


/*
 * Initialize openGL and create a new
 * window with given parameters.
 */

Window::Window(int width, int height, const char *title)
{
    // GLFW Initialisation
    if (!glfwInit()) {
        std::cout << "GLFW::INITIALISATION::ERROR" << std::endl;
        exit(1);
    }

    // Set defaults versions for openGL
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a new window
    handler = glfwCreateWindow(width, height, title, nullptr, nullptr);

    // Check for window creation errors
    if (handler == nullptr)
    {
        std::cout << "WINDOW::CREATION::ERROR" << std::endl;
        glfwTerminate();
        exit(1);
    }

    // Make this window the current context
    glfwMakeContextCurrent(handler);
    // Ensure we can capture pressed keys
    glfwSetInputMode(handler, GLFW_STICKY_KEYS, GL_TRUE);
    // Hide the mouse and enable unlimited movement
    glfwSetInputMode(handler, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // GLAD Initialisation
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD::INITIALISATION::ERROR" << std::endl;
        exit(1);
    }

    glfwSwapInterval(1);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
}
