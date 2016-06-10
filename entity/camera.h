#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
public:
    Camera(float x, float y, float z);
    float getPitch() const;

    float getYaw() const;

    float getRoll() const;

    float getPosX() const;

    float getPosY() const;

    float getPosZ() const;

    void increaseYaw(float value);
    void increaseRoll(float value);
    void increasePitch(float value);

    void increasePosX(float value);
    void increasePosY(float value);
    void increasePosZ(float value);

    void setPitch(float value);

    void setYaw(float value);

private:
    float posX;
    float posY;
    float posZ;
    float pitch;
    float yaw;
    float roll;

};

#endif // CAMERA_H
