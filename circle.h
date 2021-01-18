#pragma once
#include <SDL2/SDL.h>

typedef struct Circle
{
    int x, y;
    int r;
} Circle;

int CollideCircles(Circle c1, Circle c2);
