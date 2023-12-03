#include "bullet.h"

Bullet::Bullet(float start_x, float start_y, float start_direction)
{
    texture.Load("resources/bullet.png");
    x = start_x;
    y = start_y;
    rotation = start_direction;
    speed = 1.2;
}
