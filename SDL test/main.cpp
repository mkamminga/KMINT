#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include "MainVisitor.h"
#include "Game.h"

int main(int argc, char *argv[])
{
	MainVisitor mainView;
	Game game;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;

		if (SDL_CreateWindowAndRenderer(1024, (int)(1024 * 0.75), 0, &window, &renderer) == 0) {
			mainView.setRenderer(renderer);
			SDL_bool done = SDL_FALSE;
			SDL_Event event;
			ShortestRoute shortestRoute;

			game.start();
			while (!done) {
				
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						done = SDL_TRUE;
					} 
					else if (event.type == SDL_MOUSEBUTTONUP)
					{
						auto hare = game.getHare();
						auto cow = game.getCow();

						if (hare->getNode() != shortestRoute.goal) // update goal, hare has moved since last update
						{
							auto graph = game.getGraph();
							shortestRoute = graph->shortestPathTo(cow->getNode(), hare->getNode());
						}
						auto currentNode = cow->getNode();
						auto nextNode = shortestRoute.getNextNode();
						cow->setNode(nextNode);
					}
				}
				
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(renderer);
				auto objects = game.gameObjects();
				
				for (auto object : objects)
				{
					object->accept(&mainView);
				}

				SDL_RenderPresent(renderer);
			}
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}

		if (window) {
			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();


	return 0;
}