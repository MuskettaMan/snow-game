#pragma once
#include "Character.h"
#include "IInput.h"

class CharacterController
{
public:
	CharacterController(Character* character, IInput* input);
	void ApplyMovement();

private:
	Character* character;
	IInput* input;
};

