#include "Ball.h"

Ball::Ball(float posX, float posY, int rad, int spdX, int spdY)
    : x(posX), y(posY), radius(rad), speedX(spdX), speedY(spdY) {}

void Ball::Move() {
    x += speedX;
    y += speedY;
}

void Ball::CheckCollisionWithScreen(float screenWidth, float screenHeight) {
    if ((x + radius >= screenWidth) || (x - radius <= 0)) {
        speedX = -speedX;
    }
    if (y + radius >= screenHeight || y - radius <= 0) {
        speedY = -speedY;
    }
}

void Ball::Draw() {
    DrawCircle(x, y, radius, RED);
}
