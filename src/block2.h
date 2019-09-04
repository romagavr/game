#ifndef BLOCK2_H
#define BLOCK2_H

#include "Vertex.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>     // Непосредственно сам GLFW
#include <glm.hpp>          // библиотека графической математики
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "Helpers.h"
#include "Vertex.h"
#include "PngLoader.h"
#include "Shaders.h"
#include<vector>

using namespace std;
using namespace glm;

class Block2
{
private:
    int triangleVertexCount;
    double posX, posY, posZ;
    GLuint VAO, VBO;
    GLuint textures[6];
    GLuint shaderProgram;
    ImageData texture();
    void genTextures();
    vector<char *> blockTex;
public:
    Block2();
    void draw(float anglex, float angley, float anglez, double PosX, double PosY, double ScValue);
    void setCoords(double PosX, double PosY,double PosZ);
    void changeCoords(double delY);
    void drawStatic();
    virtual ~Block2(){}
};

#endif // BLOCK2_H
