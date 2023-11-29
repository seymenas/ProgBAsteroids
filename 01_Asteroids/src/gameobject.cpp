#include "gameobject.h"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>

GameObject::GameObject(raylib::Vector2 initialPos, std::string texturePath, float initialScale, float initialRot)
: _pos(initialPos)
, _tex(texturePath)
, _scale(initialScale)
, _rot(initialRot)
, _markedForDeletion(false)
{}

GameObject::~GameObject()
{}

raylib::Vector2 GameObject::getOrigin() const
{
    return raylib::Vector2 { static_cast<float>(_tex.GetWidth() * _scale/2), static_cast<float>(_tex.GetHeight() * _scale /2) };
}

void GameObject::draw()
{
    // Easy version: Draw object with rotation around origin (top left)
    //_tex.Draw(_pos, _rot);

    // Slightly more advanced version: Draw object with rotation around center
    raylib::Vector2 origin = raylib::Vector2(_tex.GetWidth() * _scale / 2, _tex.GetWidth() * _scale / 2);
    raylib::Rectangle sourceRect = { 0.f, 0.f, static_cast<float>(_tex.GetWidth()), static_cast<float>(_tex.GetHeight()) };
    raylib::Rectangle destRect = { _pos.GetX(), _pos.GetY(), static_cast<float>(_tex.GetWidth()) * _scale, static_cast<float>(_tex.GetHeight()) * _scale };
    _tex.Draw(sourceRect, destRect, origin, _rot);
}

void GameObject::update()
{
}

void GameObject::rotate(float deg)
{
    _rot += deg;
}

void GameObject::move(raylib::Vector2 moveVec)
{
    _pos += moveVec;
    if(_pos.x < 0.f)
        _pos.x = GetScreenWidth();
    else if(_pos.x > GetScreenWidth())
        _pos.x = 0.f;
    if(_pos.y < 0.f)
        _pos.y = GetScreenHeight();
    else if(_pos.y > GetScreenHeight())
        _pos.y = 0.f;
}

float GameObject::getRotation() const
{
    return _rot;
}

raylib::Vector2 GameObject::getPosition() const
{
    return _pos;
}

void GameObject::markForDeletion()
{
    _markedForDeletion = true;
}

bool GameObject::isMarkedForDeletion() const
{
    return _markedForDeletion;
}
