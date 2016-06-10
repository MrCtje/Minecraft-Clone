#include "mesh.h"



Mesh::Mesh(GLuint vaoID, GLuint vertexCount, GLuint indexCount)
{
    this->vaoID = vaoID;
    this->vertexCount = vertexCount;
    this->indexCount = indexCount;
}

GLuint Mesh::getvaoID() const{return vaoID;}
GLuint Mesh::getVertexCount() const{return vertexCount;}
GLuint Mesh::getIndexCount() const{return indexCount;}
