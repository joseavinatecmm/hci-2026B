#include "raylib.h"
#include "rlgl.h"
#include <math.h>

int main(void)
{
    InitWindow(800, 600, "Escalamiento 3D Oscilante");
    SetTargetFPS(60);

    Camera3D cam = { 0 };
    cam.position = { 0.0f, 6.0f, 10.0f };
    cam.target = { 0.0f, 0.0f, 0.0f };
    cam.up = { 0.0f, 1.0f, 0.0f };
    cam.fovy = 45.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        // Factor oscilante: Offset de 1.5 y amplitud de 1.0 (escala va de 0.5 a 2.5)
        float escala = 1.5f + sinf(GetTime() * 2.0f) * 1.0f;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);
        
        DrawGrid(10, 1.0f);

        rlPushMatrix();
        
        // Multiplica el tamaño original del objeto en los ejes X, Y y Z
        rlScalef(escala, escala, escala);
        
        DrawCube({ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, ORANGE);
        DrawCubeWires({ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, BLACK);
        
        rlPopMatrix();

        EndMode3D();
        
        DrawText("Escalamiento 3D Oscilante", 10, 10, 20, DARKGRAY);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
