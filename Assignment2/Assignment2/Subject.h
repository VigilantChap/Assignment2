#pragma once
#include "Observer.h"
#include "Entity.h"

class Subject
{
private:
	Observer * head = nullptr;

public:
	Subject();
	~Subject();

	void addObserver(Observer * observer);
	void removeObserver(Observer * observer);
	void notify(const Entity * entity, SDL_Event event);

};

