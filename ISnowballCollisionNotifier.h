#pragma once

class Snowball;

class ISnowballCollisionNotifier
{
public:
	virtual void NotifySnowballCollision(Snowball& snowball, ColliderType colliderType) = 0;
};

