#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "Paddle.h"

class Ball {
public:
    float x;
    float y;
    float radius;
    float speedX;
    float speedY;

    Ball(float posX, float posY, float rad, float spdX, float spdY);

    void Move();
    void CheckCollisionWithScreen(int screenWidth, int screenHeight);
    void CheckCollisionWithPaddle(const Paddle& paddle);
    void Draw();
    void Reset(float posX, float posY, float initialSpeedX, float initialSpeedY);

};

#endif
