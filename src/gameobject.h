#pragma once
#include <raylib-cpp.hpp>

class GameObject {
protected:
    float x;
    float y;
    float rotation;
    double speed;
    raylib::Texture texture;

public:
    GameObject();
    virtual void move();
    virtual void draw();
    raylib::Rectangle dest;
    //GETTER FUNCTIONS
    float get_x();
    float get_y();
};
