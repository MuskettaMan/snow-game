#pragma once
#include "ColliderType.h"
#include "CollisionNotifier.h"
#include "Rect.h"

class Collider
{
public:
	Collider(const Rect& rect, ColliderType colliderType, ICollisionNotifier& notifier);
	bool Collides(const Collider& collider) const;

private:
	const Rect& rect;
	ColliderType colliderType;
	ICollisionNotifier& notifier;
};

