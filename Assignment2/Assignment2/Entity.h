#pragma once
#include "Vector.h"

using namespace MATH;

class Entity {
protected:
	Vec2 * position = nullptr;

public:
	inline Vec2 * getPosition() { return position; }
};
