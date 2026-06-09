#include <stdio.h>
#include <raylib.h>
#include <math.h>
#include "input.h"

#define WIDTH 900
#define HEIGHT 600
#define TARGET_FPS 60

typedef struct Cube
{
    Vector3 position;
    Vector3 size;
    Color color;
} Cube;
