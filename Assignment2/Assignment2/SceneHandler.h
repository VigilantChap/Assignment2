#pragma once
#include "Window.h"
#include "Scene.h"
#include "HFiles.h"

class SceneHandler
{
public:
	SceneHandler(Window * window_);
	~SceneHandler();

	bool OnCreate();
	void OnDestroy();
	void Update();
	void HandleEvents(SDL_Event event);

private:
	Window * window = nullptr;
	SDL_Renderer * renderer = nullptr;
	Scene * task = nullptr;
};


