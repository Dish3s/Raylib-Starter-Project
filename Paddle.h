#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"

class Paddle {
public:
    float x;
    float y;
    int width;
    int height;
    int speed;

    Paddle(float posX, float posY, int w, int h, int spd);

    void Move(bool isLeftPaddle);

    void Move();
    void ClampPosition(float minY, float maxY);
    void Draw();
    void Reset(float posX, float posY, int w, int h, int spd);
};

#endif
