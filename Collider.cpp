#include "Collider.h"

Collider::Collider(const Rect& rect, CollisionType collisionType) : rect(rect), collisionType(collisionType)
{
}

const Rect& Collider::GetRect() const
{
	return rect;
}

void Collider::Collides(const Collider& collider) const
{
	for (int i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->OnCollision(collider.GetCollisionType());
	}
}

void Collider::Register(ICollisionNotification& subscriber)
{
	subscribers.push_back(&subscriber);
}

void Collider::Unregister(ICollisionNotification& subscriber)
{
	std::vector<ICollisionNotification*>::iterator it = std::find(subscribers.begin(), subscribers.end(), &subscriber);
	if (it != subscribers.end())
	{
		subscribers.erase(it);
	}
}

CollisionType Collider::GetCollisionType() const
{
	return collisionType;
}
