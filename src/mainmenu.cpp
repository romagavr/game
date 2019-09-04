#include "mainmenu.h"

MainMenu::MainMenu()
{
    triangleVertexCount = 6;
    Vertex2D triangleVertexes[] = {

        Vertex2D(vec2( 0.0f, 0.0f),    vec2(0.0f, 0.0f)),
        Vertex2D(vec2( 50.0f,  50.0f),  vec2(1.0f, 1.0f)),
        Vertex2D(vec2(0.0f,  50.0f),    vec2(0.0f, 1.0f)),

        Vertex2D(vec2(0.0f, 0.0f),    vec2(0.0f, 0.0f)),
        Vertex2D(vec2(50.0f,  0.0f),    vec2(1.0f, 0.0f)),
        Vertex2D(vec2(50.0f,  50.0f),   vec2(1.0f, 1.0f))
    };

    shaderProgram = createShader2D();
    CHECK_GL_ERRORS();

    int posAttribLocation = glGetAttribLocation(shaderProgram, "aPos");
    int uvAttribLocation = glGetAttribLocation(shaderProgram, "aUV");

    CHECK_GL_ERRORS();

    VBO = 0;
    glGenBuffers (1, &VBO);
    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glBufferData (GL_ARRAY_BUFFER, triangleVertexCount * sizeof(Vertex2D), triangleVertexes, GL_STATIC_DRAW);
    CHECK_GL_ERRORS();

    VAO = 1;
    glGenVertexArrays (1, &VAO);
    glBindVertexArray (VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glEnableVertexAttribArray(posAttribLocation);
    glVertexAttribPointer(posAttribLocation, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), OFFSETOF(Vertex2D, pos));
    glEnableVertexAttribArray(uvAttribLocation);
    glVertexAttribPointer(uvAttribLocation, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), OFFSETOF(Vertex2D, UVCoord));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 2);
    glBindVertexArray(0);
    CHECK_GL_ERRORS();

    ImageData texture = loadPngImage("/home/roman/Documents/Others/game/res/Menu/Main_menu.png");
    glGenTextures(1, &textures);
    glBindTexture(GL_TEXTURE_2D, textures);
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, texture.width, texture.height,0, GL_RGBA, GL_UNSIGNED_BYTE, texture.data);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    UIElements play("/home/roman/Documents/Others/game/res/Menu/Play.png",90,400,5,2);
    menuButtons.push_back(play);
    UIElements resume("/home/roman/Documents/Others/game/res/Menu/Resume.png",90,300,5,2);
    menuButtons.push_back(resume);
    UIElements hscores("/home/roman/Documents/Others/game/res/Menu/High_Scores.png",90,200,5,2);
    menuButtons.push_back(hscores);
    UIElements hToPlay("/home/roman/Documents/Others/game/res/Menu/How_to_Play.png",90,100,5,2);
    menuButtons.push_back(hToPlay);
}

int MainMenu::whatButton(double posX, double posY)
{
    for (int i=0; i<menuButtons.size(); i++)
        if (menuButtons[i].isMe(posX,posY))
        {
            return 4-i;
            break;
        }
    return 0;

}

void MainMenu::draw()
{
    for (auto button : menuButtons)
        button.draw();
    int modelViewProjMatrixLocation = glGetUniformLocation(shaderProgram, "uModelViewProjMat");
    int TextureLocation = glGetUniformLocation(shaderProgram,"uTexture");

    glUseProgram (shaderProgram);
    glUniform1i(TextureLocation, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures);
   // glEnable(GL_DEPTH_TEST);

    mat4 Translate = translate(mat4(1.0), vec3(0,0,0.0));
    mat4 orth = ortho(0.0f, 324.0f*1.3f, 0.0f , 538.0f*1.3f );
    mat4 Scale = scale(mat4(1.0), vec3(8.45f,14.0f,2.0f));
    mat4 RotateX = rotate(mat4(1.0),0.f, vec3(1.0,0.0,0.0));
    mat4 RotateY = rotate(mat4(1.0),0.f, vec3(0.0,1.0,0.0));
    mat4 MVP = orth * Translate*RotateX*RotateY*Scale;
    glUniformMatrix4fv(modelViewProjMatrixLocation, 1,false, glm::value_ptr(MVP));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, triangleVertexCount);
    glBindVertexArray(0);

}
