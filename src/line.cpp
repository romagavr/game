#include "line.h"

Line::Line()
{
    triangleVertexCount = 2;
    Vertex2D triangleVertexes[] = {
        Vertex2D(vec2( 0.0f, 1.0f),   vec2(0.0f, 0.0f)),
        Vertex2D(vec2( 0.0f,  0.0f),   vec2(0.0f, 1.0f)),

    };


    shaderProgram = createShader2D();
    CHECK_GL_ERRORS();
    int posAttribLocation = glGetAttribLocation(shaderProgram, "aPos");
    int uvAttribLocation = glGetAttribLocation(shaderProgram, "aUV");

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

    ImageData texture = loadPngImage("/home/roman/Desktop/OpenGL_Practice_FULL/res/test.png");
    glGenTextures(1, &textures);
    glBindTexture(GL_TEXTURE_2D, textures);
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, texture.width, texture.height,0, GL_RGBA, GL_UNSIGNED_BYTE, texture.data);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Line::draw(float posX, float posY, float alpha)
{
    int modelViewProjMatrixLocation = glGetUniformLocation(shaderProgram, "uModelViewProjMat");
    int TextureLocation = glGetUniformLocation(shaderProgram,"uTexture");

    Vertex2D triangleVertexes[] = {
        Vertex2D(vec2( 0.0f, 1.0f),  vec2(0.0f, 0.0f)),
        Vertex2D(vec2( posX,  posY),  vec2(0.0f, 1.0f)),

    };
    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER,0,2*sizeof(Vertex2D),triangleVertexes);

    glUseProgram (shaderProgram);
    glUniform1i(TextureLocation, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures);

    mat4 Translate = translate(mat4(1.0), vec3(0,0.0,0.0));
    mat4 Scale = scale(mat4(1.0), vec3(1.0f,1.0f,1.0f));
    mat4 RotateX = rotate(mat4(1.0),0.f, vec3(1.0,0.0,0.0));
    mat4 RotateY = rotate(mat4(1.0),0.0f, vec3(0.0,1.0,0.0));
    mat4 MVP = Translate*RotateX*RotateY*Scale;
    glUniformMatrix4fv(modelViewProjMatrixLocation, 1,false, glm::value_ptr(MVP));

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, triangleVertexCount);
    glBindVertexArray(0);
}
