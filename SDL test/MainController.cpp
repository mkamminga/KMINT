#include "MainController.h"

void MainController::start()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		if (SDL_CreateWindowAndRenderer(1024, (int)(1024 * 0.75), 0, &window, &renderer) == 0) {
			mainView.setRenderer(renderer);

			game.start();
			auto graph = game.getGraph();
			auto nodes = graph->getNodes();
			ShortestRoute shortestRoute;

			default_random_engine dre{ dev() };
			uniform_int_distribution<int> dist{ 0,  (int)(nodes.size() - 1) };
			

			while (!done) {
				int updateCode = feel();
				if (updateCode == 2)
				{
					update(dist, dre, shortestRoute);
				}
				draw();
			}
		}
	}

	shutdown();
}

void MainController::draw()
{
	mainView.draw(game.gameObjects());
}


int MainController::feel()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			done = true;

			return 1;
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
			return 2;
		}
	}

	return 0;
}

void MainController::update(uniform_int_distribution<int>& dist, default_random_engine& dre, ShortestRoute& shortestRoute)
{
	auto graph = game.getGraph();
	auto nodes = graph->getNodes();

	auto hare = game.getHare();
	auto cow = game.getCow();

	if (hare->getNode() != shortestRoute.goal) // update goal, hare has moved since last update
	{
		shortestRoute = graph->shortestPathTo(cow->getNode(), hare->getNode());
	}

	auto nextNode = shortestRoute.getNextNode();
	if (nextNode)
	{
		nextNode->addObject(cow);
	}

	auto currentCowNode = cow->getNode();

	if (currentCowNode == hare->getNode()) // if hare and cow are on the same node, move the hare to a randowm node
	{
		auto nextHareNode = currentCowNode;

		while (nextHareNode == currentCowNode) // chose a random new node
		{
			int nextHareNodeIndex = dist(dre);
			nextHareNode = nodes.at(nextHareNodeIndex);
		}
		nextHareNode->addObject(hare);
	}
}

void MainController::shutdown()
{
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}

	if (window) {
		SDL_DestroyWindow(window);
	}
}

MainController::~MainController()
{
	shutdown();
}
