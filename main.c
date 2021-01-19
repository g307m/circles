#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include <stdio.h>

#include "maths.h"
#include "shapes.h"

int
main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Event event;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL failed to initialize video: %s\n", SDL_GetError());
		goto cleanup;
	}

	/* create window */
	window = SDL_CreateWindow("Circles",
	 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
	 640, 480, SDL_WINDOW_SHOWN);
	if(window == NULL) {
		fprintf(stderr, "Failed to create window, error: %s\n",SDL_GetError());
		goto cleanup;
	}

	/* circles */
	Circle cursorCircle = {
		0,0,50
	};
	Circle otherCircle = {
		100,100,100
	};
	Rectangle gr = {
		0, 450, 640, 30
	};

	/* use window stuff */
	surface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL_Rect roct = {0,0, 100, 100};
	while (1) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_MOUSEMOTION:
				cursorCircle.x = event.motion.x;
				cursorCircle.y = event.motion.y;
				break;
			case SDL_MOUSEBUTTONDOWN:
				otherCircle.x = event.motion.x;
				otherCircle.y = event.motion.y;
				break;
			case SDL_QUIT:
				goto cleanup;
				break;
			default:
				break;
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		/* change other circle if colliding with cursor circle */
		if (CollideCircles(cursorCircle, otherCircle)) {
			circleRGBA(renderer, otherCircle.x, otherCircle.y, otherCircle.r, 0,0,255,255);
		} else {
			circleRGBA(renderer, otherCircle.x, otherCircle.y, otherCircle.r, 0,255,0,255);
		}
		circleRGBA(renderer, cursorCircle.x, cursorCircle.y, cursorCircle.r, 255,0,0,255);

		/* heretic rectangle for ground */
		if (CollideCircleRectangle(cursorCircle, gr)) {
			rectangleRGBA(renderer, gr.x, gr.y, gr.x+gr.w, gr.y+gr.h, 255, 0, 255, 255);
		} else {
			rectangleRGBA(renderer, gr.x, gr.y, gr.x+gr.w, gr.y+gr.h, 255, 127, 0, 255);
		}
		Vec2 cst = ccr(cursorCircle, gr);
		filledCircleRGBA(renderer, cst.x, cst.y, 10, 255, 0, 0, 255);

		SDL_RenderPresent(renderer);
	}
	
	/* cleanup */
	cleanup:
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
