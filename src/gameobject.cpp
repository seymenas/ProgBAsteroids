#include "gameobject.h"

GameObject::GameObject() {
}

void GameObject::move() {
    x += sin(rotation * (M_PI / 180)) * speed;
    y += -cos(rotation * (M_PI / 180)) * speed;
}

void GameObject::draw() {
    // Draw texture
    raylib::Rectangle source(0, 0, texture.GetWidth(), texture.GetHeight());
    dest = raylib::Rectangle(x, y, texture.GetWidth(), texture.GetHeight());
    DrawTexturePro(texture, source, dest, Vector2{(float) texture.GetWidth() / 2,
                                                  (float) texture.GetHeight() / 2}, rotation, WHITE);

    // Draw (invisible) source rectangle over texture to track collisions
    DrawRectanglePro(dest, {static_cast<float>(texture.GetWidth()/2), static_cast<float>(texture.GetHeight()/2)}, rotation, BLANK);
}

//GETTER FUNCTIONS
float GameObject::get_x() {
    return x;
}
float GameObject::get_y() {
    return y;
}