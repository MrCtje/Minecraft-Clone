#include "entity.h"

entity::entity(Mesh &mesh, float posX, float posY, float posZ, float rotX, float rotY, float rotZ, float scale)
{
    this->mesh = &mesh;
    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;
    this->rotX = rotX;
    this->rotY = rotY;
    this->rotZ = rotZ;
    this->scale = scale;
}

entity::entity(Mesh &mesh, float posX, float posY, float posZ, float rotX, float rotY, float rotZ)
{
    this->mesh = &mesh;
    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;
    this->rotX = rotX;
    this->rotY = rotY;
    this->rotZ = rotZ;
    scale = 1;
}

entity::entity(Mesh &mesh, float posX, float posY, float posZ, float scale)
{
    this->mesh = &mesh;
    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;
    this->scale = scale;
}

float entity::getPosX() const
{
    return posX;
}

void entity::setPosX(float value)
{
    posX = value;
}


float entity::getPosY() const
{
    return posY;
}

void entity::setPosY(float value)
{
    posY = value;
}

float entity::getPosZ() const
{
    return posZ;
}

void entity::setPosZ(float value)
{
    posZ = value;
}

float entity::getRotX() const
{
    return rotX;
}

void entity::setRotX(float value)
{
    rotX = value;
}

float entity::getRotY() const
{
    return rotY;
}

void entity::setRotY(float value)
{
    rotY = value;
}

float entity::getRotZ() const
{
    return rotZ;
}

void entity::setRotZ(float value)
{
    rotZ = value;
}

float entity::getScale() const
{
    return scale;
}

void entity::setScale(float value)
{
    scale = value;
}

Mesh* entity::getMesh() const
{
    return mesh;
}

void entity::setMesh(Mesh &value)
{
    mesh = &value;
}
