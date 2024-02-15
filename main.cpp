#include "raylib.h"
#include <iostream>

using namespace std;

int main() {

    int screenWidth = 1800;
    int screenHeight = 1000;

    int ballX = screenWidth / 2;
    int ballY = screenHeight / 2;

    int ballRadius = 10;

    int ballSpeedX = 8;
    int ballSpeedY = 8;

    bool IsKeyPressed(int key);             // Check if a key has been pressed once
    bool IsKeyDown(int key);                // Check if a key is being pressed
    bool IsKeyReleased(int key);            // Check if a key has been released once
    bool IsKeyUp(int key);                  // Check if a key is NOT being pressed
    void SetExitKey(int key);               // Set a custom key to exit program (default is ESC)
    int GetKeyPressed();                    // Get key pressed (keycode), call it multiple times for keys queued, returns 0 when queue is empty 
    int GetCharPressed();                   // Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty



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

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTextEx(ft, "Let's smack some balls :)", Vector2{ 720, 50 }, 30, 2, WHITE);
        DrawCircle(ballX, ballY, ballRadius, RED);
        DrawLineStrip(Vector2 *, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
