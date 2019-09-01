#ifndef SHADERS_H
#define SHADERS_H

#include <GL/glew.h>

GLuint createShader();
GLuint createShaderFromSources(const char* vertexShader, const char* fragmentShader);

#endif
