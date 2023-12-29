#include <iostream>
#include <memory>
#include <sstream>
#include <variant>

#include "gamemanager.h"
#include "asteroid.h"
#include "spaceship.h"
#include "projectile.h"

GameManager::GameManager()
: score_(0)
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

    objects_.push_back(std::make_shared<Asteroid>(asteroidPos, asteroidRot, asteroidSize, asteroidVelocity));
}

void GameManager::spawnSpaceship()
{
    raylib::Vector2 shipPos = generateRandomPos();

    auto ship = std::make_shared<Spaceship>(shipPos);
    ship->set_speed({1, 1});
    objects_.push_back(ship);
    player_ = ship;
}

void GameManager::drawObjects() const
{
    for(auto obj : objects_)
    {
        obj->draw();
    }
}

void GameManager::drawHud() const
{
    std::stringstream ss;
    ss << "Health: " << player_->getHealth() << std::endl
       << "Score: " << score_ << std::endl;
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
    for(auto obj : objects_)
    {
        if(obj->isMarkedForDeletion())
            objectsToDelete.push_back(obj);
        else
            obj->update();
    }

    // Delete objects
    for(auto obj : objectsToDelete)
    {
        objects_.remove(obj);
    }

    if(IsKeyPressed(KEY_SPACE))
    {
        launchProjectile();
    }
}

void GameManager::launchProjectile()
{
    auto projectile = std::make_shared<Projectile>(player_->getPosition(), player_->getRotation());
    objects_.push_back(projectile);
}

void GameManager::checkCollisions() {
    for(auto obj1 : objects_)
    {
        for(auto obj2 : objects_)
        {
            DrawCircle(obj1->getPosition().x, obj1->getPosition().y, obj1->getSizeDimensions().x/2, GREEN);
            if(CheckCollisionCircles(obj1->getPosition(), obj1->getSizeDimensions().x/2, obj2->getPosition(), obj2->getSizeDimensions().x/2)) {
                if(obj1 != obj2) {
                    obj1->handleCollision(obj2);
                    obj2->handleCollision(obj1);
                }
            }
        }
    }
}