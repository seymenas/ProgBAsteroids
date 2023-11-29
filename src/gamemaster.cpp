#include <raylib-cpp.hpp>
#include "gamemaster.h"
#include <iostream>

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
            ship.move();
            ship.draw();
            createAsteroids();
            timeSinceLastShot += GetFrameTime();
            timeSinceLastAsteroid += GetFrameTime();
            handleKeyboardInput();

            for (Bullet & bullet : bullets) {
                bullet.draw();
                bullet.move();

                /*
                if (bullet.get_x() > screenWidth || bullet.get_x() < 0 || bullet.get_y() > screenWidth || bullet.get_y() < 0) {
                    bullets.erase(bullet);
                }
                 */
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
            ship.set_x(ship.get_x() + sin(ship.get_direction() * (M_PI / 180)) * ship.get_speed());
            ship.set_y(ship.get_y() + -cos(ship.get_direction() * (M_PI / 180)) * ship.get_speed());
        }
    }
    if (IsKeyDown(KEY_S)) {
            ship.set_x(ship.get_x() - sin(ship.get_direction() * (M_PI / 180)) * ship.get_speed() / 2);
            ship.set_y(ship.get_y() - -cos(ship.get_direction() * (M_PI / 180)) * ship.get_speed() / 2);
    }
    if (IsKeyDown(KEY_D)) {
            ship.set_direction(ship.get_direction() + 1);
    }
    if (IsKeyDown(KEY_A)) {
            ship.set_direction(ship.get_direction() - 1);
    }
}


