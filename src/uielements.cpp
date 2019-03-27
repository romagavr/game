#include "uielements.h"

UIElements::UIElements(const char *str, double posX, double posY, double scaleX, double scaleY):
    PosX(posX), PosY(posY), ScaleX(scaleX), ScaleY(scaleY)
{
    PosXMove=0;
    PosYMove=0;
    triangleVertexCount = 6;
    Vertex2D triangleVertexes[] = {

        Vertex2D(vec2( 0.0f, 0.0f),     vec2(0.0f, 0.0f)),
        Vertex2D(vec2( 50.0f,  50.0f),   vec2(1.0f, 1.0f)),
        Vertex2D(vec2(0.0f,  50.0f),    vec2(0.0f, 1.0f)),

        Vertex2D(vec2(0.0f, 0.0f),    vec2(0.0f, 0.0f)),
        Vertex2D(vec2(50.0f,  0.0f),   vec2(1.0f, 0.0f)),
        Vertex2D(vec2(50.0f,  50.0f),    vec2(1.0f, 1.0f))
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

    ImageData texture = loadPngImage(str);
    glGenTextures(1, &textures);
    glBindTexture(GL_TEXTURE_2D, textures);
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, texture.width, texture.height,0, GL_RGBA, GL_UNSIGNED_BYTE, texture.data);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

bool UIElements::isMe(double posX, double posY)
{
    vec4 pos = inverse(MVP)  * vec4(posX,posY,0,1);
    if ((pos.y < PosY + 190) && (pos.y > PosY +110) && (pos.x < PosX + 240) && (pos.x > PosX +5))
        return 1;
    else
        return 0;
}

void UIElements::move(double posX, double posY)
{
    PosXMove += posX;
    PosYMove += posY;
}

void UIElements::draw()
{
    int modelViewProjMatrixLocation = glGetUniformLocation(shaderProgram, "uModelViewProjMat");
    int TextureLocation = glGetUniformLocation(shaderProgram,"uTexture");

    glUseProgram (shaderProgram);
    glUniform1i(TextureLocation, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.8f);
   // glEnable(GL_DEPTH_TEST);

    mat4 Translate = translate(mat4(1.0), vec3(PosX+PosXMove,PosY+PosYMove,0.0));
    mat4 orth = ortho(0.0f, 324.0f*1.3f, 0.0f , 538.0f*1.3f );
    mat4 Scale = scale(mat4(1.0), vec3(ScaleX,ScaleY,2.0f));
    mat4 RotateX = rotate(mat4(1.0),0.f, vec3(1.0,0.0,0.0));
    mat4 RotateY = rotate(mat4(1.0),0.f, vec3(0.0,1.0,0.0));

     MVP = orth * Translate*RotateX*RotateY*Scale;

    glUniformMatrix4fv(modelViewProjMatrixLocation, 1,false, glm::value_ptr(MVP));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, triangleVertexCount); // draw points 0-3 from the currently bound VAO with current in-use shader
    glBindVertexArray(0);
    glDisable(GL_ALPHA_TEST);
}
