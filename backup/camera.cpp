#include "camera.h"


/*
 * Update camera vectors
 */

void Camera::updateVectors()
{
    glm::vec3 newFront;

    // Calculate new Front vector
    newFront.x = (float)(cos(glm::radians(Yaw)) * cos(glm::radians(Pitch)));
    newFront.y = (float)(sin(glm::radians(Pitch)));
    newFront.z = (float)(sin(glm::radians(Yaw)) * cos(glm::radians(Pitch)));

    // Assign the new Front vector
    Front = glm::normalize(newFront);

    // Re-calculate Right and Up vectors
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}

/*
 * Return the view matrix calculated using Euler
 * angles and the LookAt matrice
 */

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(Position, Position + Front, Up);
}

/*
 * Process mouse movement inputs
 */

void Camera::processMouse(GLfloat xOffset, GLfloat yOffset)
{
    xOffset *= MouseSensitivity;
    yOffset *= MouseSensitivity;

    Yaw += xOffset;
    Pitch += yOffset;

    // Check Pitch bounds
    if (Pitch > 89.0f)
    {
        Pitch = 89.0f;
    }
    if (Pitch < -89.0f)
    {
        Pitch = -89.0f;
    }

    // Update vectors
    updateVectors();
}

/*
 * Process scroll inputs
 */

void Camera::processScroll(GLfloat yOffset)
{
    Zoom -= yOffset;

    // Check Zoom bounds
    if (Zoom < 1.0f)
    {
        Zoom = 1.0f;
    }
    if (Zoom > 45.0f)
    {
        Zoom = 45.0f;
    }

}

/*
 * Process keyboard inputs
 */

void Camera::processKeyboard(Movements direction, GLfloat deltaTime)
{
    // Calculate velocity
    GLfloat velocity = MovementSpeed * deltaTime;

    // update position according to direction
    switch (direction) {

        case FORWARD:
            Position += Front * velocity;
            break;

        case BACKWARD:
            Position -= Front * velocity;
            break;

        case LEFT:
            Position -= Right * velocity;
            break;

        case RIGHT:
            Position += Right * velocity;
            break;

        case UP:
            Position += Up * velocity;
            break;

        case DOWN:
            Position -= Up * velocity;
            break;

        default:
            break;
    }
}
