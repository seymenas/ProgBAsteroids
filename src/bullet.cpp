#include <raylib-cpp.hpp>
#include "bullet.h"

Bullet::Bullet(float start_x, float start_y, float start_direction)
{
    texture.Load("resources/bullet.png");
    x = start_x;
    y = start_y;
    rotation = start_direction;
    speed = 1.2;
}

void Bullet::move() {
    // Move the bullet based on its velocity
    x += sin(rotation * (M_PI / 180)) * speed;
    y += -cos(rotation * (M_PI / 180)) * speed;

}

void Bullet::draw() {
    raylib::Rectangle source(0, 0, texture.GetWidth(), texture.GetHeight());
    raylib::Rectangle dest(x, y, texture.GetWidth(), texture.GetHeight());
    DrawTexturePro(texture, source, dest, Vector2{(float) texture.GetWidth() / 2,
                                                  (float) texture.GetHeight() / 2}, rotation, WHITE);
}
