#include "gamemaster.h"
#include <iostream>

GameMaster::GameMaster()
        : screenWidth(1200), screenHeight(1024),
          window(screenWidth, screenHeight, "Asteroids"),
          background_texture("resources/background.png"), ship(),
          bulletCooldown(0.5), timeSinceLastShot(0.0),
          asteroidCooldown(0.5), timeSinceLastAsteroid(0.0),
          lifes(3), loseLifeCooldown(3), timeSinceLastLifeLost(0.0),
          score(0),
          statusFontSize(35),
          gameOverFontSize(50) {
}

void GameMaster::manageGame() {
    // Main game loop
    while (!window.ShouldClose()) {
        BeginDrawing();
        {
            if(game) {
                background_texture.Draw(screenWidth / 2 - background_texture.GetWidth() / 2,
                                        screenHeight / 2 - background_texture.GetHeight() / 2);

                ship.draw();
                createAsteroids();
                handleKeyboardInput();

                timeSinceLastShot += GetFrameTime();
                timeSinceLastAsteroid += GetFrameTime();
                timeSinceLastLifeLost += GetFrameTime();

                for (auto bulletIt = bullets.begin(); bulletIt != bullets.end();) {
                    bulletIt->draw();
                    bulletIt->move();
                    checkColissionAsteroidBullet(bulletIt);
                }

                for (auto asteroidIt = asteroids.begin(); asteroidIt != asteroids.end();) {
                    asteroidIt->draw();
                    asteroidIt->move();

                    checkColissionAsteroidSpaceship(asteroidIt);
                }


                DrawText(("Lifes: " + std::to_string(lifes)).c_str(), 20, 20,
                         statusFontSize, WHITE);
                int scoreTextWidth = MeasureText(("Score: " + std::to_string(score)).c_str(),
                                                 statusFontSize);
                DrawText(("Score: " + std::to_string(score)).c_str(),
                         screenWidth - scoreTextWidth - 20, 20, statusFontSize, WHITE);

                if(lifes == 0) {
                    lifes = 0;
                    game = false;
                }

            } else displayGameOverText();
        }
        EndDrawing();
    }
}

void GameMaster::createAsteroids() {
    if (timeSinceLastAsteroid >= asteroidCooldown) {
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
        ship.rotate("right");
    }
    if (IsKeyDown(KEY_A)) {
        ship.rotate("left");
    }
}

void GameMaster::checkColissionAsteroidSpaceship(std::vector<Asteroid>::iterator& asteroidIt) {
    if (CheckCollisionRecs(ship.dest, asteroidIt->dest)) {
        if(timeSinceLastLifeLost >= loseLifeCooldown) {
            lifes -= 1;
            timeSinceLastLifeLost = 0;
        }

    }
    ++asteroidIt;
}

void GameMaster::checkColissionAsteroidBullet(std::vector<Bullet>::iterator& bulletIt) {
    bool collided = false;
    for (auto asteroidIt = asteroids.begin(); asteroidIt != asteroids.end();) {
        if (CheckCollisionRecs(asteroidIt->dest, bulletIt->dest)) {
            asteroidIt = asteroids.erase(asteroidIt);
            collided = true;
            score += 10;
        } else {
            ++asteroidIt;
        }
    }
    if (collided) {
        bulletIt = bullets.erase(bulletIt);
    } else {
        ++bulletIt;
    }
}

void GameMaster::displayGameOverText() {
    int gameOverTextWidth = MeasureText("Game Over!", gameOverFontSize);
    DrawText("Game Over!", screenWidth/2 - gameOverTextWidth/2,
             screenHeight/2, gameOverFontSize, WHITE);
}