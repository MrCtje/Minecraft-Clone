#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <GL/glew.h>
#include <fstream>
#include <iostream>
#include <string>
class shaderprogram
{
private:

public:
    static GLuint loadShader(const char* filepath, GLenum shader_type);
    shaderprogram();
};

#endif // SHADERPROGRAM_H
