#include "MainVisitor.h"
#include "BaseObject.h"
#include "CowObject.h"
#include "HareObject.h"
#include "GraphNode.h"
#include "NodeEdge.h"
#include "SparseGraph.h"


void drawcircle(SDL_Renderer* renderer, int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int err = 0;

	while (x >= y)
	{
		SDL_RenderDrawPoint(renderer, x0 + x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 + x);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 + y);
		SDL_RenderDrawPoint(renderer, x0 - x, y0 - y);
		SDL_RenderDrawPoint(renderer, x0 - y, y0 - x);
		SDL_RenderDrawPoint(renderer, x0 + y, y0 - x);
		SDL_RenderDrawPoint(renderer, x0 + x, y0 - y);

		if (err <= 0)
		{
			y += 1;
			err += 2 * y + 1;
		}
		if (err > 0)
		{
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}

void MainVisitor::setRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

void MainVisitor::visit(CowObject * cow)
{
	if (!cowTexture)
	{
		cowTexture = IMG_LoadTexture(renderer, "images/cow-1.png");
		cowPosition.w = 110;
		cowPosition.h = 110;
	}

	drawObjectTexture(cow, cowTexture, &cowPosition);

}

void MainVisitor::visit(GraphNode * node)
{
	SDL_SetRenderDrawColor(renderer, 100, 150, 255, SDL_ALPHA_OPAQUE);
	drawcircle(renderer, node->getX(), node->getY(), 20);
	auto edges = node->getEdges();
	//draw all edges
	for (auto edge : edges)
	{
		auto from	= edge->getFrom();
		auto to		= edge->getTo();
		SDL_RenderDrawLine(renderer, from->getX(), from->getY(), to->getX(), to->getY());
	}
	
}

void MainVisitor::visit(HareObject * hare)
{
	if (!hareTexture)
	{
		hareTexture = IMG_LoadTexture(renderer, "images/rabbit-2.png");
		harePosition.w = 60;
		harePosition.h = 60;
	}

	drawObjectTexture(hare, hareTexture, &harePosition);
}

void MainVisitor::drawObjectTexture(BaseObject * object, SDL_Texture * texture, SDL_Rect * position)
{
	position->x = object->getX();
	position->y = object->getY();

	SDL_RenderCopy(renderer, texture, NULL, position);
}
