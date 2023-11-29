#include "asteroid.h"
#include "gamemanager.h"

#include <sstream>
#include <iomanip>

Asteroid::Asteroid(raylib::Vector2 initialPos, float initialRot, Size initialSize, raylib::Vector2 initialVelocity)
: GameObject(initialPos, _texturePath, 1.f, initialRot)
, _size(initialSize)
, _velocity(initialVelocity)
{
    updateScale();
}

void Asteroid::updateScale()
{
    switch(_size) 
    {
        case Size::SMALL:
            _scale = .2f;
            break;

        case Size::MEDIUM:
            _scale = .5f;
            break;

        case Size::BIG:
            _scale = .8f;
            break;
    }
}

void Asteroid::update()
{
    rotate(2);
    move(_velocity);
    GameObject::update();
}

Asteroid::Size Asteroid::getSize() const
{
    return _size;
}
