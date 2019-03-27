#ifndef FIGURES_H
#define FIGURES_H

#include <glm.hpp>
#include "Vertex.h"

using namespace glm;

// данные о вершинах
int triangleVertexCount = 36;
Vertex triangleVertexes[] = {
   //                ВЕРШИНА                   ЦВЕТ
   Vertex(vec3( -0.5f,  -0.5f,  -0.5f),    vec3(0.583f, 0.771f, 0.014f),  vec2(1.0f, 0.0f)),
   Vertex(vec3( -0.5f,   0.5f,  -0.5f),    vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 0.0f)),
   Vertex(vec3( -0.5f, 0.5f,  0.5f),       vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 1.0f)),

   Vertex(vec3( -0.5f,  0.5f,  0.5f),      vec3(0.583f, 0.771f, 0.014f),  vec2(1.0f, 0.0f)),
   Vertex(vec3( -0.5f,  -0.5f,  0.5f),     vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 0.0f)),
   Vertex(vec3( -0.5f, -0.5f,  -0.5f),     vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 1.0f)),

   Vertex(vec3( 0.5f,  -0.5f,  -0.5f),     vec3(0.583f, 0.771f, 0.014f),     vec2(1.0f, 0.0f)),
   Vertex(vec3( 0.5f,   0.5f,  -0.5f),     vec3(0.583f, 0.771f, 0.014f),     vec2(0.0f, 0.0f)),
   Vertex(vec3( 0.5f, 0.5f,  0.5f),        vec3(0.583f, 0.771f, 0.014f),     vec2(0.0f, 1.0f)),

   Vertex(vec3( 0.5f,  0.5f,  0.5f),       vec3(0.583f, 0.771f, 0.014f),     vec2(1.0f, 0.0f)),
   Vertex(vec3(0.5f,  -0.5f,  0.5f),       vec3(0.583f, 0.771f, 0.014f),     vec2(0.0f, 0.0f)),
   Vertex(vec3( 0.5f, -0.5f,  -0.5f),      vec3(0.583f, 0.771f, 0.014f),     vec2(0.0f, 1.0f)),

   Vertex(vec3( -0.5f, -0.5f,  0.5f),      vec3(0.583f, 0.771f, 0.014f), vec2(0.0f, 1.0f)),
   Vertex(vec3( -0.5f,  -0.5f,  -0.5f),    vec3(0.583f, 0.771f, 0.014f), vec2(0.0f, 0.0f)),
   Vertex(vec3(0.5f,  -0.5f,  -0.5f),      vec3(0.583f, 0.771f, 0.014f), vec2(1.0f, 0.0f)),

   Vertex(vec3(-0.5f,  -0.5f,  0.5f),  vec3(0.583f, 0.771f, 0.014f),  vec2(1.0f, 0.0f)),
   Vertex(vec3(0.5f,  -0.5f,  -0.5f),   vec3(0.583f, 0.771f, 0.014f), vec2(0.0f, 1.0f)),
   Vertex(vec3(0.5f,  -0.5f,  0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 0.0f)),

  Vertex(vec3( -0.5f, 0.5f,  0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 1.0f)),
  Vertex(vec3( -0.5f,  0.5f,  -0.5f),  vec3(0.583f, 0.771f, 0.014f), vec2(0.0f, 0.0f)),
   Vertex(vec3(0.5f,  0.5f,  -0.5f),   vec3(0.583f, 0.771f, 0.014f), vec2(1.0f, 0.0f)),

   Vertex(vec3(-0.5f, 0.5f,  0.5f),  vec3(0.583f, 0.771f, 0.014f),   vec2(1.0f, 0.0f)),
   Vertex(vec3(0.5f,  0.5f,  -0.5f),   vec3(0.583f, 0.771f, 0.014f), vec2(0.0f, 1.0f)),
   Vertex(vec3(0.5f,  0.5f,  0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 0.0f)),

   Vertex(vec3( 0.5f, -0.5f,  -0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 1.0f)),
   Vertex(vec3( -0.5f,  -0.5f,  -0.5f),  vec3(0.583f, 0.771f, 0.014f), vec2(0.0f, 0.0f)),
   Vertex(vec3(-0.5f,  0.5f,  -0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(1.0f, 0.0f)),

   Vertex(vec3(-0.5f,  0.5f,  -0.5f),   vec3(0.583f, 0.771f, 0.014f), vec2(0.0f, 1.0f)),
   Vertex(vec3(0.5f,  0.5f,  -0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 0.0f)),
   Vertex(vec3(0.5f, -0.5f,  -0.5f),  vec3(0.583f, 0.771f, 0.014f),   vec2(1.0f, 0.0f)),

   Vertex(vec3( 0.5f, -0.5f,  0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(1.0f, 0.0f)),
   Vertex(vec3( -0.5f,  -0.5f,  0.5f),  vec3(0.583f, 0.771f, 0.014f), vec2(0.0f, 0.0f)),
   Vertex(vec3(-0.5f,  0.5f,  0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 1.0f)),

   Vertex(vec3(0.5f, -0.5f,  0.5f),  vec3(0.583f, 0.771f, 0.014f),   vec2(0.0f, 1.0f)),
   Vertex(vec3(-0.5f,  0.5f,  0.5f),   vec3(0.583f, 0.771f, 0.014f), vec2(1.0f, 0.0f)),
   Vertex(vec3(0.5f,  0.5f,  0.5f),   vec3(0.583f, 0.771f, 0.014f),  vec2(0.0f, 0.0f))
};

#endif
