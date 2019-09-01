#include "Shaders.h"
#include "Helpers.h"


GLuint createShaderFromSources(const char* vertexShader, const char* fragmentShader){
    GLuint vs = glCreateShader (GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShader, NULL);
    glCompileShader(vs);
    CHECK_GL_ERRORS();

    GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShader, NULL);
    glCompileShader(fs);
    CHECK_GL_ERRORS();

    GLuint shaderProgram = glCreateProgram ();
    glAttachShader(shaderProgram, fs);
    glAttachShader(shaderProgram, vs);
    glLinkProgram(shaderProgram);
    CHECK_GL_ERRORS();

    return shaderProgram;
}

GLuint createShader(){
    const char* vertexShader = STRINGIFY_SHADER(
        attribute vec3 aPos;
        attribute vec2 aUV;
        uniform mat4 uModelViewProjMat;
        varying vec2 vUV;

        void main () {
            vec4 vertexVec4 = vec4(aPos, 1.0);
            gl_Position = uModelViewProjMat * vertexVec4;
            vUV = aUV;
        }
    );
    const char* fragmentShader = STRINGIFY_SHADER(
        varying vec2 vUV;

       uniform sampler2D uTexture;
       void main () {
            vec4 color= texture2D(uTexture, vUV);
            if (color.a < 0.1) discard;
            gl_FragColor =color; //vec4(vColor, 1.0);

        }
    );

    GLuint shader = createShaderFromSources(vertexShader, fragmentShader);
    CHECK_GL_ERRORS();
    return shader;
}

