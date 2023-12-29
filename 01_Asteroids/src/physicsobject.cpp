#include "physicsobject.h"

#include <sstream>
#include <iomanip>

PhysicsObject::PhysicsObject(raylib::Vector2 initialPos, std::string texturePath, float initialScale,
                             float initialRot)
                             : GameObject(initialPos, texturePath, initialScale, initialRot)
                             {

}

void PhysicsObject::set_speed(raylib::Vector2 new_speed) {
    speed = new_speed;
}

void PhysicsObject::update() {
    float dt = 1.0/60.0;                                                     // Zeit zwischen zwei Frames
    speed = speed + acceleration * dt;    // Beschleunigung
    speed = speed - speed * friction;   // Reibung
    move(speed);                                           // Position aktualisieren
    acceleration = 0;                                              // Beschleunigung zurücksetzen
}

void PhysicsObject::accelerate(raylib::Vector2 new_acceleration) {
    acceleration = new_acceleration;
}