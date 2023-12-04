#include "asteroid.h"
#include "gamemanager.h"

#include <sstream>
#include <iomanip>

Asteroid::Asteroid(raylib::Vector2 initialPos, float initialRot, Size initialSize, raylib::Vector2 initialVelocity)
: GameObject(initialPos, texturePath_, 1.f, initialRot)
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

Asteroid::Size Asteroid::getSize() const
{
    return size_;
}
