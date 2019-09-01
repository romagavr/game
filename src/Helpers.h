#ifndef HELPERS
#define HELPERS

#define GLFW_INCLUDE_GLU
#include <GL/glew.h>

#define OFFSETOF(TYPE, FIELD) ((void*)&(((TYPE*)NULL)->FIELD))
#define STRINGIFY_SHADER(TEXT) ("#version 120\n "#TEXT)
#define CHECK_GL_ERRORS() checkOpenGLerror(__FILE__, __LINE__)

typedef unsigned int uint;

int checkOpenGLerror(const char *file, int line);
void glDebugOut(uint source, uint type, uint id, uint severity, int length, const char* message, void* userParam);


#endif
