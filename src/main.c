#include "main.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "3d Cube World");
    SetTargetFPS(TARGET_FPS);
    DisableCursor();
    
    Camera3D cam = {
        .position = (Vector3){10, 5, 10},
        .target   = (Vector3){0, 0, 0},
        .up       = (Vector3){0, 1, 0},
        .fovy = 60.0f,
        .projection = CAMERA_PERSPECTIVE
    };

    Input input;
    InitInput(&input);

    Cube cube = {
        .position = (Vector3){0, 0.5f, 0},
        .size = (Vector3){1, 1, 1},
        .color = BLUE
    };

    while (!WindowShouldClose())
    {
        // update
        UpdateCameraInput(&cam, &input);
        
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        BeginMode3D(cam);

        DrawCubeV(cube.position, cube.size, cube.color);
        DrawLine3D(cam.position, cube.position, RED);
        DrawGrid(10, 1.0f);

        EndMode3D();

        DrawText("3D Cube World", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}
