#include "raylib.h"
#include <deque>

constexpr int CELL = 24;
constexpr int COLS = 30;
constexpr int ROWS = 22;
constexpr int WIDTH = COLS * CELL;
constexpr int HEIGHT = ROWS * CELL;

struct Cell { int x; int y; };

bool same(Cell a, Cell b) { return a.x == b.x && a.y == b.y; }

int main() {
    InitWindow(WIDTH, HEIGHT, "C++ Snake");
    SetTargetFPS(60);

    std::deque<Cell> snake{{COLS / 2, ROWS / 2}, {COLS / 2 - 1, ROWS / 2}, {COLS / 2 - 2, ROWS / 2}};
    Cell direction{1, 0};
    Cell food{COLS - 5, ROWS / 2};
    float timer = 0.0f;
    const float step = 0.12f;
    bool gameOver = false;
    int score = 0;

    while (!WindowShouldClose()) {
        if (gameOver && IsKeyPressed(KEY_R)) {
            snake = {{COLS / 2, ROWS / 2}, {COLS / 2 - 1, ROWS / 2}, {COLS / 2 - 2, ROWS / 2}};
            direction = {1, 0}; food = {COLS - 5, ROWS / 2};
            score = 0; timer = 0.0f; gameOver = false;
        }

        if (!gameOver) {
            Cell next = direction;
            if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) && direction.y != 1) next = {0, -1};
            if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && direction.y != -1) next = {0, 1};
            if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) && direction.x != 1) next = {-1, 0};
            if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) && direction.x != -1) next = {1, 0};
            direction = next;

            timer += GetFrameTime();
            if (timer >= step) {
                timer = 0.0f;
                Cell head{snake.front().x + direction.x, snake.front().y + direction.y};
                const bool eats = same(head, food);
                bool hit = head.x < 0 || head.x >= COLS || head.y < 0 || head.y >= ROWS;
                for (std::size_t i = 0; i < snake.size() - (eats ? 0 : 1); ++i)
                    if (same(head, snake[i])) hit = true;

                if (hit) gameOver = true;
                else {
                    snake.push_front(head);
                    if (eats) {
                        ++score;
                        food = {GetRandomValue(0, COLS - 1), GetRandomValue(0, ROWS - 1)};
                        for (const Cell part : snake) if (same(food, part)) food = {0, 0};
                    } else snake.pop_back();
                }
            }
        }

        BeginDrawing();
        ClearBackground(Color{18, 22, 30, 255});
        DrawText(TextFormat("SCORE: %i", score), 12, 10, 20, RAYWHITE);
        DrawRectangle(food.x * CELL, food.y * CELL, CELL - 2, CELL - 2, RED);
        for (std::size_t i = 0; i < snake.size(); ++i) {
            const Cell part = snake[i];
            DrawRectangle(part.x * CELL, part.y * CELL, CELL - 2, CELL - 2,
                          i == 0 ? LIME : GREEN);
        }
        if (gameOver) {
            DrawRectangle(0, HEIGHT / 2 - 42, WIDTH, 84, Color{0, 0, 0, 190});
            DrawText("GAME OVER", WIDTH / 2 - 95, HEIGHT / 2 - 28, 32, RAYWHITE);
            DrawText("Press R to restart", WIDTH / 2 - 90, HEIGHT / 2 + 10, 18, LIGHTGRAY);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
