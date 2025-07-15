/*
 * The camera class simulate the player point
 * of view in openGL 3D space by moving the scene
 * according to the user perspective. Player view
 * is calculated using vectors thanks to GML.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


enum Movements {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
};


class Camera {

public:

    // Attributes
    glm::vec3 Position{};
    glm::vec3 Front{};
    glm::vec3 Up{};
    glm::vec3 Right{};
    glm::vec3 WorldUp{};

    // Euler angles
    GLfloat Yaw;
    GLfloat Pitch;

    // Parameters
    GLfloat MovementSpeed;
    GLfloat MouseSensitivity;
    GLfloat Zoom;

    // Class constructor
    explicit Camera(
        glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 up = glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f),
        glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3 right = glm::vec3(0.0f, 0.0f, 0.0f),
        GLfloat yaw = -90.0f,
        GLfloat pitch = 0.0f,
        GLfloat movementSpeed = 2.5f,
        GLfloat mouseSensitivity = 0.1f,
        GLfloat zoom = 45.0f
    ){
        Position = position;
        Up = up;
        Front = front;
        WorldUp = worldUp;
        Right = right;
        Yaw = yaw;
        Pitch = pitch;
        MovementSpeed = movementSpeed;
        MouseSensitivity = mouseSensitivity;
        Zoom = zoom;
    };

    // Camera view matrix
    glm::mat4 getViewMatrix() const;

    // Process keyboard and mouse inputs
    void processKeyboard(Movements direction, GLfloat deltaTime);
    void processScroll(GLfloat yOffset);
    void processMouse(GLfloat xOffset, GLfloat yOffset);

private:

    // Update the camera vectors
    void updateVectors();

};

#endif // CAMERA_H
