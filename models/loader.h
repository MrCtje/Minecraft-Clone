#ifndef LOADER_H
#define LOADER_H
#include <GL/glew.h>
#include "mesh.h"
#include <vector>
#include <iostream>
#include "models/model.h"
#include "util/matrix.h"

class Loader
{
public:
    Loader();
    ~Loader();
    Mesh loadToMesh(Model& model);


private:
    GLuint createVAO();
    std::vector<GLuint> vboList;
    std::vector<GLuint> vaoList;
    void storeDataInVBO(int index, int dataElements, GLuint vertexCount, float *data);
    void bindIndicesBuffer(GLuint * indices, GLuint indexCount);
};

#endif // LOADER_H
