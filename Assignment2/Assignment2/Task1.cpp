#include "Task1.h"



Task1::Task1(SDL_Window * window_, SDL_Renderer* renderer_)
{
	window = window_;
	renderer = renderer_;
}


Task1::~Task1()
{
}

void Task1::OnDestroy() {

	delete unit;
	//unit = nullptr;
	delete aManager;
	//aManager = nullptr;

	TTF_CloseFont(Sans);
	SDL_DestroyTexture(Message);
	SDL_FreeSurface(surfaceMessage); 
	SDL_DestroyTexture(Wallet);
	SDL_FreeSurface(surfaceWallet); 

	delete Message_rect;
	//Message_rect = nullptr;


	delete Wallet_rect;
	//Wallet_rect = nullptr;



}

bool Task1::OnCreate() {
	cout << "Task 1" << endl;

	SDL_GetWindowSize(window, &w, &h);

	aManager = new ActionManager();

	if (aManager == nullptr) {
		OnDestroy();
		return false;
	}

	unit = new Character(renderer);

	if (unit == nullptr) {
		OnDestroy();
		return false;
	}

	/*bun = new Bunny(renderer);

	if (bun == nullptr) {
		OnDestroy();
		return false;
	}*/

	unit->moveTo(new Vec2(w/2, h/2));

	Sans = TTF_OpenFont("Sans.ttf", 500); //this opens a font style and sets a size

	Black = { 0, 0, 0 };

	ostringstream str;
	str << unit->getHealth(); // converting to string

	health = "Health: " + str.str();

	surfaceMessage = TTF_RenderText_Solid(Sans, health.c_str(), Black);
	Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	//create a rect to display wallet
	Wallet_rect = new SDL_Rect;
	Wallet_rect->x = 0;
	Wallet_rect->y = 50;
	Wallet_rect->w = 100;
	Wallet_rect->h = 50;

	ostringstream str1;
	str1 << unit->walletBalance(); // converting to string

	wallet = "$" + str1.str();

	surfaceWallet = TTF_RenderText_Solid(Sans, wallet.c_str(), Black);
	Wallet = SDL_CreateTextureFromSurface(renderer, surfaceWallet);

	//create a rect for message
	Message_rect = new SDL_Rect;
	Message_rect->x = 0;
	Message_rect->y = 0;
	Message_rect->w = 160;
	Message_rect->h = 50;

	if (Sans == nullptr ||
		Message_rect == nullptr ||
		surfaceMessage == nullptr) 
		return false;

	return true;

}

void Task1::Update() {
	unit->Update();
	//bun->Update();

	ostringstream str;
	str << unit->getHealth(); // converting to string

	health = "Health: " + str.str();

	surfaceMessage = TTF_RenderText_Solid(Sans, health.c_str(), Black);
	Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	ostringstream str1;
	str1 << unit->walletBalance(); // converting to string

	wallet = "$" + str1.str();

	surfaceWallet = TTF_RenderText_Solid(Sans, wallet.c_str(), Black);
	Wallet = SDL_CreateTextureFromSurface(renderer, surfaceWallet);
}

void Task1::HandleEvents(SDL_Event event) {
	aManager->HandleInput(event, unit);
}

void Task1::Render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	unit->Render();
	//bun->Render();

	//draw messages
	SDL_RenderCopy(renderer, Message, NULL, Message_rect);
	SDL_RenderCopy(renderer, Wallet, NULL, Wallet_rect);

	SDL_RenderPresent(renderer);

	//destroy the texture and surface for message1 since it's being recreated every loop
	SDL_DestroyTexture(Message);
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Wallet);
	SDL_FreeSurface(surfaceWallet);
}
