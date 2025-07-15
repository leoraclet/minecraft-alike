#include "window.h"
#include "camera.h"
#include "renderer.h"


// Global variables
GLfloat lastX = 0;
GLfloat lastY = 0;
GLfloat deltaTime = 0;
GLfloat lastFrame = 0;
GLboolean firstMouse = true;

// Class objects
Window *window = nullptr;
Camera *camera = nullptr;
Renderer *renderer = nullptr;

// Callback functions for openGL window events
static void key_callback(GLFWwindow *win, int key, int, int action, int);
static void size_callback(GLFWwindow *, int width, int height);
static void scroll_callback(GLFWwindow *, double, double yOffset);
static void mouse_callback(GLFWwindow *, double xPosIn, double yPosIn);

// Process keyboard inputs
void processInputs(GLFWwindow *win);


int main()
{
    // Initialize classes
    window = new Window(1000, 800, "Minecraft");
    camera = new Camera();
    renderer = new Renderer(window, camera);

    // Setup callback functions
    glfwSetKeyCallback(window->handler, key_callback);
    glfwSetFramebufferSizeCallback(window->handler, size_callback);
    glfwSetScrollCallback(window->handler, scroll_callback);
    glfwSetCursorPosCallback(window->handler, mouse_callback);

    // Main infinite loop
    while (!glfwWindowShouldClose(window->handler))
    {
        // Get time
        GLfloat currentFrame;
        currentFrame = (GLfloat)glfwGetTime();

        // Set last frame and delta time
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Process inputs
        processInputs(window->handler);

        // Clear color & depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render scene
        renderer->render();

        // Swap buffers & check for events triggers
        glfwSwapBuffers(window->handler);
        glfwPollEvents();
    }

    renderer->destroy();

    // Destroy window
    glfwDestroyWindow(window->handler);
    glfwTerminate();

    return 0;
}

void size_callback(GLFWwindow *, int width, int height)
{
    glViewport(0, 0, width, height);
}

void scroll_callback(GLFWwindow *, double, double yOffset)
{
    camera->processScroll((GLfloat)yOffset);
}

void mouse_callback(GLFWwindow *, double xPosIn, double yPosIn)
{

    GLfloat xPos;
    GLfloat yPos;

    xPos = (GLfloat)xPosIn;
    yPos = (GLfloat)yPosIn;

    if (firstMouse)
    {
        lastX = xPos;
        lastY = yPos;

        firstMouse = false;
    }

    GLfloat xOffset = xPos - lastX;
    GLfloat yOffset = lastY - yPos;

    lastX = xPos;
    lastY = yPos;

    // Process mouse movements
    camera->processMouse(xOffset, yOffset);
}

void key_callback(GLFWwindow *win, int key, int, int action, int)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(win, true);
                break;

            case GLFW_KEY_Z:
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                break;

            case GLFW_KEY_F:
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                break;

            default:
                break;
        }
    }
}

void processInputs(GLFWwindow *win)
{
    // Close the window
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(win, true);
    }
    // Forward movement
    if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera->processKeyboard(FORWARD, deltaTime);
    }
    // Backward movement
    if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera->processKeyboard(BACKWARD, deltaTime);
    }
    // Right movement
    if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera->processKeyboard(RIGHT, deltaTime);
    }
    // Left movement
    if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera->processKeyboard(LEFT, deltaTime);
    }
    // Up movement
    if (glfwGetKey(win, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        camera->processKeyboard(UP, deltaTime);
    }
    // Down movement
    if (glfwGetKey(win, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        camera->processKeyboard(DOWN, deltaTime);
    }
}