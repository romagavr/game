#ifndef LINE_H
#define LINE_H

#include "Vertex.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "Helpers.h"
#include "vertex2d.h"
#include "PngLoader.h"
#include "shader2d.h"
#include "math.h"

using namespace std;
using namespace glm;


class Line
{
private:
    int triangleVertexCount;
    GLuint VAO, VBO;
    GLuint textures;
    GLuint shaderProgram;
    ImageData texture();
public:
    Line();
    void draw(float posX, float posY, float alpha);
};

#endif // LINE_H
