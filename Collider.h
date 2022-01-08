#pragma once
#include <vector>
#include <algorithm>

#include "Rect.h"
#include "ICollisionNotification.h"

class Collider
{
public:
	Collider(const Rect& rect, CollisionType collisionType);
	const Rect& GetRect() const;
	void Collides(const Collider& collider) const;
	void Register(ICollisionNotification& subscriber);
	void Unregister(ICollisionNotification& subscriber);
	CollisionType GetCollisionType() const;

private:
	const Rect& rect;
	std::vector<ICollisionNotification*> subscribers;
	CollisionType collisionType;
};

