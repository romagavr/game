#include "gamewindow.h"

GameWindow::GameWindow()
{
    isBlockFall = false;
    posX =0; posY=0;
    towerHieght = -0.77; //-0.87
    isMoveBackGr = false;
    countOfBlocks = 0;
    countOfBckg = 0;
    isGameOver = false;
    gamePoints = 0;
    BLOCKS_AMOUNT = 50;

    line = new Line();
    generateNumber = new GenNumber();
    generateTimerNumber = new GenNumber();
    backGrItems.push_back(new BackGround("/home/roman/Desktop/OpenGL_Practice_FULL/res/BackGround/Background2.png", 538*1.3));
    backGrItems.push_back(new BackGround("/home/roman/Desktop/OpenGL_Practice_FULL/res/BackGround/Floor.png", 0));
    backGrItems.push_back(new BackGround("/home/roman/Desktop/OpenGL_Practice_FULL/res/BackGround/first.png", 0));
    backGrItems[1]->resetScale(3,1);
    backGrItems[1]->move(0,133);

    userUI.push_back(new UIElements("/home/roman/Desktop/OpenGL_Practice_FULL/res/Menu/Game_time.png",0,600,3.5,1.5));
    userUI.push_back(new UIElements("/home/roman/Desktop/OpenGL_Practice_FULL/res/Menu/Game_Points.png",3,550,3.5,1.3));

    heapOfBlocks.resize(BLOCKS_AMOUNT);
    for (int i=0; i<heapOfBlocks.size(); i++)
        heapOfBlocks[i] = new Block();
}

void GameWindow::drawPoints(int points)
{
    generateNumber->getNumber(points,num,false);
    for (auto number : num)
    {
        number->move(170,570);
        number->draw();
    }
}

void GameWindow::drawTime(int time)
{
    generateTimerNumber->getNumber(time,numTime,true);
    for (auto number : numTime)
    {
        number->move(170,625);
        number->draw();
    }
}

void GameWindow::calcGamePionts(double delPos)
{
    if (delPos < 0.01)
    {
        gamePoints +=1000;
        return;
    }
    if (delPos < 0.1)
    {
        gamePoints +=500;
        return;
    }
    if (delPos < 0.15)
    {
        gamePoints +=250;
        return;
    }
    if (delPos >= 0.15)
    {
        gamePoints +=100;
        return;
    }
}

void GameWindow::drawGame(bool isSpaceClicked, double time)
{
    drawPoints(gamePoints);
    drawTime(time);
    for (auto elements : userUI)
        elements->draw();
    if (!isBlockFall)
    {
        posX = 0-0.5*sin(time*BLOCK_MOVING_SPEED);
        posY = 0.3-0.15*cos(time*BLOCK_MOVING_SPEED);
    } else
    {
        posY -= BLOCK_FALLING_SPEED;
        if (posY < towerHieght)
        {
            posY = towerHieght;
            heapOfBlocks[countOfBlocks]->setCoords(posX,posY,0);
            if (countOfBlocks == 0)
                blockPosX = posX;
            else
            {
                if (abs(posX - blockPosX) > 0.2)
                {
                    isGameOver = true;
                    return;
                }
                calcGamePionts(abs(posX - blockPosX));
                blockPosX = posX;
            }
            if ((countOfBlocks+1) == BLOCKS_AMOUNT)
            {
                isGameOver = true;
                return;
            }
            countOfBlocks++;
            towerHieght += 0.2;
            isBlockFall = false;
            if (towerHieght > 0)
                isMoveBackGr = true;

        }
    }
    if (isMoveBackGr)
    {
        for(int i=0; i<countOfBlocks; i++)
            heapOfBlocks[i]->changeCoords(0.007);
        for (auto backGr : backGrItems)
            backGr->move(-1,0);
        for (auto number : numTime)
            number->move(0,0.007);
        for (auto number : num)
            number->move(0,0.007);
        for (auto elements : userUI)
            elements->move(0,0.007);
        countOfBckg++;
        if (countOfBckg==100)
        {
            countOfBckg=0;
            towerHieght -= 0.7;
            isMoveBackGr = false;
        }
    }

    if (!isBlockFall)
        line->draw(posX,posY,1.0f);
    else
        line->draw(0,0.5,1.0);
    for (auto backGr : backGrItems)
        backGr->draw();


    heapOfBlocks[countOfBlocks]->draw(1,1,1,posX,posY,1);
    for(int i=0; i<countOfBlocks; i++)
    {
//        glEnable(GL_DEPTH_TEST);
//        glDepthFunc(GL_ALWAYS);
//        glDepthMask(GL_FALSE);
        heapOfBlocks[i]->drawStatic();
//        glDepthMask(GL_TRUE);
//        glDepthFunc(GL_LESS);
    }

    if (isSpaceClicked && !isMoveBackGr)
        isBlockFall = true;
}
