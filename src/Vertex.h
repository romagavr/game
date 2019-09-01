#ifndef VERTEX_H
#define VERTEX_H

#include <glm.hpp>

using namespace glm;

struct Vertex{
    vec3 pos;
    vec2 UVCoord;

    // constructor
    Vertex(vec3 inPos, vec2 UVCoord);
};

#endif
