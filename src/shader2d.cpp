#include "shader2d.h"
#include "Helpers.h"


GLuint createShaderFromSources2D(const char* vertexShader, const char* fragmentShader){
    GLuint vs2 = glCreateShader (GL_VERTEX_SHADER);
    CHECK_GL_ERRORS();
    glShaderSource(vs2, 1, &vertexShader, NULL);
    CHECK_GL_ERRORS();
    glCompileShader(vs2);
    CHECK_GL_ERRORS();

    GLuint fs2 = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource(fs2, 1, &fragmentShader, NULL);
    glCompileShader(fs2);
    CHECK_GL_ERRORS();

    GLuint shaderProgram = glCreateProgram ();
    glAttachShader(shaderProgram, fs2);
    glAttachShader(shaderProgram, vs2);
    glLinkProgram(shaderProgram);
    CHECK_GL_ERRORS();

    return shaderProgram;
}

GLuint createShader2D(){
    const char* vertexShader = STRINGIFY_SHADER(
        attribute vec2 aPos;
        attribute vec2 aUV;
        uniform mat4 uModelViewProjMat;
        varying vec2 vUV;

        void main () {
            vec4 vertexVec4 = vec4(aPos,0.0, 1.0);
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

    GLuint shader = createShaderFromSources2D(vertexShader, fragmentShader);
    CHECK_GL_ERRORS();
    return shader;
}

