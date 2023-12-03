#include "gameobject.h"

GameObject::GameObject() {
}

void GameObject::move() {
    x += sin(rotation * (M_PI / 180)) * speed;
    y += -cos(rotation * (M_PI / 180)) * speed;
}

void GameObject::draw() {
    raylib::Rectangle source(0, 0, texture.GetWidth(), texture.GetHeight());
    raylib::Rectangle dest(x, y, texture.GetWidth(), texture.GetHeight());
    DrawTexturePro(texture, source, dest, Vector2{(float) texture.GetWidth() / 2,
                                                  (float) texture.GetHeight() / 2}, rotation, WHITE);
}

//GETTER FUNCTIONS
float GameObject::get_x() {
    return x;
}
float GameObject::get_y() {
    return y;
}