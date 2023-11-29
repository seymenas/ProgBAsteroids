#include <raylib-cpp.hpp>
#include "asteroid.h"

Asteroid::Asteroid(int screenWidth, int screenHeight)
{
    texture.Load("resources/ohmsteroid.png");
    scale = (GetRandomValue(3, 10)) * 0.1;

    texture.SetHeight(texture.GetHeight() * scale);
    texture.SetWidth(texture.GetWidth() * scale);

    speed = 0.3;

    // Generate random coordinates at the edges of the screen
    float screenOffset = 50; // Adjust this value based on how far off-screen you want the targets

    int edgeSelection = GetRandomValue(0, 1);
    if (edgeSelection == 0) { // Spawn on the top or bottom edge
        x = GetRandomValue(0, screenWidth);
        if (GetRandomValue(0, 1) == 0) {  // top
            y = -screenOffset;
            direction = GetRandomValue(90, 270);
        } else { // bottom
            y = screenHeight + screenOffset;
            direction = GetRandomValue(-90.0, 90.0);
        }
    }
// Spawn on the left or right edge
    else {
        if (GetRandomValue(0, 1) == 0) { // left
            x = -screenOffset;
            direction = GetRandomValue(0, 180.0);
        } else { // right
            x = screenWidth + screenOffset;
            direction = GetRandomValue(180.0, 360.0);
        }
        x = GetRandomValue(0.0, screenHeight);
    }
}



void Asteroid::move() {
    // Move the bullet based on its velocity
    x += sin(direction * (M_PI / 180)) * speed;
    y += -cos(direction * (M_PI / 180)) * speed;

}

void Asteroid::draw() {
    raylib::Rectangle source(0, 0, texture.GetWidth(), texture.GetHeight());
    raylib::Rectangle dest(x, y, texture.GetWidth(), texture.GetHeight());
    DrawTexturePro(texture, source, dest, Vector2{(float) texture.GetWidth() / 2,
                                                  (float) texture.GetHeight() / 2}, direction, WHITE);

    /*
    // Draw the bullet
    raylib::Rectangle sourceRect = { 0.f, 0.f, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    raylib::Rectangle destRect = { x, y, static_cast<float>(texture.GetWidth()), static_cast<float>(texture.GetHeight()) };
    raylib::Vector2 origin = raylib::Vector2(texture.GetWidth() / 2, texture.GetHeight() / 2);
    texture.Draw(sourceRect, destRect, origin, 0.0f, raylib::WHITE);
     */
}
