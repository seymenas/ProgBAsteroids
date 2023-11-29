#pragma once
#include <raylib-cpp.hpp>

class GameObject {
protected:
    float x;
    float y;
    float vel_x;
    float vel_y;
    float rotation;
    double speed;
    virtual void move();
    virtual void draw();

public:
    GameObject();
    //GETTER FUNCTIONS
    float get_x();
    float get_y();
    float get_direction();
    double get_speed();
    raylib::Texture texture;
    //SETTER FUNCTIONS
    void set_x(float x_);
    void set_y(float y_);
    void set_direction(float direction_);
};
