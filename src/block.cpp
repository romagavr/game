#include "block.h"

Block::Block()
{

    triangleVertexCount = 36;
    Vertex triangleVertexes[] = {
        Vertex(vec3( -0.5f,  -0.5f,  -0.5f),      vec2(1.0f, 0.0f)),
        Vertex(vec3( -0.5f,   0.5f,  -0.5f),      vec2(0.0f, 0.0f)),
        Vertex(vec3( -0.5f, 0.5f,  0.5f),         vec2(0.0f, 1.0f)),

        Vertex(vec3( -0.5f,  0.5f,  0.5f),        vec2(1.0f, 0.0f)),
        Vertex(vec3( -0.5f,  -0.5f,  0.5f),     vec2(0.0f, 0.0f)),
        Vertex(vec3( -0.5f, -0.5f,  -0.5f),      vec2(0.0f, 1.0f)),

        Vertex(vec3( 0.5f,  -0.5f,  -0.5f),       vec2(1.0f, 0.0f)),
        Vertex(vec3( 0.5f,   0.5f,  -0.5f),        vec2(0.0f, 0.0f)),
        Vertex(vec3( 0.5f, 0.5f,  0.5f),           vec2(0.0f, 1.0f)),

        Vertex(vec3( 0.5f,  0.5f,  0.5f),          vec2(1.0f, 0.0f)),
        Vertex(vec3(0.5f,  -0.5f,  0.5f),          vec2(0.0f, 0.0f)),
        Vertex(vec3( 0.5f, -0.5f,  -0.5f),         vec2(0.0f, 1.0f)),

        Vertex(vec3( 0.5f, -0.5f,  -0.5f),      vec2(1.0f, 1.0f)),
        Vertex(vec3( -0.5f,  -0.5f,  -0.5f),     vec2(0.0f, 1.0f)),
        Vertex(vec3(-0.5f,  -0.5f,  0.5f),      vec2(0.0f, 0.0f)),

        Vertex(vec3(-0.5f,  -0.5f,  0.5f),   vec2(1.0f, 0.0f)),
        Vertex(vec3(0.5f,  -0.5f,  -0.5f),   vec2(0.0f, 1.0f)),
        Vertex(vec3(0.5f,  -0.5f,  0.5f),    vec2(0.0f, 0.0f)),

       Vertex(vec3( -0.5f, 0.5f,  0.5f),    vec2(0.0f, 1.0f)),
       Vertex(vec3( -0.5f,  0.5f,  -0.5f),  vec2(0.0f, 0.0f)),
        Vertex(vec3(0.5f,  0.5f,  -0.5f),  vec2(1.0f, 0.0f)),

        Vertex(vec3(-0.5f, 0.5f,  0.5f),    vec2(1.0f, 0.0f)),
        Vertex(vec3(0.5f,  0.5f,  -0.5f),    vec2(0.0f, 1.0f)),
        Vertex(vec3(0.5f,  0.5f,  0.5f),    vec2(0.0f, 0.0f)),

        Vertex(vec3( 0.5f, -0.5f,  -0.5f),    vec2(0.0f, 1.0f)),
        Vertex(vec3( -0.5f,  -0.5f,  -0.5f),  vec2(0.0f, 0.0f)),
        Vertex(vec3(-0.5f,  0.5f,  -0.5f),    vec2(1.0f, 0.0f)),

        Vertex(vec3(-0.5f,  0.5f,  -0.5f),   vec2(0.0f, 1.0f)),
        Vertex(vec3(0.5f,  0.5f,  -0.5f),    vec2(0.0f, 0.0f)),
        Vertex(vec3(0.5f, -0.5f,  -0.5f),   vec2(1.0f, 0.0f)),

        Vertex(vec3( 0.5f, -0.5f,  0.5f),    vec2(1.0f, 0.0f)),
        Vertex(vec3( -0.5f,  -0.5f,  0.5f),  vec2(0.0f, 0.0f)),
        Vertex(vec3(-0.5f,  0.5f,  0.5f),    vec2(0.0f, 1.0f)),

        Vertex(vec3(0.5f, -0.5f,  0.5f),    vec2(0.0f, 1.0f)),
        Vertex(vec3(-0.5f,  0.5f,  0.5f),  vec2(1.0f, 0.0f)),
        Vertex(vec3(0.5f,  0.5f,  0.5f),   vec2(0.0f, 0.0f)),
    };

    shaderProgram = createShader();
    CHECK_GL_ERRORS();
    int posAttribLocation = glGetAttribLocation(shaderProgram, "aPos");
    int uvAttribLocation = glGetAttribLocation(shaderProgram, "aUV");
    CHECK_GL_ERRORS();

    VBO = 1;
    glGenBuffers (1, &VBO);
    glBindBuffer (GL_ARRAY_BUFFER, VBO);
    glBufferData (GL_ARRAY_BUFFER, triangleVertexCount * sizeof(Vertex), triangleVertexes, GL_STATIC_DRAW);
    CHECK_GL_ERRORS();

    VAO = 1;
    glGenVertexArrays (1, &VAO);
    glBindVertexArray (VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glEnableVertexAttribArray(posAttribLocation);
    glVertexAttribPointer(posAttribLocation, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFFSETOF(Vertex, pos));
    glEnableVertexAttribArray(uvAttribLocation);
    glVertexAttribPointer(uvAttribLocation, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), OFFSETOF(Vertex, UVCoord));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 2);
    glBindVertexArray(0);
    CHECK_GL_ERRORS();
    genTextures();

}

