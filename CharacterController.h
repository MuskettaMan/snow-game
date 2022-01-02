#pragma once
#include "SantaCharacter.h"
#include "IInput.h"

class CharacterController
{
public:
	CharacterController(SantaCharacter* character, IInput* input);
	void ApplyMovement();

private:
	SantaCharacter* character;
	IInput* input;
};

