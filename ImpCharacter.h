#pragma once
#include <functional>

#include "Character.h"
#include "IEnemyCollisionNotifier.h"

class ImpCharacter : public Character
{
public:
	ImpCharacter(vec2 position, float speed, const IEnemyCollisionNotifier& collisionNotifier);
	~ImpCharacter();
	void NotifyCollision(ColliderType colliderType) override;
	void Draw(Surface* screen) override;
private:
	int frameCounter;
	const IEnemyCollisionNotifier& collisionNotifier;
};

