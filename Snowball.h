#pragma once
#include "Collider.h"
#include "ISnowballCollisionNotifier.h"
#include "surface.h"
#include "template.h"

using namespace Tmpl8;

class Snowball : public ICollisionNotifier
{
public:
	Snowball(vec2 origin, vec2 direction, ISnowballCollisionNotifier& snowballCollisionNotifier);
	~Snowball();
	void Update();
	void Draw(Surface* screen) const;
	float GetStartTime();
	Collider& GetCollider() const;
	void NotifyCollision(ColliderType colliderType) override;

private:
	vec2 position;
	vec2 velocity;
	Sprite* sprite;
	Rect* rect;
	Collider* collider;
	float startTime;
	ISnowballCollisionNotifier& snowballCollisionNotifier;
};

