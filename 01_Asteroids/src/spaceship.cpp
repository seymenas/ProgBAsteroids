#include "spaceship.h"


Spaceship::Spaceship(raylib::Vector2 initialPos)
: GameObject(initialPos, _texturePath)
, _health(_maxHealth)
{
}

void Spaceship::update()
{
    if(IsKeyDown(KEY_W))
        move(raylib::Vector2{0.f, -_movementSpeed}.Rotate(DEG2RAD * _rot)); // Attention: Rotate parameter is radians, not degrees!
    if(IsKeyDown(KEY_A))
        rotate(-_rotationSpeed);
    if(IsKeyDown(KEY_D))
        rotate(_rotationSpeed);

    GameObject::update();
}

int Spaceship::getHealth() const
{
    return _health;
}
