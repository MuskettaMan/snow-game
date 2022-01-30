#pragma once
#include "Rect.h"

class Collider
{
public:
	Collider(const Rect& rect);
	bool Collides(const Collider& collider) const;

private:
	const Rect& rect;
};

