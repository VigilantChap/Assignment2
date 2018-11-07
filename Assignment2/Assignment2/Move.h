#pragma once
#include "Character.h"
#include "Command.h"
#include "Vector.h"
#include "HFiles.h"

using namespace MATH;

class Move :
	public Command
{
private:
	Vec2 * newPosition = nullptr;
	Vec2 * prevPosition = nullptr;
	Character * unit = nullptr;
public:
	inline Move(Character* _unit, Vec2 * pos) {
		unit = _unit;
		prevPosition = _unit->getPosition();
		newPosition = pos;
		Action();
	};
	inline void Action() { unit->moveTo(newPosition); }
	inline void Undo() { unit->moveTo(prevPosition); }
	inline ~Move() {}
};

