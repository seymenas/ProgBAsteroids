#include <iostream>
#include "spaceship.h"


Spaceship::Spaceship(raylib::Vector2 initialPos)
: PhysicsObject(initialPos, texturePath_, 1.0, 0.0)
, health_(maxHealth_)
{
}

void Spaceship::update()
{
    if(IsKeyDown(KEY_W))
        accelerate(raylib::Vector2{0.f, static_cast<float>(-thrust)}.Rotate(DEG2RAD * rot_));
    if(IsKeyDown(KEY_A))
        rotate(-rotationSpeed_);
    if(IsKeyDown(KEY_D))
        rotate(rotationSpeed_);

    timeSinceLastLifeLost += GetFrameTime();

    PhysicsObject::update();
}

void Spaceship::handleCollision(std::shared_ptr<GameObject> otherObj)
{
    std::shared_ptr<Asteroid> asteroid = std::dynamic_pointer_cast<Asteroid>(otherObj);
    if(asteroid != nullptr)
    {
        if(timeSinceLastLifeLost >= loseLifeCoolDown) {
            health_ = health_ - 50;
            timeSinceLastLifeLost = 0;
        }
    }
}

int Spaceship::getHealth() const
{
    return health_;
}

