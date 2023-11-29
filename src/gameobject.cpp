#include <raylib-cpp.hpp>
#include "gameobject.h"

GameObject::GameObject() {
}

void GameObject::move() {

}

void GameObject::draw() {

}

//GETTER FUNCTIONS
float GameObject::get_x() {
    return x;
}
float GameObject::get_y() {
    return y;
}
float GameObject::get_vel_x() {
    return vel_x;
}
float GameObject::get_vel_y() {
    return vel_y;
}
float GameObject::get_direction() {
    return direction;
}
double GameObject::get_speed() {
    return speed;
}

//SETTER FUNCTIONS
void GameObject::set_x(float x_) {
    x = x_;
}
void GameObject::set_y(float y_) {
    y = y_;
}
void GameObject::set_vel_x(float vel_x_) {
    vel_x = vel_x_;
}
void GameObject::set_vel_y(float vel_y_) {
    vel_y = vel_y_;
}
void GameObject::set_direction(float direction_) {
    direction = direction_;
}
void GameObject::set_speed(double speed_) {
    speed = speed_;
}