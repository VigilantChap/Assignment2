#include "SceneHandler.h"
#include "Task1.h"



SceneHandler::SceneHandler(Window * window_)
{
	window = window_;
	renderer = window->GetRenderer();
	task = nullptr;
}


SceneHandler::~SceneHandler()
{
}

void SceneHandler::OnDestroy() {
	delete window;
	SDL_DestroyRenderer(renderer);
	delete task;
}

bool SceneHandler::OnCreate() {
	task = new Task1(window->GetWindow(), window->GetRenderer());

	if (task == nullptr) {
		OnDestroy();
		return false;
	}

	if (task->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

void SceneHandler::Update() {
	task->Update();
	task->Render();
}

void SceneHandler::HandleEvents(SDL_Event event) {

	task->HandleEvents(event);

}



