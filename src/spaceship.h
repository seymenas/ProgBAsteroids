#pragma once
#include <raylib-cpp.hpp>

class Spaceship {
private:
    int x;
    int y;
    float vel_x;
    float vel_y;
    raylib::Texture texture;

public:
    Spaceship();
    void move();
    void draw();
    //GETTER FUNCTIONS
    int get_x();
    int get_y();
};