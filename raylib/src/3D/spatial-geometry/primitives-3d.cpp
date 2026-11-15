#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Figuras 3D y Modalidades de Renderizado");
    SetTargetFPS(60);

    Camera3D cam = { 0 };
    cam.position = { 0.0f, 14.0f, 14.0f };
    cam.target = { 0.0f, 0.0f, 0.0f };
    cam.up = { 0.0f, 1.0f, 0.0f };
    cam.fovy = 45.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);

        // Cubo
        DrawCube({ -4.0f, 0.0f, -4.5f }, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires({ 0.0f, 0.0f, -4.5f }, 2.0f, 2.0f, 2.0f, MAROON);
        DrawCube({ 4.0f, 0.0f, -4.5f }, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires({ 4.0f, 0.0f, -4.5f }, 2.0f, 2.0f, 2.0f, BLACK);

        // Esfera
        DrawSphere({ -4.0f, 0.0f, -1.5f }, 1.2f, BLUE);
        DrawSphereWires({ 0.0f, 0.0f, -1.5f }, 1.2f, 16, 16, DARKBLUE);
        DrawSphere({ 4.0f, 0.0f, -1.5f }, 1.2f, BLUE);
        DrawSphereWires({ 4.0f, 0.0f, -1.5f }, 1.2f, 16, 16, BLACK);

        // Cilindro
        DrawCylinder({ -4.0f, -1.0f, 1.5f }, 1.0f, 1.0f, 2.0f, 16, GREEN);
        DrawCylinderWires({ 0.0f, -1.0f, 1.5f }, 1.0f, 1.0f, 2.0f, 16, DARKGREEN);
        DrawCylinder({ 4.0f, -1.0f, 1.5f }, 1.0f, 1.0f, 2.0f, 16, GREEN);
        DrawCylinderWires({ 4.0f, -1.0f, 1.5f }, 1.0f, 1.0f, 2.0f, 16, BLACK);

        // Cono (Cilindro con radio superior en 0)
        DrawCylinder({ -4.0f, -1.0f, 4.5f }, 0.0f, 1.2f, 2.0f, 16, ORANGE);
        DrawCylinderWires({ 0.0f, -1.0f, 4.5f }, 0.0f, 1.2f, 2.0f, 16, BROWN);
        DrawCylinder({ 4.0f, -1.0f, 4.5f }, 0.0f, 1.2f, 2.0f, 16, ORANGE);
        DrawCylinderWires({ 4.0f, -1.0f, 4.5f }, 0.0f, 1.2f, 2.0f, 16, BLACK);

        EndMode3D();

        DrawText("Relleno", 120, 30, 20, DARKGRAY);
        DrawText("Malla de Alambre", 310, 30, 20, DARKGRAY);
        DrawText("Relleno + Marco", 560, 30, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
