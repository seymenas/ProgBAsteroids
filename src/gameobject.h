#pragma once
#include <raylib-cpp.hpp>

class GameObject {
protected:
    float x;
    float y;
    float rotation;
    double speed;
    virtual void move();
    virtual void draw();
    raylib::Texture texture;

public:
    GameObject();
    //GETTER FUNCTIONS
    float get_x();
    float get_y();
};
