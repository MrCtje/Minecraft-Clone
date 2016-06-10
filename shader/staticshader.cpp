#include "staticshader.h"

StaticShader::StaticShader(GLuint program)
{
    loc_transformMatrix = glGetUniformLocation(program, "transformMatrix");
    loc_projectMatrix = glGetUniformLocation(program, "projectMatrix");
    loc_viewMatrix = glGetUniformLocation(program, "viewMatrix");
    std::cout << std::endl << "Project, transform, viewmatrixlocation: " << loc_projectMatrix << " " << loc_transformMatrix << " " << loc_viewMatrix << std::endl;
}

void StaticShader::loadTransformMatrix(util::Matrix transformation)
{
    glUniformMatrix4fv(loc_transformMatrix, 1, GL_FALSE, transformation.m);
}

void StaticShader::loadprojectMatrix(util::Matrix projection)
{
    glUniformMatrix4fv(loc_projectMatrix, 1, GL_FALSE, projection.m);
}

void StaticShader::loadviewMatrix(Camera &view)
{
    util::Matrix matrix = util::IDENTITY_MATRIX;
    util::TranslateMatrix(&matrix, -view.getPosX(), -view.getPosY(), view.getPosZ());
    util::Rotate(&matrix, view.getPitch(), view.getYaw(), view.getRoll());



    glUniformMatrix4fv(loc_viewMatrix, 1, GL_FALSE, matrix.m);
}
