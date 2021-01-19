#pragma once
#include "maths.h"
#include <SDL2/SDL.h>

typedef struct Circle
{
    int x, y, r;
    float friction;
} Circle;

int CollideCircles(Circle c1, Circle c2);

typedef struct Rectangle
{
    int x, y, w, h;
    float friction;
} Rectangle;

Vec2 ccr(Circle c, Rectangle r);
int CollideCircleRectangle(Circle c, Rectangle r);
