#include "raylib.h"
#include <math.h>

int main(void)
{
    InitWindow(800, 600, "Rotacion 2D Pura (Sin Pivote)");
    SetTargetFPS(60);

    Vector2 p = { 120.0f, 80.0f };

    // ángulo theta en radianes (aprox 17 grados) para que la rotación sea sutil
    float theta = 0.4f; 

    float x_rot = p.x * cosf(theta) - p.y * sinf(theta);
    float y_rot = p.x * sinf(theta) + p.y * cosf(theta);
    Vector2 p_rotada = { x_rot, y_rot };

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dibujar el punto original P
        DrawCircleV(p, 8, DARKBLUE);
        DrawText("P(x, y) original", p.x + 15, p.y - 10, 16, DARKBLUE);

        // Dibujar el punto rotado P' (girado respecto al origen 0,0 de la pantalla)
        DrawCircleV(p_rotada, 8, RED);
        DrawText("P'(x_rot, y_rot) rotado", p_rotada.x + 15, p_rotada.y + 10, 16, RED);

        // Mostrar la trayectoria del giro desde el origen (0,0)
        DrawLineV({0, 0}, p, LIGHTGRAY);
        DrawLineV({0, 0}, p_rotada, LIGHTGRAY);
        DrawCircle(0, 0, 5, BLACK);
        DrawText("(0,0) Origen de la pantalla", 10, 15, 14, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
