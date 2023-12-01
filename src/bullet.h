#pragma once
#include <raylib-cpp.hpp>
#include "gameobject.h"

class Bullet : public GameObject{
public:
    Bullet(float start_x, float start_y, float start_direction);

    void move() override;
    void draw() override;
};