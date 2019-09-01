#ifndef MAINMENU_H
#define MAINMENU_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "Helpers.h"
#include "vertex2d.h"
#include "PngLoader.h"
#include "shader2d.h"
#include<vector>
#include"uielements.h"

using namespace std;
using namespace glm;

class MainMenu
{
private:
    int triangleVertexCount;
    GLuint VAO, VBO;
    GLuint textures;
    GLuint shaderProgram;
    ImageData texture();
    vector<UIElements> menuButtons;
public:
    MainMenu();
    void draw();
    int whatButton(double posX, double posY);
};

#endif // MAINMENU_H
