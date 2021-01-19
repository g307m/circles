#pragma once

#include <math.h>

typedef struct Vec2 {
	float x,y;
} Vec2;

float ThirdLeg(float leg1, float leg2);
float Distance(float x1, float y1, float x2, float y2);

float Min(float x, float y);
float Max(float x, float y);
float Clamp(float min, float val, float max);
