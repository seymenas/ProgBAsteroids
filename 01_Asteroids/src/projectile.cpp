#include "projectile.h"

Projectile::Projectile(raylib::Vector2 initialPos, float rotation)
: GameObject(initialPos, _texturePath, 1.0f, rotation)
, _distanceTravelled(0.f)
{}

void Projectile::update()
{
    move(raylib::Vector2{0.f, -_movementSpeed}.Rotate(DEG2RAD * _rot));
    if(_distanceTravelled > _range)
        markForDeletion();
}

void Projectile::move(raylib::Vector2 moveVec)
{
    _distanceTravelled  += moveVec.Length();
    GameObject::move(moveVec);
}
