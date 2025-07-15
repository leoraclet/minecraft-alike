#ifndef EBO_H
#define EBO_H

/*
 * @brief: Element Buffer Object
 */

class EBO
{
private:
    // ID reference of the EBO
    GLuint ID;
public:
    // Class constructor
    explicit EBO(std::vector<GLuint> &indices);

    void bind() const;
    void remove() const;

    static void unbind();
};

#endif // EBO_H
