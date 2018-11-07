#pragma once
#include "HFiles.h"
#include "Entity.h"
#include "Subject.h"

class Observer
{
	friend class Subject;

private:
	Observer * next = nullptr;

public:
	virtual void onNotify(const Entity * entity, SDL_Event event) = 0;
};