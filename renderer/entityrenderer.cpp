#include "entityrenderer.h"

entityRenderer::entityRenderer(Camera& camera, GLuint program, int &width, int &height)
{
    this->program = program;
    util::Matrix projectionMatrix = util::CreateProjectionMatrix(70, width/height, .1, 1000);
    shader = new StaticShader(program);
    shader->loadprojectMatrix(projectionMatrix);
    shader->loadviewMatrix(camera);

    tex_2d = SOIL_load_OGL_texture
        (
            "/home/mrctje/Dropbox/Eclipse/SteenPapierSchaar/texture_cube.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
        );
}

entityRenderer::~entityRenderer()
{
    glDeleteTextures(1, &tex_2d);
    delete shader;
}

void entityRenderer::render(Camera &cam, entity &en)
{
    glBindVertexArray(en.getMesh()->getvaoID());
    glEnableVertexAttribArray(0);
    //glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    shader->loadviewMatrix(cam);
    entityTransformation(en); //Transforms entity
    glDrawElements(GL_TRIANGLES, en.getMesh()->getIndexCount(), GL_UNSIGNED_INT, NULL);
    glDisableVertexAttribArray(0);
    //glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glBindVertexArray(0);
}

void entityRenderer::entityTransformation(entity &en)
{
    util::Matrix matrix = util::IDENTITY_MATRIX;
    util::Rotate(&matrix, en.getRotX(), en.getRotY(), en.getRotZ());
    util::ScaleMatrix(&matrix, en.getScale(), en.getScale(), en.getScale());
    util::TranslateMatrix(&matrix, -en.getPosX(), -en.getPosY(), -en.getPosZ());

    shader->loadTransformMatrix(matrix);
}
