#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
private:
    // Camera vectors
    glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 Front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 Up = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 Right = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

    // Euler angles
    GLfloat Yaw = -90.0;
    GLfloat Pitch = 0.0;

    // Camera settings
    GLfloat MovementSpeed = 2.5;
    GLfloat MouseSensitivity = 0.1;
    GLfloat Zoom = 45.0;

    // Window size
    GLint width;
    GLint height;

    // Update camera vectors
    void updateVectors();

public:
    // Class constructor
    Camera(GLint width, GLint height, glm::vec3 position);

    // Getters
    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix(GLfloat nearPlane, GLfloat farPlane) const;

};

#endif // CAMERA_H
