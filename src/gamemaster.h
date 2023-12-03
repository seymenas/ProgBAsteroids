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
    float bulletCooldown;
    float timeSinceLastShot;
    float asteroidCooldown;
    float timeSinceLastAsteroid;
    std::vector<Asteroid> asteroids{};
    int lifes;
    float loseLifeCooldown;
    float timeSinceLastLifeLost;
    int score;
    int fontSize;
    void createAsteroids();
    void handleKeyboardInput();
    void checkColissionAsteroidBullet(std::vector<Bullet>::iterator& bulletIt);
    void checkColissionAsteroidSpaceship(std::vector<Asteroid>::iterator& asteroidIt);
public:
    GameMaster();
    void manageGame();
};
