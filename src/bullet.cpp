#include <raylib-cpp.hpp>
#include "bullet.h"

Bullet::Bullet(float x_, float y_, float vel_x_, float vel_y_, float direction_):texture("resources/bullet.png") {
    x =  x_;
    y = y_;
    vel_x = vel_x_;
    vel_y = vel_y_;
    direction = direction_;
}

void Bullet::move() {
    x += vel_x;
    y += vel_y;
}


void Bullet::draw() {
    // Slightly more advanced version: Draw object with rotation around center
    raylib::Vector2 origin = raylib::Vector2(texture.GetWidth() / 2, texture.GetWidth() / 2);
    raylib::Rectangle sourceRect = { 0.f, 0.f, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    raylib::Rectangle destRect = { x, y, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    texture.Draw(sourceRect, destRect, origin, direction);
}

//GETTER FUNCTIONS
int Bullet::get_x() {
    return x;
}
int Bullet::get_y() {
    return y;
}
