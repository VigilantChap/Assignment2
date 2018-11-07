#pragma once
#include "Vector.h"
#include "Entity.h"
#include "HFiles.h"


using namespace MATH;

class Character: public Entity
{
private:
	//Member variables that can be changed
	int health;
	float wallet;
	bool hasImg;

	//objects used to render
	SDL_Rect * rect = nullptr;
	SDL_Texture * texture = nullptr;
	SDL_Surface * image = nullptr;
	SDL_Renderer * renderer = nullptr;

public:
	//Lets us render our character
	Character(SDL_Renderer * renderer_);
	~Character();
	
	void Update();
	void Render();

	void addBalance(float amount);
	void removeBalance(float amount);

	void addHealth(int amount);
	void removeHealth(int amount);

	void moveTo(Vec2 * pos);

	inline int getHealth() { return health; }
	inline float walletBalance() { return wallet; }
};

