#pragma once

#include "gameobject.h"

#include <list>

class Spaceship : public GameObject
{
private:
    inline static const std::string _texturePath = "./resources/spaceship.png";
    const float _movementSpeed = 4.0f;
    const float _thrust = 0.51f;
    const float _shipFriction = 0.995f;
    const float _rotationSpeed = 4.5f;
    const int _maxHealth = 100;

    int _health;

public:
    Spaceship(raylib::Vector2 initialPos);

    void update() override;

    int getHealth() const;
};