#include "input.h"
#include "raymath.h"

void InitInput(Input *input)
{
    input->moveSpeed = 3.0f;
    input->mouseSensitivity = 0.003f;
}

void UpdateCameraInput(Camera3D *camera, Input *input)
{
    float dt = GetFrameTime();

    float speedMultiplier = 1.0f;

    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))
    {
        speedMultiplier = 2.5f;
    }

    float speed = input->moveSpeed * speedMultiplier * dt;

    Vector3 forward = Vector3Normalize(
        Vector3Subtract(camera->target, camera->position)
    );

    Vector3 up = (Vector3){0, 1, 0};
    Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, up));

    if (IsKeyDown(KEY_W))
    {
        camera->position = Vector3Add(camera->position, Vector3Scale(forward, speed));
        camera->target   = Vector3Add(camera->target, forward);
    }

    if (IsKeyDown(KEY_S)) {
        camera->position = Vector3Subtract(camera->position, Vector3Scale(forward, speed));
        camera->target   = Vector3Subtract(camera->target, forward);
    }

    if (IsKeyDown(KEY_D)) {
        camera->position = Vector3Add(camera->position, Vector3Scale(right, speed));
        camera->target   = Vector3Add(camera->target, right);
    }

    if (IsKeyDown(KEY_A)) {
        camera->position = Vector3Subtract(camera->position, Vector3Scale(right, speed));
        camera->target   = Vector3Subtract(camera->target, right);
    }

    Vector2 mouse = GetMouseDelta();

    float yaw = -mouse.x * input->mouseSensitivity;
    float pitch = -mouse.y * input->mouseSensitivity;

    Vector3 direction = Vector3Subtract(camera->target, camera->position);
    direction = Vector3RotateByAxisAngle(direction, up, yaw);
    direction = Vector3RotateByAxisAngle(direction, right, pitch);

    camera->target = Vector3Add(camera->position, direction);
}