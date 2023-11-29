#pragma once

#include <list>
#include <memory>

#include "gameobject.h"
#include "spaceship.h"
#include "asteroid.h"
#include "projectile.h"

class GameManager
{
    using GameObjectContainer = std::list<std::shared_ptr<GameObject>>;

private:
    inline static float _initialAsteroidSpawnProb = 0.005;
    inline static float _asteroidSpawProbIncrease = 0.0005;

    int _score;
    float _asteroidSpawnProbPerFrame;

    GameObjectContainer _objects;
    GameObjectContainer _objectsToSpawn;
    std::shared_ptr<Spaceship> _player;

    raylib::Vector2 generateRandomPos();

    void launchProjectile();

public:
    GameManager();

    std::shared_ptr<Asteroid> createAsteroid(raylib::Vector2 position, Asteroid::Size size, float rotation);

    void spawnAsteroid();

    void spawnSpaceship();

    void update();

    void drawObjects() const;

    void drawHud() const;
};