/*
'#include <raylib-cpp.hpp>
#include "spaceship.h"

class Spaceship {
private:
    int x;
    int y;
    float vel_x;
    float vel_y;
    raylib::Texture texture;

public:
    Spaceship():texture("resources/spaceship.png") {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;
        vel_x = 0;
        vel_y = 0;
    }

    void move() {
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

    void draw() {
        texture.Draw(x, y);
    }

    //GETTER FUNCTIONS
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
}; */