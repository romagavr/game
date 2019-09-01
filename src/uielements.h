#ifndef UIELEMENTS_H
#define UIELEMENTS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "Helpers.h"
#include "vertex2d.h"
#include "PngLoader.h"
#include "shader2d.h"

using namespace std;
using namespace glm;

class UIElements
{
private:
    int triangleVertexCount;
    GLuint VAO, VBO;
    GLuint textures;
    GLuint shaderProgram;
    ImageData texture();
    double PosX, PosY;
    double PosXMove, PosYMove;
    double ScaleX, ScaleY;
    mat4 MVP;
public:
    UIElements(const char* str, double posX, double posY, double scaleX, double scaleY);
    void draw();
    bool isMe(double posX, double posY);
    void move(double posX, double posY);
};

#endif // UIELEMENTS_H
