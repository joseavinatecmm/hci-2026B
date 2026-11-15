#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Traslacion 2D");
    SetTargetFPS(60);

    Vector2 p = { 100.0f, 100.0f };

    float Tx = 150.0f;
    float Ty = 100.0f;

    Vector2 pActual = { p.x + Tx, p.y + Ty };

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) Tx += 4.0f;
        if (IsKeyDown(KEY_LEFT))  Tx -= 4.0f;
        if (IsKeyDown(KEY_UP))    Ty -= 4.0f;
        if (IsKeyDown(KEY_DOWN))  Ty += 4.0f;

        // Recalcular la nueva posición en cada frame basada en el Tx y Ty actualizados
        pActual = { p.x + Tx, p.y + Ty };

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Dibujar el punto final P' resultante de la suma de traslación
        DrawCircleV(pActual, 10, RED);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
