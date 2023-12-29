#pragma once

#include "gameobject.h"

class PhysicsObject : public GameObject
{
public:
    PhysicsObject(raylib::Vector2 initialPos, std::string texturePath, float initialScale,
                  float initialRot);
    void set_speed(raylib::Vector2 new_speed);
    void accelerate(raylib::Vector2 acceleration);
    void update() override;
protected:
    const int thrust = 10;
private:
    raylib::Vector2 speed;
    raylib::Vector2 acceleration;
    float friction = 0.01;
};