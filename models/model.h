#ifndef MODEL_H
#define MODEL_H
#include <GL/glew.h>
typedef struct Model{
    GLfloat * vertices;
    GLuint * indices;
    GLfloat * normals;
    GLfloat * textures;
    GLuint vertexCount;
    GLuint indexCount;
    GLuint texturesCount;
    GLuint normalsCount;
}Model;


void freeModelMemory(Model *m);

#endif // MODEL_H
