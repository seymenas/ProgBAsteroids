#pragma once
#include <raylib-cpp.hpp>
#include <vector>
#include <cmath>
#include "spaceship.h"
#include "bullet.h"
#include "asteroid.h"



class GameMaster {
private:
    int screenWidth;
    int screenHeight;
    raylib::Window window;
    raylib::Texture background_texture;
    Spaceship ship;
    std::vector<Bullet> bullets{};
    //raylib::Vector2 bullets;
    float bulletCooldown;
    float timeSinceLastShot;
    float asteroidCooldown;
    float timeSinceLastAsteroid;
    std::vector<Asteroid> asteroids{};

    void createAsteroids();
    void handleKeyboardInput();
public:
    GameMaster();
    void manageGame();
};
