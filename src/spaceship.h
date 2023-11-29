#pragma once
#include <raylib-cpp.hpp>
#include "gameobject.h"
#include "bullet.h"

class Spaceship : public GameObject{
public:
    Spaceship();
    void move() override;
    void draw() override;
    Bullet shoot();

};