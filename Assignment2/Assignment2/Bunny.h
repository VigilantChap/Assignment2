#pragma once
#include "HFiles.h"
#include "Entity.h"

class Bunny : public Entity
{
private:
	//objects used to render
	SDL_Rect * rect = nullptr;
	SDL_Texture * texture = nullptr;
	SDL_Surface * image = nullptr;
	SDL_Renderer * renderer = nullptr;

	bool hasImg;

public:
	Bunny(SDL_Renderer * renderer_);
	~Bunny();

	void Update();
	void Render();
};
