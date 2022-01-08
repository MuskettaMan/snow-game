#pragma once
#include "Rect.h"

class Collider
{
public:
	Collider(const Rect& rect);
	const Rect& GetRect() const;
	//__event void Collides(const Collider& collider) const;

private:
	const Rect& rect;
};

