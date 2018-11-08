#include "Bunny.h"



Bunny::Bunny(SDL_Renderer * renderer_)
{
	renderer = renderer_;

	//load image and convert it to texture
	image = IMG_Load("bunny.png");
	texture = SDL_CreateTextureFromSurface(renderer, image);

	//check if the image loaded properly (used in render function)
	if (image == nullptr || texture == nullptr) hasImg = false;
	else hasImg = true;

	//set character default stats
	position = new Vec2(10.0f, 10.0f);

	//create rectangle to display as character
	rect = new SDL_Rect;
	rect->w = 100;
	rect->h = 100;
	rect->x = position->x - 50;
	rect->y = position->y - 50;
}


Bunny::~Bunny()
{
	delete rect;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
}

void Bunny::Update() {

	position->x++;
	position->y++;

	//update character's rectangle so that it always equals position
	//the -50 essentially puts the rect's origin in the centre of itself
	rect->x = position->x - 50;
	rect->y = position->y - 50;
}

void Bunny::Render() {
	//if there is an image, render it
	if (hasImg) SDL_RenderCopy(renderer, texture, NULL, rect);

	//if not, render a coloured rect
	else {
		SDL_SetRenderDrawColor(renderer, 78, 42, 163, 255);
		SDL_RenderFillRect(renderer, rect);
	}
}
