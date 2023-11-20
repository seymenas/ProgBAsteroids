#pragma once
#include <raylib-cpp.hpp>

class GameObject {
protected:
    float x;
    float y;
    float vel_x;
    float vel_y;
    raylib::Texture texture;
    float direction;
    double speed;
    virtual void move();
    virtual void draw();


public:
    GameObject();
    //GETTER FUNCTIONS
    int get_x();
    int get_y();

};
