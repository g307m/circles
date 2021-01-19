#include "shapes.h"

#include <SDL2/SDL.h>
#include <stdlib.h>

#include "maths.h"

int
CollideCircles(Circle c1, Circle c2)
{
	return fabsf(ThirdLeg(c1.x-c2.x,c1.y-c2.y)) < c1.r + c2.r;
}

Vec2
ccr(Circle c, Rectangle r)
{
	Vec2 closest = {
		Clamp(r.x,c.x,r.x+r.w),
		Clamp(r.y, c.y, r.y+r.h)
	};
	return closest;
}
int
CollideCircleRectangle(Circle c, Rectangle r)
{
	Vec2 closest = ccr(c,r);
	return Distance(c.x,c.y,closest.x,closest.y) < c.r;
}
