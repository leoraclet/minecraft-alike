#ifndef MESH_H
#define MESH_H

/*
 * @brief: Mesh class
 */

class Mesh
{
private:
    std::vector<GLuint> indices;
    std::vector<Vertex> vertices;
    std::vector<Texture> textures;

    VAO vao;
public:
    // Class constructor
    Mesh(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, std::vector<Texture> &textures);

    // Draw the Mesh to the screen
    void draw(Shader &shader);
};

#endif // MESH_H
