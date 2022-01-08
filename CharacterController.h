#pragma once
#include "Character.h"
#include "IInput.h"
#include "IUpdatable.h"

class CharacterController : public IUpdatable
{
public:
	CharacterController(Character* character, IInput* input);
	void Update() override;

private:
	Character* character;
	IInput* input;
};

