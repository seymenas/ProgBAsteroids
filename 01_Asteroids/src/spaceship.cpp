#include "spaceship.h"


Spaceship::Spaceship(raylib::Vector2 initialPos)
: GameObject(initialPos, texturePath_, 1.0, 0.0)
, health_(maxHealth_)
{
}

void Spaceship::update()
{
    if(IsKeyDown(KEY_W))
        move(raylib::Vector2{0.0, -movementSpeed_}.Rotate(DEG2RAD * rot_)); // Attention: Rotate parameter is radians, not degrees!
    if(IsKeyDown(KEY_A))
        rotate(-rotationSpeed_);
    if(IsKeyDown(KEY_D))
        rotate(rotationSpeed_);

    GameObject::update();
}

int Spaceship::getHealth() const
{
    return health_;
}
