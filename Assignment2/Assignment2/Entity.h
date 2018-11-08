#pragma once
#include "Vector.h"

using namespace MATH;

class Entity {
protected:

public:
	virtual Vec2 * getPosition() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};
