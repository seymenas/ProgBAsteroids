#include <raylib-cpp.hpp>
#include "spaceship.h"

Spaceship::Spaceship() {
    texture.Load("resources/spaceship.png");
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    vel_x = 0;
    vel_y = 0;
    direction = 0.0f;
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


    //MOVE
        if (IsKeyDown(KEY_UP)) {
            if(y > 0) {
                vel_y = -speed;
            }
        }
        if (IsKeyDown(KEY_DOWN)) {
            if(y + texture.GetHeight() < GetScreenHeight()) {
                vel_y = speed;
            }
        }
        if (IsKeyDown(KEY_RIGHT)) {
            if(x + texture.GetWidth() < GetScreenWidth()) {
                vel_x = speed;
            }
        }
        if (IsKeyDown(KEY_LEFT)) {
            if (x > 0) {
                vel_x = -speed;
            }
        }

        x += vel_x;
        y += vel_y;

        if (IsKeyDown(KEY_A)) {
            direction -= 0.5f;
            }
        if (IsKeyDown(KEY_D)) {
            direction += 0.5f;
        }

    if (IsKeyDown(KEY_SPACE)) {
        createBullet();
    }
    }


void Spaceship::draw() {
    // Slightly more advanced version: Draw object with rotation around center
    raylib::Vector2 origin = raylib::Vector2(texture.GetWidth() / 2, texture.GetWidth() / 2);
    raylib::Rectangle sourceRect = { 0.f, 0.f, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    raylib::Rectangle destRect = { x, y, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    texture.Draw(sourceRect, destRect, origin, direction);
}

void Spaceship::createBullet() {

}