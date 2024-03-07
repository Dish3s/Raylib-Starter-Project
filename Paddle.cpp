#include "Paddle.h"

Paddle::Paddle(float posX, float posY, int w, int h, int spd)
    : x(posX), y(posY), width(w), height(h), speed(spd) {}

void Paddle::MoveUp() {
    y -= speed;
}

void Paddle::MoveDown() {
    y += speed;
}

void Paddle::Draw() {
    DrawRectangle(x, y, width, height, WHITE);
}
