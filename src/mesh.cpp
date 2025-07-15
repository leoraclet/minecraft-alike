// C++
#include <vector>
// Libs
#include <glad/glad.h>
// Local
#include "shader.h"
#include "vbo.h"
#include "vao.h"
#include "ebo.h"
#include "texture.h"
#include "mesh.h"


/*
 * @brief: Create a new Mesh
 *
 * @param vertices : Mesh vertices
 * @param indices  : Mesh indices
 * @param textures : Mesh textures
 */

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, std::vector<Texture> &textures)
{
    Mesh::vertices = vertices;
    Mesh::indices = indices;
    Mesh::textures = textures;

    // Binds the VAO
    vao.bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO vbo(vertices);
    // Generates Element Buffer Object and links it to indices
    EBO ebo(indices);

    // Links VBO attributes to the VAO
    vao.link_attrib(vbo, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)(nullptr));
    vao.link_attrib(vbo, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
    vao.link_attrib(vbo, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
    vao.link_attrib(vbo, 3, 2, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));

    // Unbind all buffers
    vao.unbind();
    vbo.unbind();
    ebo.unbind();
}

/*
 * @brief: Draw the Mesh to screen via the Shader
 *
 * @param shader: Shader program reference
 */

void Mesh::draw(Shader &shader)
{

}
