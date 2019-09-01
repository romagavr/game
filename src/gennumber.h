#ifndef GENNUMBER_H
#define GENNUMBER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>     // Непосредственно сам GLFW
#include <glm.hpp>          // библиотека графической математики
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include "Helpers.h"
#include "vertex2d.h"
#include "PngLoader.h"
#include "shader2d.h"
#include <vector>
#include <string>
#include "uielements.h"

using namespace std;
using namespace glm;
class GenNumber
{
private:
    void getVector(int number, vector<int> &vecNumber);
    void getTimeVector(int number, vector<int> &vecNumber);
public:
    GenNumber();
    void getNumber(int number, vector<UIElements*> &vecElements, bool isTime);
};

#endif // GENNUMBER_H
