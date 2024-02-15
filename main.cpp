#include "raylib.h"
#include <iostream>

using namespace std;

int main() {

    float screenWidth = 1800;
    float screenHeight = 1000;

    int ballX = screenWidth / 2;
    int ballY = screenHeight / 2;

    int ballRadius = 10;

    int ballSpeedX = 8;
    int ballSpeedY = 8;

    int rect1Y = screenHeight / 2 - 75; 
    int rect2Y = screenHeight / 2 - 75; 
    int rectSpeed = 10; 

    InitWindow(screenWidth, screenHeight, "My first Raylib window!");
    SetTargetFPS(60);

    Font ft = LoadFont("resources/fonts/romulus.png");

    while (!WindowShouldClose()) {
        ballX += ballSpeedX;
        ballY += ballSpeedY;

 
        if ((ballX + ballRadius >= screenWidth) || (ballX - ballRadius <= 0)) {
            ballSpeedX = -ballSpeedX;
        }
        if ((ballY + ballRadius >= screenHeight) || (ballY - ballRadius <= 0)) {
            ballSpeedY = -ballSpeedY;
        }

        //Player 1
        if (IsKeyDown(KEY_W)) {
            rect1Y -= rectSpeed;
        }
        if (IsKeyDown(KEY_S)) {
            rect1Y += rectSpeed;
        }

        //Player 2
        if (IsKeyDown(KEY_UP)) {
            rect2Y -= rectSpeed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            rect2Y += rectSpeed;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextEx(ft, "Let's smack some balls :)", Vector2{ 720, 50 }, 30, 2, WHITE);
        DrawCircle(ballX, ballY, ballRadius, RED);

        for (float i = 0; i < screenHeight; i += 100) {
            DrawLineEx(Vector2{ screenWidth / 2, i }, Vector2{screenWidth/2, i+50}, 5, WHITE);
        }

        DrawRectangle(100, rect1Y, 30, 150, WHITE);
        DrawRectangle(1700, rect2Y, 30, 150, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
