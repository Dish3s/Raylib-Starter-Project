#include "raylib.h"
#include <iostream>

using namespace std;

int main() {

    //Screen Size
    float screenWidth = 1800;
    float screenHeight = 1000;

    //Ball Spawn
    int ballX = screenWidth / 2;
    int ballY = screenHeight / 2;

    //Ball Size
    int ballRadius = 10;

    //Ball Speed
    int ballSpeedX = 8;
    int ballSpeedY = 8;

    //Position and speed for the rectangles
    int rect1X = 100;
    int rect1Y = screenHeight / 2 - 75; 

    int rect2X = 1700;
    int rect2Y = screenHeight / 2 - 75; 

    //Rectangle Size
    int rectWidth = 30;
    int rectHeight = 150;

    //Rectangle Speed
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
        if (ballY + ballRadius >= screenHeight) {
            ballSpeedY = -ballSpeedY;
        }
        if (ballY - ballRadius <= 0) {
            ballSpeedY = -ballSpeedY;
        }

        // Ball collision with rectangles
        if ((ballX + ballRadius >= rect1X) && (ballX - ballRadius <= rect1X + rectWidth) && (ballY + ballRadius >= rect1Y) && (ballY - ballRadius <= rect1Y + rectHeight)) {
            ballSpeedX = -ballSpeedX;
        }
        if ((ballX + ballRadius >= rect2X) && (ballX - ballRadius <= rect2X + rectWidth) && (ballY + ballRadius >= rect2Y) && (ballY - ballRadius <= rect2Y + rectHeight)) {
            ballSpeedX = -ballSpeedX;
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

        //UI
        DrawTextEx(ft, "Let's smack some balls :)", Vector2{ 720, 50 }, 30, 2, WHITE);
        DrawTextEx(ft, TextFormat("0"), Vector2{ 520, 50 }, 50, 2, WHITE);
        DrawTextEx(ft, TextFormat("0"), Vector2{ 1280, 50 }, 50, 2, WHITE);

        for (float i = 0; i < screenHeight; i += 100) {
            DrawLineEx(Vector2{ screenWidth / 2, i }, Vector2{ screenWidth / 2, i + 50 }, 5, WHITE);
        }

        //Ball
        DrawCircle(ballX, ballY, ballRadius, RED);

        //Paddles
        DrawRectangle(100, rect1Y, 30, 150, WHITE);
        DrawRectangle(1700, rect2Y, 30, 150, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
