// Libs
#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
// Local
#include "camera.h"


/*
 * @brief: Create a new camera
 *
 * @param width    : Window width
 * @param height   : Window height
 * @param position : Camera position
 */

Camera::Camera(GLint width, GLint height, glm::vec3 position)
{
    this->width = width;
    this->height = height;
    this->Position = position;
}

/*
 * @brief: Updates camera vectors
 */

void Camera::updateVectors()
{
    // New camera front vector
    glm::vec3 newFront;

    // Calculate new front vector coordinates
    newFront.x = (float)(cos(glm::radians(Yaw)) * cos(glm::radians(Pitch)));
    newFront.y = (float)(sin(glm::radians(Pitch)));
    newFront.z = (float)(sin(glm::radians(Yaw)) * cos(glm::radians(Pitch)));

    // Assign the new Front vector to the camera Front vector
    Front = glm::normalize(newFront);

    // Calculate Right and Up vectors from the new Front vector
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}

/*
 * @brief: Makes camera look in the right direction from the right position
 *
 * @return: View matrix as a 4D matrix
 */

glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(Position, Position + Front, Up);
}

/*
 * @brief: Adds perspective to the scene
 *
 * @param nearPlane : Distance from the viewer to the near clipping plane
 * @param farPlane  : Distance from the viewer to the far clipping plane
 *
 * @return: Projection matrix as a 4D matrix
 */

glm::mat4 Camera::getProjectionMatrix(GLfloat nearPlane, GLfloat farPlane) const
{
    return glm::perspective(
        glm::radians(Zoom),
        (float)width / (float)height,
        nearPlane, farPlane
    );
}
