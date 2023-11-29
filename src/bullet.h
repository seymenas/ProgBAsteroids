#pragma once
#include <raylib-cpp.hpp>
#include "gameobject.h"

class Bullet : public GameObject{
public:
    Bullet(float startX, float startY, float startDirection);

    void move() override;
    void draw() override;
};