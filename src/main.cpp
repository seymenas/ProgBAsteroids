#include <raylib-cpp.hpp>

int main() 
{
    int screenWidth = 1280;
    int screenHeight = 1024;

    raylib::Window window(screenWidth, screenHeight, "raylib [textures] example - image loading");
    raylib::Texture texture("resources/background.png");

    // Main game loop
    while (!window.ShouldClose()) {    // Detect window close button or ESC key

        BeginDrawing();
        {
            texture.Draw(screenWidth / 2 - texture.GetWidth() / 2, screenHeight / 2 - texture.GetHeight() / 2);
        }
        EndDrawing();
    }
    return 0;
}