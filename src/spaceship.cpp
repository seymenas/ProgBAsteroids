#include <raylib-cpp.hpp>
#include "spaceship.h"

Spaceship::Spaceship() {
    texture.Load("resources/spaceship.png");
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    vel_x = 0;
    vel_y = 0;
    direction = 0.0;
    speed = 0.5;
}

void Spaceship::move() {
    // LIMITATIONS
    if (x + texture.GetWidth() > GetScreenWidth() || x == 0) {
        vel_x = 0;
    }
    if (y + texture.GetHeight() > GetScreenHeight() || y == 0) {
        vel_y = 0;
    }

    //x += vel_x;
    //y += vel_y;

    /*
    if (IsKeyDown(KEY_A)) {
        direction -= 0.5f;
        }
    if (IsKeyDown(KEY_D)) {
        direction += 0.5f;
    }
     */
}


void Spaceship::draw() {
    raylib::Rectangle source(0, 0, texture.GetWidth(), texture.GetHeight());
    raylib::Rectangle dest(x, y, texture.GetWidth(), texture.GetHeight());
    DrawTexturePro(texture, source, dest, Vector2{(float) texture.GetWidth() / 2,
                                                  (float) texture.GetHeight() / 2}, direction, WHITE);


    /*
    // Slightly more advanced version: Draw object with rotation around center
    raylib::Vector2 origin = raylib::Vector2(texture.GetWidth() / 2, texture.GetWidth() / 2);
    raylib::Rectangle sourceRect = { 0.f, 0.f, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    raylib::Rectangle destRect = { x, y, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    texture.Draw(sourceRect, destRect, origin, direction);
     */
}

Bullet Spaceship::shoot() {
    Bullet bullet(x, y, direction);
    return bullet;
}