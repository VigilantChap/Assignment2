#pragma once
#include "Character.h"
#include "HFiles.h"
#include "Command.h"

class AddHealth : public Command
{
private:
	int amount;
	Character * character = nullptr;

public:
	inline AddHealth(Character * c, int amount_) { amount = amount_; character = c; Action(); }
	inline void Action() { character->addHealth(amount); }
	inline void Undo() { character->removeHealth(amount); }
};

