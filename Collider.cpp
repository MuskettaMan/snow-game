#include "Collider.h"

Collider::Collider(const Rect& rect) : rect(rect)
{
}

const Rect& Collider::GetRect() const
{
	return rect;
}
