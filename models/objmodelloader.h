#ifndef OBJMODELLOADER_H
#define OBJMODELLOADER_H
#include <fstream>
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "models/model.h"
#include "util/string_util.h"

#define SPACE_CHARACTER 32

class OBJModelLoader
{
public:
    ~OBJModelLoader();
    OBJModelLoader();
    Model *loadOBJModel(const char *filePath);

private:
    std::vector<std::string> vertexVector;
    std::vector<std::string> indexVector;
    std::vector<std::string> texturesVector;
    std::vector<std::string> normalVector;
    GLuint getVertexCount();
    GLuint getIndexCount();
    int vertexCount;
    int indexCount;
    bool texturePresent;
};

#endif // OBJMODELLOADER_H
