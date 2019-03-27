#ifndef VERTEX2D_H
#define VERTEX2D_H


#include <glm.hpp>

using namespace glm;

struct Vertex2D{
    vec2 pos;
    vec2 UVCoord;

    // constructor
    Vertex2D(vec2 inPos, vec2 UVCoord);
};

#endif // VERTEX2D_H
