#include "raylib.h"
#include "Paddle.h"
#include "Ball.h"

template<typename T>
T Clamp(T value, T min, T max) {
    return value < min ? min : (value > max ? max : value);
}

enum class GameMode {
    Menu,
    SinglePlayer,
    Multiplayer
};

GameMode ShowMenu() {
    ClearBackground(BLACK);
    DrawText("Press 1 for Single Player", 100, 100, 30, WHITE);
    DrawText("Press 2 for Multiplayer", 100, 150, 30, WHITE);

    if (IsKeyPressed(KEY_ONE))
        return GameMode::SinglePlayer;
    else if (IsKeyPressed(KEY_TWO))
        return GameMode::Multiplayer;
    else
        return GameMode::Menu;
}

int main() {
    const int screenWidth = 1800;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Pong");

    SetTargetFPS(60);

    Ball ball(screenWidth / 2, screenHeight / 2, 10, 8, 8);
    Paddle paddle1(100, screenHeight / 2 - 75, 30, 150, 10);
    Paddle paddle2(1700, screenHeight / 2 - 75, 30, 150, 10);

    GameMode mode = GameMode::Menu;

    while (!WindowShouldClose()) {
        switch (mode) {

        case GameMode::Menu:
            mode = ShowMenu();
            break;

        case GameMode::SinglePlayer:

            // Update
            ball.Move();
            ball.CheckCollisionWithScreen(screenWidth, screenHeight);
            paddle1.y = Clamp<float>(paddle1.y, 0, screenHeight - paddle1.height);

            // Draw
            BeginDrawing();
            ClearBackground(BLACK);
            ball.Draw();
            paddle1.Draw();
            EndDrawing();
            break;

        case GameMode::Multiplayer:

            // Update
            ball.Move();
            ball.CheckCollisionWithScreen(screenWidth, screenHeight);
            paddle1.y = Clamp<float>(paddle1.y, 0, screenHeight - paddle1.height);
            paddle2.y = Clamp<float>(paddle2.y, 0, screenHeight - paddle2.height);

            // Draw
            BeginDrawing();
            ClearBackground(BLACK);
            ball.Draw();
            paddle1.Draw();
            paddle2.Draw();
            EndDrawing();
            break;
        }
    }

    CloseWindow();

    return 0;
}
