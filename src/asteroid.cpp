#include "asteroid.h"

Asteroid::Asteroid(int screenWidth, int screenHeight)
{
    texture.Load("resources/ohmsteroid.png");
    scale = (GetRandomValue(3, 10)) * 0.1;

    texture.SetHeight(texture.GetHeight() * scale);
    texture.SetWidth(texture.GetWidth() * scale);

    speed = 0.3;

    // Generate random coordinates at the edges of the screen
    float screenOffset = 100; // Adjust this value based on how far off-screen you want the targets

    int edgeSelection = GetRandomValue(0, 1);
    if (edgeSelection == 0) { // Spawn on the top or bottom edge
        x = GetRandomValue(0, screenWidth);
        if (GetRandomValue(0, 1) == 0) {  // top
            y = -screenOffset;
            rotation = GetRandomValue(90, 270);
        } else { // bottom
            y = screenHeight + screenOffset;
            rotation = GetRandomValue(-90.0, 90.0);
        }
    }
    else { // Spawn on the left or right edge
        y = GetRandomValue(0.0, screenHeight);
        if (GetRandomValue(0, 1) == 0) { // left
            x = -screenOffset;
            rotation = GetRandomValue(0, 180.0);
        } else { // right
            x = screenWidth + screenOffset;
            rotation = GetRandomValue(180.0, 360.0);
        }
    }
}
