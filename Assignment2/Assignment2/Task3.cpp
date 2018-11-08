#include "Task3.h"



Task3::Task3(SDL_Window * window_, SDL_Renderer* renderer_)
{
	window = window_;
	renderer = renderer_;
}


Task3::~Task3()
{
}

void Task3::OnDestroy() {
	delete observer;
	delete subject;

	delete bun;
	//bun = nullptr;
}

bool Task3::OnCreate() {
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

void Task3::Update() {
	//if (bun != nullptr)
	bun->Update();
	unit->Update(); 
}

void Task3::HandleEvents(SDL_Event event) {

}

void Task3::Render() {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	//if (bun != nullptr)
	bun->Render();
	unit->Render();

	SDL_RenderPresent(renderer);
}
