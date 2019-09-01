#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>     // Непосредственно сам GLFW
#include <glm.hpp>          // библиотека графической математики
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "Helpers.h"
#include "block.h"
#include "line.h"
#include "background.h"
#include "uielements.h"
#include "gennumber.h"
#include <vector>
#include<iostream>


#define BLOCK_MOVING_SPEED 2
#define BLOCK_FALLING_SPEED 0.03

using namespace std;
using namespace glm;

class GameWindow
{
private:
    vector<Block *>  heapOfBlocks;
    vector<BackGround *> backGrItems;
    vector<UIElements *> userUI;
    vector<UIElements *> num;
    vector<UIElements *> numTime;
    Line * line;
    GenNumber *generateNumber;
    GenNumber *generateTimerNumber;

    int gamePoints;
    double blockPosX;
    double posX;
    double posY;
    bool isBlockFall;
    bool isMoveBackGr;
    int countOfBckg;
    double towerHieght;
    void drawPoints(int points);
    void drawTime(int time);
    void calcGamePionts(double delPos);

public:
    GameWindow();
    bool isGameOver;
    void drawGame(bool isSpaceClicked, double time);
    int BLOCKS_AMOUNT;
    int countOfBlocks;
    ~GameWindow(){

    }
};

#endif // GAMEWINDOW_H
