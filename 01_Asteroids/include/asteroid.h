#pragma once

#include <raylib-cpp.hpp>

#include "gameobject.h"

class Asteroid : public GameObject
{
public:
    enum Size
    {
        SMALL = 0,
        MEDIUM,
        BIG
    };

private:
    inline static const std::string _texturePath = "./resources/ohmsteroid.png";
    Size _size;
    raylib::Vector2 _velocity;

    void updateScale();

public:
    Asteroid(raylib::Vector2 initialPos, float initialRot, Size initialSize, raylib::Vector2 initialVelocity);

    void update() override;

    Size getSize() const;
};
