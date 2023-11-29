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
float GameObject::get_direction() {
    return rotation;
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
void GameObject::set_direction(float direction_) {
    rotation = direction_;
}