#include <raylib-cpp.hpp>
#include "spaceship.h"

Spaceship::Spaceship():texture("resources/spaceship.png") {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    vel_x = 0;
    vel_y = 0;
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
        //this->y -= vel_y;
        vel_y = -1;
    }
    if (IsKeyDown(KEY_DOWN)) {
        //this->y += vel_y;
        vel_y = 1;
    }
    if (IsKeyDown(KEY_RIGHT)) {
        //this->x += vel_x;
        vel_x = 1;
    }
    if (IsKeyDown(KEY_LEFT)) {
        //this->x -= vel_x;
        vel_x = -1;
    }

    x += vel_x;
    y += vel_y;
}

void Spaceship::draw() {
    texture.Draw(x, y);
}

//GETTER FUNCTIONS
int Spaceship::get_x() {
    return x;
}
int Spaceship::get_y() {
    return y;
}
