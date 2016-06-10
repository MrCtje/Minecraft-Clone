#ifndef ENTITY_H
#define ENTITY_H
#include "models/mesh.h"

class entity
{
public:
    entity(Mesh &mesh, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scale);
    entity(Mesh &mesh, float posX, float posY, float posZ, float rotX, float rotY, float rotZ);
    entity(Mesh &mesh, float posX, float posY, float posZ, float scale);

    float getPosX() const;
    void setPosX(float value);

    float getPosY() const;
    void setPosY(float value);

    float getPosZ() const;
    void setPosZ(float value);

    float getRotX() const;
    void setRotX(float value);

    float getRotY() const;
    void setRotY(float value);

    float getRotZ() const;
    void setRotZ(float value);

    float getScale() const;
    void setScale(float value);

    Mesh *getMesh() const;
    void setMesh(Mesh &value);

private:
    Mesh *mesh;
    float posX;
    float posY;
    float posZ;
    float rotX;
    float rotY;
    float rotZ;
    float scale;
//    float scalY;
//    float scalZ;
};

#endif // ENTITY_H
