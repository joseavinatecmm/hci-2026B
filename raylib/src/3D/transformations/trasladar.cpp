#include "raylib.h"
#include <math.h>

int main(void)
{
    InitWindow(800, 600, "Traslacion 3D Sencilla");
    SetTargetFPS(60);

    Camera3D cam = { 0 };
    cam.position = { 0.0f, 6.0f, 12.0f }; // Posición de la cámara en el espacio
    cam.target = { 0.0f, 0.0f, 0.0f };    // Hacia dónde mira (el centro)
    cam.up = { 0.0f, 1.0f, 0.0f };        // Eje vertical 'arriba'
    cam.fovy = 45.0f;                     // Campo de visión
    cam.projection = CAMERA_PERSPECTIVE;

    Vector2 posicionOriginal = { -3.0f, 0.0f }; // En el plano X, Z (eje horizontal/profundidad)

    while (!WindowShouldClose())
    {
        float Tx = 3.0f + sinf(GetTime() * 2.0f) * 3.0f; 

        Vector3 posicionActual = { posicionOriginal.x + Tx, 0.0f, 0.0f };

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(cam);

        DrawGrid(10, 1.0f);

        DrawCube({ posicionOriginal.x, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, LIGHTGRAY);
        DrawCubeWires({ posicionOriginal.x, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, DARKGRAY);

        DrawCube(posicionActual, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(posicionActual, 2.0f, 2.0f, 2.0f, MAROON);

        EndMode3D();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
