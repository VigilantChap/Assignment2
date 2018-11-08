#pragma once

#include "HFiles.h"
#include "Character.h"
#include "Scene.h"
#include "ActionManager.h"
#include <SDL_ttf.h>
#include <sstream>
#include <iomanip>
#include "Bunny.h"

class Task1 : public Scene
{
public:
	Task1(SDL_Window * window_, SDL_Renderer* renderer_);
	~Task1();

	bool OnCreate();
	void OnDestroy();
	void Update();
	void HandleEvents(SDL_Event event);
	void Render();

private:
	SDL_Window * window = nullptr;
	SDL_Renderer * renderer = nullptr;
	int w, h;

	SDL_Texture* Message = nullptr;
	SDL_Rect* Message_rect = nullptr;
	TTF_Font* Sans = nullptr;
	SDL_Surface* surfaceMessage = nullptr;

	SDL_Texture* Wallet = nullptr;
	SDL_Rect* Wallet_rect = nullptr;
	SDL_Surface* surfaceWallet = nullptr;

	string health;
	string wallet;
	SDL_Color Black;


	Character * unit = nullptr;
	//Bunny * bun = nullptr;
	ActionManager * aManager = nullptr;
};

