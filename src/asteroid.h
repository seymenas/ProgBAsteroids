#pragma once
#include <raylib-cpp.hpp>
#include "gameobject.h"

class Asteroid : public GameObject {
public:
    Asteroid(int screenWidth, int screenHeight);

    void move() override;
    void draw() override;
private:
    float scale;
};