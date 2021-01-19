#include "maths.h"

float
ThirdLeg(float leg1, float leg2)
{
	return sqrt(pow(leg1, 2)+pow(leg2, 2));
}
float
Distance(float x1, float y1, float x2, float y2)
{
	return fabsf(ThirdLeg(x1-x2, y1-y2));
}

float Min(float x, float y) { return x < y ? x : y; }
float Max(float x, float y) { return x < y ? x : y; }

float
Clamp(float min, float val, float max)
{
	return val<min?min:(val>max?max:val);
}
