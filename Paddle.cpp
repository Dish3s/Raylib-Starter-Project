#include "Paddle.h"
#include "raylib.h"
#include "raymath.h"

Paddle::Paddle(float posX, float posY, int w, int h, int spd)
    : x(posX), y(posY), width(w), height(h), speed(spd) {}

void Paddle::Move(bool isLeftPaddle) {

    int paddleSpeed = (isLeftPaddle) ? speed : -speed;

    if (isLeftPaddle) {
        if (IsKeyDown(KEY_W))
            y -= paddleSpeed;
        if (IsKeyDown(KEY_S))
            y += paddleSpeed;
    }
    else {
        if (IsKeyDown(KEY_UP))
            y += paddleSpeed;
        if (IsKeyDown(KEY_DOWN))
            y -= paddleSpeed;
    }
}

void Paddle::ClampPosition(float minY, float maxY) {
    y = Clamp(y, minY, maxY);
}

void Paddle::Draw() {
    DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::Reset(float posX, float posY, int w, int h, int spd) {
    x = posX;
    y = posY;
    width = w;
    height = h;
    speed = spd;
}
