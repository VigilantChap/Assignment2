#pragma once
#include "Character.h"
#include "HFiles.h"
#include "CommandFiles.h"
#include "UndoManager.h"


class ActionManager
{
protected:
	//unique_ptr<UndoManager> Undoer;
	UndoManager * Undoer = 0;
public:
	//Takes in button inputs and tells them to do their action then passes the action to the UndoManager
	void HandleInput(SDL_Event _event, Character* _unit);
	ActionManager();
	~ActionManager();
};

