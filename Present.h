#pragma once
#include <functional>

#include "Collider.h"
#include "IDrawable.h"
#include "IPresentCollisionNotifier.h"
#include "PresentFactory.h"
#include "surface.h"

using namespace Tmpl8;

class Present : public IDrawable, public ICollisionNotifier
{
public:
	Present(int pointsToReward, int spriteFrame, vec2 position, IPresentCollisionNotifier& collisionNotifier);
	virtual ~Present();
	int GetPointsToReward() const;
	void NotifyCollision (ColliderType colliderType) override;
	void Draw(Surface* screen) override;
	Rect* GetRect();
	Collider* GetCollider();

private:
	int pointsToReward;
	Sprite* sprite;
	Rect* rect;
	Collider* collider;
	IPresentCollisionNotifier& collisionNotifier;
};

