#include <raylib-cpp.hpp>
#include "gamemaster.h"

GameMaster::GameMaster()
        : screenWidth(1200), screenHeight(1024),
          window(screenWidth, screenHeight, "Asteroids"),
          background_texture("resources/background.png"), ship(), bulletCooldown(0.5),
          timeSinceLastShot(0.0), asteroidCooldown(1),
          timeSinceLastAsteroid(0.0) {
}

void GameMaster::manageGame() {
    // Main game loop
    while (!window.ShouldClose()) {
        BeginDrawing();
        {
            background_texture.Draw(screenWidth / 2 - background_texture.GetWidth() / 2,
                                    screenHeight / 2 - background_texture.GetHeight() / 2);
            ship.draw();
            createAsteroids();

            handleKeyboardInput();

            timeSinceLastShot += GetFrameTime();
            timeSinceLastAsteroid += GetFrameTime();

            for (Bullet & bullet : bullets) {
                bullet.draw();
                bullet.move();
            }

            for (Asteroid & asteroid : asteroids) {
                asteroid.draw();
                asteroid.move();
            }
        }
        EndDrawing();
    }
}

void GameMaster::createAsteroids() {
    if(timeSinceLastAsteroid >= asteroidCooldown) {
        asteroids.emplace_back(screenWidth, screenHeight);
        timeSinceLastAsteroid = 0.0;
    }
}

void GameMaster::handleKeyboardInput() {
    if (IsKeyDown(KEY_SPACE) && timeSinceLastShot >= bulletCooldown) {
        bullets.emplace_back(ship.shoot());
        timeSinceLastShot = 0.0;
    }

    //MOVE
    if (ship.get_y() > 0 && ship.get_y() < screenHeight && ship.get_x() > 0 && ship.get_x() < screenWidth) {
        if (IsKeyDown(KEY_W)) {
            ship.move("forward");
        }
    }
    if (IsKeyDown(KEY_S)) {
        ship.move("backward");
    }
    if (IsKeyDown(KEY_D)) {
        ship.move("right");
    }
    if (IsKeyDown(KEY_A)) {
        ship.move("left");
    }
}


