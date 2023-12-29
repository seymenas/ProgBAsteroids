#include <iostream>
#include "projectile.h"

Projectile::Projectile(raylib::Vector2 initialPos, float rotation)
: GameObject(initialPos, texturePath_, 1.0, rotation)
, distanceTravelled_(0.0)
{}

void Projectile::update()
{
    move(raylib::Vector2{0.0, -movementSpeed_}.Rotate(DEG2RAD * rot_));
    if(distanceTravelled_ > range_)
        markForDeletion();
}

void Projectile::move(raylib::Vector2 moveVec)
{
    distanceTravelled_  += moveVec.Length();
    GameObject::move(moveVec);
}

void Projectile::handleCollision(std::shared_ptr<GameObject> otherObj)
{
    std::shared_ptr<Asteroid> asteroid = std::dynamic_pointer_cast<Asteroid>(otherObj);
    if(asteroid != nullptr)
    {
        markForDeletion();

    }
}

