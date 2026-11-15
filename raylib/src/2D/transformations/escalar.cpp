#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Escalamiento 2D - Estatico");
    SetTargetFPS(60);

    Vector2 p1 = { 50.0f,  50.0f };
    Vector2 p2 = { 150.0f, 50.0f };
    Vector2 p3 = { 150.0f, 150.0f };
    Vector2 p4 = { 50.0f,  150.0f };

    float Sx = 2.0f;
    float Sy = 2.0f;

    Vector2 p1_esc = { p1.x * Sx, p1.y * Sy };
    Vector2 p2_esc = { p2.x * Sx, p2.y * Sy };
    Vector2 p3_esc = { p3.x * Sx, p3.y * Sy };
    Vector2 p4_esc = { p4.x * Sx, p4.y * Sy };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dibujar el cuadrado original (gris)
        DrawLineV(p1, p2, GRAY);
        DrawLineV(p2, p3, GRAY);
        DrawLineV(p3, p4, GRAY);
        DrawLineV(p4, p1, GRAY);
        DrawText("Original", p1.x, p1.y - 25, 20, GRAY);

        // Dibujar el cuadrado escalado (rojo)
        DrawLineEx(p1_esc, p2_esc, 3.0f, RED);
        DrawLineEx(p2_esc, p3_esc, 3.0f, RED);
        DrawLineEx(p3_esc, p4_esc, 3.0f, RED);
        DrawLineEx(p4_esc, p1_esc, 3.0f, RED);
        DrawText("Escalado (x2)", p3_esc.x + 10, p3_esc.y, 20, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