void Block::genTextures()
{

    blockTex.push_back("/home/roman/Documents/Others/game/res/Block/Block_window.png");
    blockTex.push_back("/home/roman/Documents/Others/game/res/Block/Block_balcony.png");
    blockTex.push_back("/home/roman/Documents/Others/game/res/Block/Block_balcony_blue.png");
    blockTex.push_back("/home/roman/Documents/Others/game/res/Block/Block_balcony_red.png");

    glGenTextures(6, textures);

    ImageData texture2 = loadPngImage("/home/roman/Documents/Others/game/res/Block/block.png");
    for (int i=0; i<6; i++)
    {
        if (i==2) continue;
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, texture2.width, texture2.height,0, GL_RGBA, GL_UNSIGNED_BYTE, texture2.data);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    ImageData texture = loadPngImage(blockTex[rand() % 3]);
    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, texture.width, texture.height,0, GL_RGBA, GL_UNSIGNED_BYTE, texture.data);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

void Block::setCoords(double PosX, double PosY, double PosZ)
{
    posX = PosX;
    posY = PosY;
    posZ = PosZ;
}

void Block::changeCoords(double delY)
{
    posY -= delY;
}

void Block::drawStatic()
{
    int modelViewProjMatrixLocation = glGetUniformLocation(shaderProgram, "uModelViewProjMat");
    int TextureLocation = glGetUniformLocation(shaderProgram,"uTexture");


    glUseProgram (shaderProgram);
    glUniform1i(TextureLocation, 0);
    glActiveTexture(GL_TEXTURE);
    glEnable(GL_DEPTH_TEST);

    mat4 Translate = translate(mat4(1.0), vec3(posX,posY,0.0f));
    mat4 Scale = scale(mat4(1.0), vec3(0.34f,0.34f,0.2f));
    mat4 RotateX = rotate(mat4(1.0),1.35f, vec3(1.0,0.0,0.0));
    mat4 RotateY = rotate(mat4(1.0),0.0f, vec3(0.0,1.0,0.0));
    mat4 RotateZ = rotate(mat4(1.0),0.0f, vec3(0.0,0.0,1.0));
    mat4 MVP = Translate*RotateX*RotateY*RotateZ*Scale;

    glUniformMatrix4fv(modelViewProjMatrixLocation, 1,false, glm::value_ptr(MVP));

    glBindVertexArray(VAO);
    for (int i=0; i<6; i++)
    {
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        glDrawArrays(GL_TRIANGLES, 6*i, triangleVertexCount/6);
    }
    glBindVertexArray(0);
}

void Block::draw(float anglex, float angley, float anglez, double PosX, double PosY, double ScValue)
{
    int modelViewProjMatrixLocation = glGetUniformLocation(shaderProgram, "uModelViewProjMat");
    int TextureLocation = glGetUniformLocation(shaderProgram,"uTexture");

    glUseProgram (shaderProgram);
    glUniform1i(TextureLocation, 0);
    glActiveTexture(GL_TEXTURE0);
    glEnable(GL_DEPTH_TEST);

    mat4 Translate = translate(mat4(1.0), vec3(PosX,PosY,0.0f));
    mat4 Scale = scale(mat4(1.0), vec3(0.34f,0.34f,0.2f));
    mat4 RotateX = rotate(mat4(1.0),1.35f, vec3(1.0,0.0,0.0));
    mat4 RotateY = rotate(mat4(1.0),0.f, vec3(0.0,1.0,0.0));
    mat4 RotateZ = rotate(mat4(1.0),0.f, vec3(0.0,0.0,1.0));
    mat4 MVP = Translate*RotateX*RotateY*RotateZ*Scale;

    glUniformMatrix4fv(modelViewProjMatrixLocation, 1,false, glm::value_ptr(MVP));

    glBindVertexArray(VAO);
    for (int i=0; i<6; i++)
    {
        glBindTexture(GL_TEXTURE_2D, textures[i]);
        glDrawArrays(GL_TRIANGLES, 6*i, triangleVertexCount/6);
    }
    glBindVertexArray(0);
}
