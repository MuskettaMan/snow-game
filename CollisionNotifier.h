#pragma once
#include "ColliderType.h"

class ICollisionNotifier
{
public:
	virtual void NotifyCollision(ColliderType colliderType) = 0;
};

