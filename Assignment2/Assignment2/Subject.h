#pragma once
#include "HFiles.h"
#include "Entity.h"
#include "Observer.h"

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

