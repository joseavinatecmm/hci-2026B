#include "raylib.h"

int main(void)
{
    InitWindow(800, 600, "Modificando la Camara 3D");
    SetTargetFPS(60);

    Camera3D cam = { 0 };
    cam.position = { 0.0f, 4.0f, 10.0f };
    cam.target = { 0.0f, 0.0f, 0.0f };
    cam.up = { 0.0f, 1.0f, 0.0f };
    cam.fovy = 45.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        // 1. Modificar POSITION (Mover la cámara físicamente en el eje X)
        if (IsKeyDown(KEY_RIGHT)) cam.position.x += 0.2f;
        if (IsKeyDown(KEY_LEFT))  cam.position.x -= 0.2f;

        // 2. Modificar TARGET (Cambiar hacia dónde mira en el eje Y)
        if (IsKeyDown(KEY_UP))   cam.target.y += 0.2f;
        if (IsKeyDown(KEY_DOWN)) cam.target.y -= 0.2f;

        // 3. Modificar FOVY (Efecto de Zoom o lente angular)
        if (IsKeyDown(KEY_Z)) cam.fovy -= 1.0f;
        if (IsKeyDown(KEY_X)) cam.fovy += 1.0f;

        // 4. Modificar UP (Inclinar la cámara lateralmente)
        if (IsKeyDown(KEY_A)) cam.up.x -= 0.05f;
        if (IsKeyDown(KEY_D)) cam.up.x += 0.05f;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(cam);
        
        DrawCube({ 0.0f, 0.0f, 0.0f }, 2.0f, 2.0f, 2.0f, RED);
        DrawGrid(10, 1.0f); // Cuadrícula para notar la perspectiva
        
        EndMode3D();

        DrawText("Controles de Camara:", 10, 10, 20, BLACK);
        DrawText("FLECHAS IZQ/DER : Modificar 'position.x'", 10, 40, 20, DARKGRAY);
        DrawText("FLECHAS ARR/ABA : Modificar 'target.y'", 10, 70, 20, DARKGRAY);
        DrawText("TECLAS Z / X    : Modificar 'fovy' (Zoom)", 10, 100, 20, DARKGRAY);
        DrawText("TECLAS A / D    : Modificar 'up.x' (Inclinacion)", 10, 130, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
