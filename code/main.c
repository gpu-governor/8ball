#include "raylib.h"
#include<stdio.h>

const int width = 1280;
const int height = 720;

// Global Texture variables
Texture2D table;
Texture2D stick;
Texture2D triangle;
Texture2D balls[16]; // Array to hold ball textures

void load_balls();
void draw_balls();

int main() {
    InitWindow(width, height, "8 Ball Pool");
    SetTargetFPS(60);

    // Load textures
    table = LoadTexture("Assets/table.png");
    stick = LoadTexture("Assets/cue.png");
    triangle = LoadTexture("Assets/triangle.png");

    load_balls(); // Load ball textures

    // Main loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);

        // Draw the textures
        DrawTextureEx(table, (Vector2){100, 100}, 0.0f, 0.2f, WHITE);
        draw_balls();
        DrawTextureEx(triangle, (Vector2){100, 100}, 0.0f, 0.2f, WHITE);
        DrawTextureEx(stick, (Vector2){100, 100}, 0.0f, 0.2f, WHITE);

        EndDrawing();
    }

    // Unload textures
    UnloadTexture(table);
    UnloadTexture(stick);
    UnloadTexture(triangle);
    for (int i = 0; i < 16; i++) {
        UnloadTexture(balls[i]);
    }

    CloseWindow();
    return 0;
}

void load_balls() {
    // Load ball textures into the array
    for (int i = 0; i < 16; i++) {
        char filename[30];
        printf(filename, sizeof(filename), "Assets/ball_%d.png", i + 1);
        balls[i] = LoadTexture(filename);
    }
}

void draw_balls() {
    // Draw the balls at specific positions
    for (int i = 0; i < 16; i++) {
        DrawTextureEx(balls[i], (Vector2){100 + i * 30, 100}, 0.0f, 0.2f, WHITE);
    }
}
