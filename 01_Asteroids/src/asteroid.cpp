#include "asteroid.h"
#include "gamemanager.h"

#include <sstream>
#include <iomanip>
#include <iostream>

Asteroid::Asteroid(raylib::Vector2 initialPos, float initialRot, Size initialSize, raylib::Vector2 initialVelocity)
: GameObject(initialPos, texturePath_, 1.0, initialRot)
, size_(initialSize)
, velocity_(initialVelocity)
{
    updateScale();
}

void Asteroid::updateScale()
{
    switch(size_)
    {
        case Size::SMALL:
            scale_ = .2f;
            break;

        case Size::MEDIUM:
            scale_ = .5f;
            break;

        case Size::BIG:
            scale_ = .8f;
            break;
    }
}

void Asteroid::update()
{
    rotate(2);
    move(velocity_);
    GameObject::update();
}

void Asteroid::handleCollision(std::shared_ptr<GameObject> otherObj)
{
    // Asteroid <-> Projectile
    std::shared_ptr<Projectile> projectile = std::dynamic_pointer_cast<Projectile>(otherObj);
    if(projectile != nullptr)
    {
        std::cout << "ASTEROID COLISSION WITH PROJECTILE" << std::endl;
        markForDeletion();
    }
}

Asteroid::Size Asteroid::getSize() const
{
    return size_;
}
