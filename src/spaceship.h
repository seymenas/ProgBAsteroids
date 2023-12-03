#pragma once
#include "gameobject.h"
#include "bullet.h"

class Spaceship : public GameObject{
public:
    Spaceship();
    void move(std::string direction);
    void rotate(std::string direction);
    Bullet shoot();
};