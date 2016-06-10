#ifndef MESH_H
#define MESH_H
#include <GL/glew.h>

class Mesh
{
private:
    GLuint vaoID;
    GLuint vertexCount;
    GLuint indexCount;
public:
    Mesh(GLuint vaoID, GLuint vertexCount, GLuint indexCount);
    GLuint getvaoID() const;
    GLuint getVertexCount() const;
    GLuint getIndexCount() const;
};

#endif // MESH_H
