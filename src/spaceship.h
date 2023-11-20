#pragma once
#include <raylib-cpp.hpp>
#include "gameobject.h"

class Spaceship : public GameObject{
public:
    Spaceship();
    void move() override;
    void draw() override;
    void createBullet();
};