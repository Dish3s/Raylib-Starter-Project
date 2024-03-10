#include "raylib.h"
#include "Paddle.h"
#include "Ball.h"

enum class GameMode {
    Menu,
    SinglePlayer,
    Multiplayer
};

GameMode ShowMenu() {
    static bool keyWasPressed = false;

    ClearBackground(static_cast<Color>(BLACK));

    // Calculate center positions
    int centerX = GetScreenWidth() / 2;
    int centerY = GetScreenHeight() / 2;

    // Draw title
    DrawText("PONG", centerX - MeasureText("PONG", 40) / 2, centerY - 100, 40, WHITE);

    // Draw menu options
    DrawText("Press 1 for Single Player", centerX - MeasureText("Press 1 for Single Player", 30) / 2, centerY, 30, WHITE);
    DrawText("Press 2 for Multiplayer", centerX - MeasureText("Press 2 for Multiplayer", 30) / 2, centerY + 50, 30, WHITE);

    if (IsKeyPressed(KEY_ONE) && !keyWasPressed) {
        keyWasPressed = true;
        return GameMode::SinglePlayer;
    }
    else if (IsKeyPressed(KEY_TWO) && !keyWasPressed) {
        keyWasPressed = true;
        return GameMode::Multiplayer;
    }
    else if (!IsKeyDown(KEY_ONE) && !IsKeyDown(KEY_TWO)) {
        keyWasPressed = false;
    }

    return GameMode::Menu;
}

int main() {
    const int screenWidth = 1800;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Pong");

    SetTargetFPS(60);

    Ball ball(static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f, 10, 8, 8);
    Paddle paddle1(100.0f, static_cast<float>(screenHeight) / 2.0f - 75.0f, 30, 150, 10);
    Paddle paddle2(1700.0f, static_cast<float>(screenHeight) / 2.0f - 75.0f, 30, 150, 10);

    GameMode mode = GameMode::Menu;

    int scorePlayer1 = 0;
    int scorePlayer2 = 0;

    while (!WindowShouldClose()) {
        // Process events
        if (mode == GameMode::Menu) {
            mode = ShowMenu();
        }
        else if (mode == GameMode::SinglePlayer || mode == GameMode::Multiplayer) {
            // Update
            ball.Move();
            ball.CheckCollisionWithScreen(screenWidth, screenHeight);
            paddle1.Move(true); // Pass true for the left paddle
            paddle1.ClampPosition(0, screenHeight - paddle1.height);

            if (mode == GameMode::Multiplayer) {
                paddle2.Move(false); // Pass false for the right paddle
                paddle2.ClampPosition(0, screenHeight - paddle2.height);
            }
            else {
                // AI controls the right paddle
                paddle2.y = ball.y - paddle2.height / 2;
            }

            // Check collision with the paddles
            ball.CheckCollisionWithPaddle(paddle1);
            ball.CheckCollisionWithPaddle(paddle2);

            // Check for scoring
            if (ball.x - ball.radius <= 0) {
                scorePlayer2++;
                if (scorePlayer2 >= 10) {
                    // Player 2 wins
                    // Add winning condition handling here
                    // Reset scores and game elements for the next round
                    scorePlayer1 = 0;
                    scorePlayer2 = 0;
                    ball.Reset(static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f, 8, 8);
                    paddle1.Reset(100.0f, static_cast<float>(screenHeight) / 2.0f - 75.0f, 30, 150, 10);
                    paddle2.Reset(1700.0f, static_cast<float>(screenHeight) / 2.0f - 75.0f, 30, 150, 10);
                    mode = GameMode::Menu; // Go back to the menu after a game ends
                }
                else {
                    // Reset ball for the next round
                    ball.Reset(static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f, 8, 8);
                }
            }
            else if (ball.x + ball.radius >= screenWidth) {
                // Player 1 scores
                scorePlayer1++;
                if (scorePlayer1 >= 10) {
                    // Player 1 wins
                    // Add winning condition handling here
                    // Reset scores and game elements for the next round
                    scorePlayer1 = 0;
                    scorePlayer2 = 0;
                    ball.Reset(static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f, 8, 8);
                    paddle1.Reset(100.0f, static_cast<float>(screenHeight) / 2.0f - 75.0f, 30, 150, 10);
                    paddle2.Reset(1700.0f, static_cast<float>(screenHeight) / 2.0f - 75.0f, 30, 150, 10);
                    mode = GameMode::Menu; // Go back to the menu after a game ends
                }
                else {
                    // Reset ball for the next round
                    ball.Reset(static_cast<float>(screenWidth) / 2.0f, static_cast<float>(screenHeight) / 2.0f, 8, 8);
                }
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(static_cast<Color>(BLACK));

        if (mode == GameMode::SinglePlayer || mode == GameMode::Multiplayer) {
            // Draw dotted line
            for (int i = 0; i < screenHeight; i += 20) {
                DrawRectangle(screenWidth / 2 - 1, i, 2, 10, WHITE);
            }

            ball.Draw();
            paddle1.Draw();
            paddle2.Draw();
        }

        // Draw scores
        DrawText(TextFormat("%02d", scorePlayer1), screenWidth / 2 - 50, 20, 40, WHITE);
        DrawText(TextFormat("%02d", scorePlayer2), screenWidth / 2 + 20, 20, 40, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
