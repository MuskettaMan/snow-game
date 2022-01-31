#pragma once
#include "ColliderType.h"

class Present;

class IPresentCollisionNotifier
{
public:
	virtual void NotifyPresentCollision(Present& present, ColliderType colliderType) = 0;
};

