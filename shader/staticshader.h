#ifndef STATICSHADER_H
#define STATICSHADER_H
#include <GL/glew.h>
#include <iostream>
#include "util/matrix.h"
#include "entity/camera.h"

class StaticShader
{
public:
    StaticShader(GLuint program);
    void loadTransformMatrix(util::Matrix transformation);
    void loadprojectMatrix(util::Matrix projection);
    void loadviewMatrix(Camera &view);
private:
    GLuint loc_transformMatrix;
    GLuint loc_projectMatrix;
    GLuint loc_viewMatrix;
    GLuint program;
};

#endif // STATICSHADER_H
