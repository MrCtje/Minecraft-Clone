#include "entityrenderer.h"

entityRenderer::entityRenderer(Camera& camera, GLuint program, int &width, int &height)
{
    this->program = program;
    util::Matrix projectionMatrix = util::CreateProjectionMatrix(70, width/height, .1, 1000);
    shader = new StaticShader(program);
    shader->loadprojectMatrix(projectionMatrix);
    shader->loadviewMatrix(camera);
}

entityRenderer::~entityRenderer()
{
    delete shader;
}

void entityRenderer::render(Camera &cam, entity &en, GLint attrib)
{
    glBindVertexArray(en.getMesh()->getvaoID());
    glEnableVertexAttribArray(attrib);
    shader->loadviewMatrix(cam);
    entityTransformation(en); //Transforms entity
    glDrawElements(GL_TRIANGLES, en.getMesh()->getIndexCount(), GL_UNSIGNED_INT, NULL);
    glDisableVertexAttribArray(attrib);
    glBindVertexArray(0);
}

void entityRenderer::entityTransformation(entity &en)
{
    util::Matrix matrix = util::IDENTITY_MATRIX;
    util::TranslateMatrix(&matrix, en.getPosX(), en.getPosY(), en.getPosZ());
    util::Rotate(&matrix, en.getRotX(), en.getRotY(), en.getRotZ());
    util::ScaleMatrix(&matrix, en.getScale(), en.getScale(), en.getScale());
    shader->loadTransformMatrix(matrix);
}
