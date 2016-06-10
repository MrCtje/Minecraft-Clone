#ifndef ENTITYRENDERER_H
#define ENTITYRENDERER_H
#include <iostream>
#include "entity/entity.h"
#include "util/matrix.h"
#include "models/loader.h"
#include "shader/staticshader.h"
#include "entity/camera.h"
#include "SOIL2.h"

class entityRenderer
{
public:
    entityRenderer(Camera &camera, GLuint program, int &width, int &height);
    ~entityRenderer();
    void render(Camera &cam, entity &en);
    GLuint tex_2d;
private:
    void entityTransformation(entity &en);
    StaticShader* shader;
    GLuint program;
};

#endif // ENTITYRENDERER_H
