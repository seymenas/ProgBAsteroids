#include "projectile.h"

Projectile::Projectile(raylib::Vector2 initialPos, float rotation)
: GameObject(initialPos, texturePath_, 1.0f, rotation)
, distanceTravelled_(0.f)
{}

void Projectile::update()
{
    move(raylib::Vector2{0.f, -movementSpeed_}.Rotate(DEG2RAD * rot_));
    if(distanceTravelled_ > range_)
        markForDeletion();
}

void Projectile::move(raylib::Vector2 moveVec)
{
    distanceTravelled_  += moveVec.Length();
    GameObject::move(moveVec);
}
