#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Escalamiento 3D Manual (Estatico)");
    SetTargetFPS(60);

    Camera3D cam = { 0 };
    cam.position = { 0.0f, 8.0f, 16.0f };
    cam.target = { 0.0f, 0.0f, 0.0f };
    cam.up = { 0.0f, 1.0f, 0.0f };
    cam.fovy = 45.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    // definir dimensiones iniciales y factor de escala
    float ladoInicial = 2.0f;
    float factorEscala = 2.5f;

    // matemática del escalamiento manualmente (S * dimensión)
    float ladoFinal = ladoInicial * factorEscala;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);

        DrawGrid(20, 1.0f);

        // Objeto 1: Cubo Original (Izquierda)
        DrawCube({ -4.0f, 0.0f, 0.0f }, ladoInicial, ladoInicial, ladoInicial, LIGHTGRAY);
        DrawCubeWires({ -4.0f, 0.0f, 0.0f }, ladoInicial, ladoInicial, ladoInicial, DARKGRAY);

        // Objeto 2: Cubo Escalado (Derecha) usando la nueva dimensión calculada
        DrawCube({ 4.0f, 0.0f, 0.0f }, ladoFinal, ladoFinal, ladoFinal, ORANGE);
        DrawCubeWires({ 4.0f, 0.0f, 0.0f }, ladoFinal, ladoFinal, ladoFinal, BLACK);

        EndMode3D();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
