#pragma once
#include <raylib-cpp.hpp>
#include "gameobject.h"
#include "bullet.h"

class Spaceship : public GameObject{
public:
    Spaceship();
    void draw() override;
    void move(std::string direction);
    void rotate(std::string direction);
    Bullet shoot();
};