#ifndef VBO_H
#define VBO_H

#include "glm/ext/vector_float3.hpp"
#include "glm/ext/vector_float2.hpp"
#include <glad/glad.h>
#include <vector>

/*
 * @brief: Standardized vertices structure
 */

struct Vertex
{
    glm::vec3 position; // Position coordinates
    glm::vec3 normal;   // Normal coordinates
    glm::vec3 color;    // Color coordinates
    glm::vec2 texUV;    // Texture coordinates
};

/*
 * @brief: Vertex Buffer Object
 */

class VBO
{
private:
    // ID reference of the VBO
    GLuint ID = 0;
public:
    // Class constructor
    explicit VBO(std::vector<Vertex> &vertices);

    void bind() const;
    void remove() const;

    static void unbind();

};

#endif // VBO_H
