#include "raylib.h"
#include <math.h>

int main(void)
{
    InitWindow(800, 600, "4 Movimientos Cinematicos 3D");
    
    // Fija la tasa de refresco en 60 fotogramas por segundo (FPS)
    SetTargetFPS(60);

    Camera3D cam = { 0 };
    cam.position = { 0.0f, 8.0f, 14.0f };
    cam.target = { 0.0f, 0.0f, 0.0f };
    cam.up = { 0.0f, 1.0f, 0.0f };
    cam.fovy = 45.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    int escena = 1;
    
    // Variables de tiempo y trayectoria para control de animación
    float t = 0.0f;
    float xInicio = -5.0f;
    float xFin = 5.0f;

    while (!WindowShouldClose())
    {
        // Cambio de escena y reinicio del cronómetro de animación
        if (IsKeyPressed(KEY_ONE))   { escena = 1; t = 0.0f; }
        if (IsKeyPressed(KEY_TWO))   { escena = 2; t = 0.0f; }
        if (IsKeyPressed(KEY_THREE)) { escena = 3; t = 0.0f; }
        if (IsKeyPressed(KEY_FOUR))  { escena = 4; t = 0.0f; }

        // Acumula el tiempo transcurrido entre fotogramas (delta time)
        t += GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(cam);

        DrawGrid(14, 1.0f);

        if (escena == 1)
        {
            // MOVIMIENTO LINEAL (LERP): Velocidad constante, aceleración nula
            float u = fmodf(t * 0.4f, 1.0f); // Progreso normalizado de 0.0 a 1.0
            float posX = xInicio + (xFin - xInicio) * u;

            DrawCube({ posX, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, SKYBLUE);
            DrawCubeWires({ posX, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, DARKBLUE);
        }
        else if (escena == 2)
        {
            // MOVIMIENTO CON ACELERACIÓN (Easing): Curva cúbica suave (Smoothstep)
            float u = fmodf(t * 0.4f, 1.0f);
            float ease = u * u * (3.0f - 2.0f * u); // Acelera al salir y frena al llegar
            float posX = xInicio + (xFin - xInicio) * ease;

            DrawCube({ posX, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, LIME);
            DrawCubeWires({ posX, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, DARKGREEN);
        }
        else if (escena == 3)
        {
            // MOVIMIENTO OSCILATORIO (M.A.S.): Vaivén continuo mediante función seno
            float posX = sinf(t * 2.5f) * 5.0f; // Frecuencia de 2.5 y amplitud de 5.0

            DrawCube({ posX, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, PURPLE);
            DrawCubeWires({ posX, 1.0f, 0.0f }, 2.0f, 2.0f, 2.0f, DARKPURPLE);
        }
        else if (escena == 4)
        {
            // MOVIMIENTO ORBITAL: Coordenadas circulares en el plano XZ usando coseno y seno
            float radio = 4.5f;
            float angulo = t * 2.0f; // Velocidad angular
            float posX = cosf(angulo) * radio;
            float posZ = sinf(angulo) * radio;

            // Pivote central en malla de alambre
            DrawSphereWires({ 0.0f, 1.0f, 0.0f }, 1.0f, 8, 8, GRAY);

            // Objeto en órbita
            DrawCube({ posX, 1.0f, posZ }, 1.5f, 1.5f, 1.5f, ORANGE);
            DrawCubeWires({ posX, 1.0f, posZ }, 1.5f, 1.5f, 1.5f, MAROON);
        }

        EndMode3D();

        DrawText("Presiona teclas [1], [2], [3] o [4] para cambiar de escena", 10, 10, 20, DARKGRAY);
        
        if (escena == 1) DrawText("Escena 1: Movimiento Lineal (LERP)", 10, 40, 20, DARKBLUE);
        if (escena == 2) DrawText("Escena 2: Aceleracion y Desaceleracion (Easing)", 10, 40, 20, DARKGREEN);
        if (escena == 3) DrawText("Escena 3: Movimiento Oscilatorio (Seno)", 10, 40, 20, DARKPURPLE);
        if (escena == 4) DrawText("Escena 4: Movimiento Orbital (Coseno / Seno)", 10, 40, 20, MAROON);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
