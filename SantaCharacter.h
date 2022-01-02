#pragma once
#include "Character.h"

class SantaCharacter : public Character
{
public: 
	SantaCharacter();
	~SantaCharacter();
	void Draw(Surface* screen) override;
	void Update() override;
	void Shoot() override;
private:
	CharacterShooter* shooter;
	uint movementFrameCounter;
};

