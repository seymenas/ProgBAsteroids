#include "gamemanager.h"

#include <raylib-cpp.hpp>
#include <vector>

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 1024;
    const int numAsteroids = 6;
    const int asteroidSpawnCoolDown = 3;
    int timeOfLastAsteroidSpawned = 0;

    raylib::Window window(screenWidth, screenHeight, "B:ME PROG3 Asteroids");
    raylib::Texture background("resources/background.png");

    SetTargetFPS(60);

    GameManager manager;

    for (int i = 0; i < numAsteroids; i++)
    {
        manager.spawnAsteroid();
    }
    manager.spawnSpaceship();

    while (!window.ShouldClose())
    {
        BeginDrawing();
        window.ClearBackground(RAYWHITE);
        background.Draw(raylib::Vector2(0, 0));
        manager.drawObjects();
        manager.drawHud();
        if(manager.getGameStatus())
        {
            manager.update();
            manager.checkCollisions();
            if((int) GetTime() % asteroidSpawnCoolDown == 0 && timeOfLastAsteroidSpawned != (int) GetTime()) {
                manager.spawnAsteroid();
                timeOfLastAsteroidSpawned = (int) GetTime();
            }
        } else {
            manager.displayGameOverText();
        }
        EndDrawing();
    }
    return 0;
}