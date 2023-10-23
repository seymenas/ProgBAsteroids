#include <raylib-cpp.hpp>
#include "spaceship.h"

int screenWidth = 1200;
int screenHeight = 1024;


int main() 
{
    raylib::Window window(screenWidth, screenHeight, "raylib [textures] example - image loading");
    raylib::Texture background_texture("resources/background.png");
    Spaceship ship;

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key

        BeginDrawing();
        {
            background_texture.Draw(screenWidth / 2 - background_texture.GetWidth() / 2,
                                    screenHeight / 2 - background_texture.GetHeight() / 2);
            ship.move();
            ship.draw();
        }
        EndDrawing();
    }
    return 0;
}