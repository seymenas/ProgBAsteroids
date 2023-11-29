#pragma once

#include <raylib-cpp.hpp>

class GameObject
{
private:
    raylib::Texture _tex;
    bool _markedForDeletion;

protected:
    float _rot;
    raylib::Vector2 _pos;
    float _scale;

    raylib::Vector2 getOrigin() const;

public:
    GameObject(raylib::Vector2 initialPos, std::string texturePath, float initialScale = 1.f, float initialRot = 0.f);

    virtual ~GameObject();

    virtual void update();

    void draw();

    virtual void rotate(float deg);

    virtual void move(raylib::Vector2 moveVec);

    void markForDeletion();

    bool isMarkedForDeletion() const;

    float getRotation() const;

    raylib::Vector2 getPosition() const;
};