#include "Task2.h"



Task2::Task2(SDL_Window * window_, SDL_Renderer* renderer_)
{
	window = window_;
	renderer = renderer_;
}


Task2::~Task2()
{
}

void Task2::OnDestroy() {
	delete observer;
	delete subject;

	delete bun;
	//bun = nullptr;
}

bool Task2::OnCreate() {
	SDL_GetWindowSize(window, &w, &h);

	cout << "Task 2" << endl;

	unit = new Character(renderer);

	bun = new Bunny(renderer);

	//if (bun = nullptr) {
	//	OnDestroy();
	//	return false;
	//}

	return true;
}

void Task2::Update() {
	//if (bun != nullptr)
	bun->Update();
	unit->Update();
}

void Task2::HandleEvents(SDL_Event event) {

}

void Task2::Render() {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	//if (bun != nullptr)
	bun->Render();
	unit->Render();

	SDL_RenderPresent(renderer);
}
