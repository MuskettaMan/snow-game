#include "Collider.h"

Collider::Collider(const Rect& rect) : rect(rect)
{
}

bool Collider::Collides(const Collider& collider) const
{
	if (rect.position.x + rect.size.x >= collider.rect.position.x && rect.position.x <= collider.rect.position.x + collider.rect.size.x && rect.position.y + rect.size.y >= collider.rect.position.y && rect.position.y <= collider.rect.position.y + collider.rect.size.y)
		return true;
	return false;
}
