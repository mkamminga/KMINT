#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "BaseVisitor.h"
class BaseObject;

class MainVisitor : public BaseVisitor
{
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture *cowTexture = nullptr;
	SDL_Texture *hareTexture = nullptr;
	SDL_Rect cowPosition;
	SDL_Rect harePosition;

public:
	void setRenderer(SDL_Renderer* renderer);
	virtual void visit(CowObject* cow);
	virtual void visit(GraphNode* graphNode);
	virtual void visit(HareObject* hare);
	void drawObjectTexture(BaseObject* object, SDL_Texture * texture, SDL_Rect* position);

	~MainVisitor()
	{
		if (cowTexture)
		{
			SDL_DestroyTexture(cowTexture);
		}
	}
};

