#include "Collider.h"

Collider::Collider(const Rect& rect, ColliderType colliderType, ICollisionNotifier& notifier) : rect(rect), colliderType(colliderType), notifier(notifier)
{
}

bool Collider::Collides(const Collider& collider) const
{
	if (rect.position.x + rect.size.x >= collider.rect.position.x && rect.position.x <= collider.rect.position.x + collider.rect.size.x && rect.position.y + rect.size.y >= collider.rect.position.y && rect.position.y <= collider.rect.position.y + collider.rect.size.y)
	{
		notifier.NotifyCollision(collider.colliderType);
		return true;
	}
	return false;
}
