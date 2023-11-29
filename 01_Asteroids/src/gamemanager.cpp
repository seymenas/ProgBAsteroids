#include <iostream>
#include <memory>
#include <sstream>
#include <variant>

#include "gamemanager.h"
#include "asteroid.h"
#include "spaceship.h"
#include "projectile.h"

GameManager::GameManager()
: _score(0)
, _asteroidSpawnProbPerFrame(_initialAsteroidSpawnProb)
{
}

void GameManager::spawnAsteroid()
{
    raylib::Vector2 asteroidPos = generateRandomPos();

    raylib::Vector2 asteroidVelocity {
        static_cast<float>(GetRandomValue(-2, 2)),
        static_cast<float>(GetRandomValue(-2, 2))
    };

    Asteroid::Size asteroidSize = static_cast<Asteroid::Size>(GetRandomValue(0, 2));

    int asteroidRot = GetRandomValue(0, 359);

    _objects.push_back(std::make_shared<Asteroid>(asteroidPos, asteroidRot, asteroidSize, asteroidVelocity));
}

void GameManager::spawnSpaceship()
{
    raylib::Vector2 shipPos = generateRandomPos();

    auto ship = std::make_shared<Spaceship>(shipPos);
    _objects.push_back(ship);
    _player = ship;
}

void GameManager::drawObjects() const
{
    for(auto obj : _objects)
    {
        obj->draw();
    }
}

void GameManager::drawHud() const
{
    std::stringstream ss;
    ss  << "Health: " << _player->getHealth() << std::endl
        << "Score: " << _score << std::endl;
    DrawText(ss.str().c_str(), 80, 80, 20, LIGHTGRAY);
}

raylib::Vector2 GameManager::generateRandomPos()
{
    return raylib::Vector2 {
        static_cast<float>(GetRandomValue(0, GetScreenWidth())),
        static_cast<float>(GetRandomValue(0, GetScreenHeight()))
    };
}

void GameManager::update()
{
    GameObjectContainer objectsToDelete;
    // Update objects
    for(auto obj : _objects)
    {
        if(obj->isMarkedForDeletion())
            objectsToDelete.push_back(obj);
        else
            obj->update();
    }

    // Delete objects
    for(auto obj : objectsToDelete)
    {
        _objects.remove(obj);
    }

    if(IsKeyPressed(KEY_SPACE))
    {
        launchProjectile();
    }
}

void GameManager::launchProjectile()
{
    auto projectile = std::make_shared<Projectile>(_player->getPosition(), _player->getRotation());
    _objects.push_back(projectile);
}
