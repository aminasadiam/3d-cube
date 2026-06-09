#ifndef INPUT_H
#define INPUT_H

#include <raylib.h>

typedef struct input
{
    float moveSpeed;
    float mouseSensitivity;
} Input;

void InitInput(Input *input);
void UpdateCameraInput(Camera3D *camera, Input *input);

#endif
