#include <raylib-cpp.hpp>
#include "bullet.h"

Bullet::Bullet(float startX, float startY, float startDirection)
{
    texture.Load("resources/bullet.png");
    x = startX;
    y = startY;
    //vel_x = startVelX * 1.2;
    //vel_y = startVelY * 1.2;
    direction = startDirection;
    speed = 1;
}

void Bullet::move() {
    // Move the bullet based on its velocity
    x += sin(direction * (M_PI / 180)) * speed;
    y += -cos(direction * (M_PI / 180)) * speed;

}

void Bullet::draw() {
    raylib::Rectangle source(0, 0, texture.GetWidth(), texture.GetHeight());
    raylib::Rectangle dest(x, y, texture.GetWidth(), texture.GetHeight());
    DrawTexturePro(texture, source, dest, Vector2{(float) texture.GetWidth() / 2,
                                                  (float) texture.GetHeight() / 2}, direction, WHITE);

    /*
    // Draw the bullet
    raylib::Rectangle sourceRect = { 0.f, 0.f, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    raylib::Rectangle destRect = { x, y, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    raylib::Vector2 origin = raylib::Vector2(texture.GetWidth() / 2, texture.GetHeight() / 2);
    texture.Draw(sourceRect, destRect, origin, 0.0f, raylib::WHITE);
     */
}
