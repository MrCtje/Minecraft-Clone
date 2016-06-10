#include "loader.h"

Loader::Loader()
{

}

GLuint Loader::createVAO(){
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    vaoList.push_back(vaoID);
    glBindVertexArray(vaoID);
    return vaoID;
}

Mesh Loader::loadToMesh(Model& model){
    Mesh mesh(createVAO(), model.vertexCount, model.indexCount);
    bindIndicesBuffer(model.indices, model.indexCount);
    storeDataInVBO(0, 3, model.vertexCount, model.vertices);
    storeDataInVBO(1, 3, model.normalsCount, model.normals);
    storeDataInVBO(2, 2, model.texturesCount, model.textures);
    return mesh;
}

void Loader::bindIndicesBuffer(GLuint * indices, GLuint indexCount){
    GLuint veoID;
    glGenBuffers(1, &veoID);
    vboList.push_back(veoID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, veoID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GL_UNSIGNED_INT) * indexCount, indices, GL_STATIC_DRAW);
    int size;
    glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    std::cout << "ElementBuffersize: " << size/sizeof(GL_UNSIGNED_INT) << std::endl;
}

void Loader::storeDataInVBO(int index, int dataElements, GLuint vertexCount, GLfloat * data){
    GLuint vboID;
    glGenBuffers(1, &vboID);
    vboList.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT) * vertexCount * dataElements, data, GL_STATIC_DRAW);
    int size;
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    std::cout<<"Buffersize: " << size/sizeof(GL_FLOAT) << std::endl;
    glVertexAttribPointer(index, dataElements, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Loader::~Loader(){
    glDeleteVertexArrays(vaoList.size(), vaoList.data());
    glDeleteBuffers(vboList.size(), vboList.data());
}
