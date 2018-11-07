#include "UndoManager.h"

UndoManager::UndoManager() {
}


UndoManager::~UndoManager() {
}

void UndoManager::AddCommand(Command * _action) {
	actionList.push(_action);
}

void UndoManager::UndoCommand() {
	actionList.top()->Undo();
	actionList.pop();
}

bool UndoManager::hasActions() {
	if (actionList.size() > 0)
		return true;
	else return false;
}


