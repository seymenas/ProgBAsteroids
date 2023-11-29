#pragma once

#include "gameobject.h"

class Projectile : public GameObject
{
private:
    inline static const std::string _texturePath = "./resources/bullet.png";
    const float _movementSpeed = 8.f;
    const float _range = 400.f;

    float _distanceTravelled;

public:
    Projectile(raylib::Vector2 initialPos, float rotation);

    void update() override;

    void move(raylib::Vector2 moveVec) override;
};