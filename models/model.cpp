#include "models/model.h"

void freeModelMemory(Model *m){
    delete[] m->indices;
    delete[] m->normals;
    delete[] m->textures;
    delete[] m->vertices;
    delete m;
}
