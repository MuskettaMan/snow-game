#pragma once
#include "Character.h"
class ImpCharacter : public Character
{
public:
	ImpCharacter(vec2 position, float speed);
	~ImpCharacter();
	void NotifyCollision(ColliderType colliderType) override;
	void Draw(Surface* screen) override;
private:
	int frameCounter;
};

