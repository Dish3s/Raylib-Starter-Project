#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball {
public:
    float x;
    float y;
    int radius;
    int speedX;
    int speedY;

    Ball(float posX, float posY, int rad, int spdX, int spdY);

    void Move();
    void CheckCollisionWithScreen(float screenWidth, float screenHeight);
    void Draw();
};

#endif
