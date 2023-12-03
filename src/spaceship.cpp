#include "spaceship.h"

Spaceship::Spaceship() {
    texture.Load("resources/spaceship.png");
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    rotation = 0.0;
    speed = 0.5;
}

void Spaceship::move(std::string direction) {
    if (direction == "forward") {
        x += sin(rotation * (M_PI / 180)) * speed;
        y += -cos(rotation * (M_PI / 180)) * speed;
    }
    if (direction == "backward") {
        x -= sin(rotation * (M_PI / 180)) * speed / 2;
        y -= -cos(rotation * (M_PI / 180)) * speed / 2;
    }
}

void Spaceship::rotate(std::string direction) {
    if(direction == "right") {
        rotation += 1;
    }
    if(direction == "left") {
        rotation -= 1;
    }
}

Bullet Spaceship::shoot() {
    Bullet bullet(x, y, rotation);
    return bullet;
}