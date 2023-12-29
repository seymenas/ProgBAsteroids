#pragma once

#include "gameobject.h"
#include "asteroid.h"

class Projectile : public GameObject
{
private:
    inline static const std::string texturePath_ = "./resources/bullet.png";
    const float movementSpeed_ = 8.0;
    const float range_ = 400.0;

    float distanceTravelled_;

public:
    Projectile(raylib::Vector2 initialPos, float rotation);

    void handleCollision(std::shared_ptr<GameObject> other) override;

    void update() override;

    void move(raylib::Vector2 moveVec) override;

};