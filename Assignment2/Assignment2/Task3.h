#pragma once
#include "HFiles.h"
#include "Scene.h"
#include "Character.h"
#include "Bunny.h"
#include "Observer.h"
#include "Subject.h"


class Task3 : public Scene
{
public:
	Task3(SDL_Window * window_, SDL_Renderer* renderer_);
	~Task3();

	bool OnCreate();
	void OnDestroy();
	void Update();
	void HandleEvents(SDL_Event event);
	void Render();

private:
	int w, h;

	SDL_Renderer * renderer = nullptr;
	SDL_Window * window = nullptr;

	Observer * observer = nullptr;
	Subject * subject = nullptr;

	Bunny * bun = nullptr;
	Character * unit = nullptr;
};

