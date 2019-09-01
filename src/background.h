#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Vertex.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>     // Непосредственно сам GLFW
#include <glm.hpp>          // библиотека графической математики
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "Helpers.h"
#include "vertex2d.h"
#include "PngLoader.h"
#include "shader2d.h"

using namespace std;
using namespace glm;

class BackGround
{
private:
    int triangleVertexCount;
    GLuint VAO, VBO;
    GLuint textures;
    GLuint shaderProgram;
    ImageData texture();
    double PosY;
    double PosYMove, PosXMove;
    double ScaleX, ScaleY;
public:
    BackGround(char* str, double posY);
    void draw();
    void move(double posY, double posX);
    void resetScale(double scaleX, double scaleY);
};

#endif // BACKGROUND_H
