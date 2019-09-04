#define GLFW_INCLUDE_GLU
#define GLFW_INCLUDE_GL3
#define GLFW_INCLUDE_GLEXT
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "PngLoader.h"
#include "Helpers.h"
#include"gamewindow.h"
#include"mainmenu.h"
#include"uielements.h"


using namespace std;
using namespace glm;

#define MATH_PI 3.14159265

bool escapePressed = false;
bool spacePressed = false;
bool leftButtonPressed = false;
bool rightPressed = false;
double lastCursorPosX = 0.0;
double lastCursorPosY = 0.0;

void glfwErrorCallback(int error, const char* description) {
    printf("OpenGL error = %d\n description = %s\n\n", error, description);
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        escapePressed = true;
    }
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS){
        spacePressed = true;
    }
}

void glfwMouseButtonCallback(GLFWwindow* window, int button, int state, int mod) {
    if(button == GLFW_MOUSE_BUTTON_1){
        if(state == GLFW_PRESS){
            leftButtonPressed = true;
        }else{
            leftButtonPressed = false;
        }
    }
    if(button == GLFW_MOUSE_BUTTON_2){
        if(state == GLFW_PRESS){
            rightPressed = true;
        }else{
            rightPressed = false;
        }
    }
}

void glfwCursorCallback(GLFWwindow* window, double x, double y) {
    lastCursorPosX = x;
    lastCursorPosY = y;
}

void glfwScrollCallback(GLFWwindow* window, double scrollByX, double scrollByY) {
}

int main(int argc, char *argv[]) {

    GLFWwindow* window = 0;
    glfwSetErrorCallback(glfwErrorCallback);
    if (!glfwInit()){
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(324*1.3, 538*1.3, "Tower Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, glfwKeyCallback);
    glfwSetMouseButtonCallback(window, glfwMouseButtonCallback);
    glfwSetCursorPosCallback(window, glfwCursorCallback);
    glfwSetScrollCallback(window, glfwScrollCallback);
    glewExperimental = GL_TRUE;
    glewInit();
    if(glDebugMessageCallback){
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback((GLDEBUGPROC)glDebugOut, 0);
    }
    const unsigned char* version = glGetString(GL_VERSION);
    printf("OpenGL version = %s\n", version);
    int width = 0;
    int height = 0;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    CHECK_GL_ERRORS();

    CHECK_GL_ERRORS();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    CHECK_GL_ERRORS();

    MainMenu menu;
    GameWindow* game = new GameWindow();
    BackGround howToPlay("/home/roman/Documents/Others/game/res/Menu/Menu3.png", 0);
    BackGround gameOver("/home/roman/Documents/Others/game/res/Menu/Game_Over.png", 0);
    BackGround gameWin("/home/roman/Documents/Others/game/res/Menu/Game_Win.png", 0);
    bool menuShow = true;
    int button = 0;
    int overTime = 0;
    double time;


    while (!glfwWindowShouldClose(window)){


        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (menuShow)
            menu.draw();
        if (leftButtonPressed && menuShow)
            button = menu.whatButton(lastCursorPosX, lastCursorPosY);
        switch (button) {
        case 1:
            time = glfwGetTime();
            menuShow = false;
            if (!game->isGameOver)
                game->drawGame(spacePressed,time);
            else
            {
                overTime++;
                if (game->BLOCKS_AMOUNT == game->countOfBlocks+1)
                    gameWin.draw();
                else
                    gameOver.draw();
                if (overTime == 100)
                {
                    overTime = 0;
                    menuShow=true;
                    button=0;
                    game->~GameWindow();
                    game = new GameWindow();
                }
            }
            if (spacePressed)
                spacePressed = false;
            if (escapePressed)
            {
                escapePressed = false;
                button = 0;
                menuShow = true;
            }
            break;
        case 2:
            button = 1;
            break;
        case 4:
            menuShow = false;
            howToPlay.draw();
            if (escapePressed)
            {
                escapePressed = false;
                button = 0;
                menuShow = true;
            }
            break;
        default:
            break;
        }


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
