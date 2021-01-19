#include "shapes.h"

#include <SDL2/SDL.h>
#include <stdlib.h>

#include "maths.h"

int
CollideCircles(Circle c1, Circle c2)
{
	return fabsf(ThirdLeg(c1.x-c2.x,c1.y-c2.y)) < c1.r + c2.r;
}
