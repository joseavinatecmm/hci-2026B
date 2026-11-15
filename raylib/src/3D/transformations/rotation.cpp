#include "raylib.h"
#include "rlgl.h" 
#include <math.h>

int main(void)
{
    InitWindow(800, 600, "Rotacion Oscilante 3D (Ejes X, Y, Z)");
    SetTargetFPS(60);

    Camera3D cam = { 0 };
    cam.position = { 0.0f, 4.0f, 10.0f };
    cam.target = { 0.0f, 0.0f, 0.0f };
    cam.up = { 0.0f, 1.0f, 0.0f };
    cam.fovy = 45.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        // calcula el ángulo oscilando suavemente entre -45 y +45 grados
        float angulo = sinf(GetTime() * 2.0f) * 45.0f;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);

        // rotación en el eje X
        rlPushMatrix();                      // Aísla la matriz espacial para este cubo
        rlTranslatef(-3.0f, 0.0f, 0.0f);     // Ubica el cubo a la izquierda
        rlRotatef(angulo, 1.0f, 0.0f, 0.0f); // Rota usando el ángulo calculado sobre el eje X (1,0,0)
        DrawCube({ 0, 0, 0 }, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires({ 0, 0, 0 }, 2.0f, 2.0f, 2.0f, MAROON);
        rlPopMatrix();                       // Restaura la matriz para no afectar al siguiente cubo

        // rotación en el eje Y
        rlPushMatrix();
        rlTranslatef(0.0f, 0.0f, 0.0f);      // Centro
        rlRotatef(angulo, 0.0f, 1.0f, 0.0f); // Rota usando el ángulo calculado sobre el eje Y (0,1,0)
        DrawCube({ 0, 0, 0 }, 2.0f, 2.0f, 2.0f, GREEN);
        DrawCubeWires({ 0, 0, 0 }, 2.0f, 2.0f, 2.0f, DARKGREEN);
        rlPopMatrix();

        // rotación en el eje Z
        rlPushMatrix();
        rlTranslatef(3.0f, 0.0f, 0.0f);      // Derecha
        rlRotatef(angulo, 0.0f, 0.0f, 1.0f); // Rota usando el ángulo calculado sobre el eje Z (0,0,1)
        DrawCube({ 0, 0, 0 }, 2.0f, 2.0f, 2.0f, BLUE);
        DrawCubeWires({ 0, 0, 0 }, 2.0f, 2.0f, 2.0f, DARKBLUE);
        rlPopMatrix();

        EndMode3D();
        
        DrawText("Eje X (Rojo)", 100, 500, 20, DARKGRAY);
        DrawText("Eje Y (Verde)", 340, 500, 20, DARKGRAY);
        DrawText("Eje Z (Azul)", 580, 500, 20, DARKGRAY);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
