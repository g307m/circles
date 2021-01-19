#include "pushing.h"
#include "shapes.h"
#include <SDL2/SDL_stdinc.h>

Vec2
pushall(float force, Circle* circle, int index, Circle** circles[0xFF], Uint8 size, Rectangle rectangle)
{
	Vec2 forces;
	Circle* current;

	for (int i = 0; i<size; i++) {
		current = *circles[i];
		if (i == index)
			continue;
		
		if (CollideCircles(*circle, **circles[i])) {
			forces.x+=circle->x-current->x;
			forces.y+=circle->y-current->y;
		}
	}
	return forces;
}
