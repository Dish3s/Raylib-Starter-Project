#include "Ball.h"
#include "raylib.h"

Ball::Ball(float posX, float posY, float rad, float spdX, float spdY)
    : x(posX), y(posY), radius(rad), speedX(spdX), speedY(spdY) {}

void Ball::Move() {
    x += speedX;
    y += speedY;
}

void Ball::CheckCollisionWithScreen(int screenWidth, int screenHeight) {
    if ((y - radius) <= 0 || (y + radius) >= screenHeight) {
        speedY = -speedY;
    }
}

void Ball::CheckCollisionWithPaddle(const Paddle& paddle) {
    if ((x + radius) >= paddle.x &&
        (x - radius) <= (paddle.x + paddle.width) &&
        (y + radius) >= paddle.y &&
        (y - radius) <= (paddle.y + paddle.height)) {
        speedX = -speedX;
    }
}

void Ball::Draw() {
    DrawCircle(x, y, radius, WHITE);
}

void Ball::Reset(float posX, float posY, float initialSpeedX, float initialSpeedY) {
    x = posX;
    y = posY;
    speedX = initialSpeedX;
    speedY = initialSpeedY;
}
