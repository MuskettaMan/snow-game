#pragma once
#include "CollisionType.h"

class ICollisionNotification
{
public:
	virtual void OnCollision(CollisionType collisionType) = 0;
};