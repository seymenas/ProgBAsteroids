#pragma once
#include <raylib-cpp.hpp>

class Bullet {
private:
    float x;
    float y;
    float vel_x;
    float vel_y;
    raylib::Texture texture;
    float direction;

public:
    Bullet(float x_, float y_, float vel_x_, float vel_y_, float direction_);
    void move();
    void draw();
    //GETTER FUNCTIONS
    int get_x();
    int get_y();
};