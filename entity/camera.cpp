#include "camera.h"

Camera::Camera(float x, float y, float z)
{
    posX = x;
    posY = y;
    posZ = z;
}

float Camera::getPitch() const
{
    return pitch;
}

float Camera::getYaw() const
{
    return yaw;
}

float Camera::getRoll() const
{
    return roll;
}

float Camera::getPosX() const
{
    return posX;
}

float Camera::getPosY() const
{
    return posY;
}

float Camera::getPosZ() const
{
    return posZ;
}

void Camera::increaseYaw(float value)
{
    yaw += value;
}

void Camera::increaseRoll(float value)
{
    roll += value;
}

void Camera::increasePitch(float value)
{
    pitch += value;
}

void Camera::increasePosX(float value)
{
    posX += value;
}

void Camera::increasePosY(float value)
{
    posY += value;
}

void Camera::increasePosZ(float value)
{
    posZ += value;
}

void Camera::setPitch(float value)
{
    pitch = value;
}

void Camera::setYaw(float value)
{
    yaw = value;
}
