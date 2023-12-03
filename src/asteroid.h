#pragma once
#include "gameobject.h"

class Asteroid : public GameObject {
public:
    Asteroid(int screenWidth, int screenHeight);
private:
    float scale;
};