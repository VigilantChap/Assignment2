#pragma once
#include "HFiles.h"
#include "Character.h"
#include "Command.h"


class Purchase : public Command
{
private:
	float amount;
	Character * character;

public:
	inline Purchase(Character * c, float amount_) { amount = amount_; character = c; Action(); }
	inline void Action() { character->removeBalance(amount); }
	inline void Undo() { character->addBalance(amount); }
};

