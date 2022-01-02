#pragma once
#include "Character.h"

class SantaCharacter : public Character
{
public: 
	SantaCharacter(float speed);
	~SantaCharacter();
	void Draw(Surface* screen) override;
	void Update() override;
	void Shoot() override;
private:
	CharacterShooter* shooter;
	uint movementFrameCounter;
};

