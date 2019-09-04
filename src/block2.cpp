#include "block2.h"

Block2::Block2()
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
