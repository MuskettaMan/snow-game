#include "CharacterController.h"

#include <iostream>

CharacterController::CharacterController(Character* character, IInput* input) : character(character), input(input)
{
}

void CharacterController::Update()
{
	vec2 direction(0, 0);
	if (input->GetDownKeyPressed())
		direction.y = 1;
	if (input->GetUpKeyPressed())
		direction.y = -1;
	if (input->GetLeftKeyPressed())
		direction.x = -1;
	if (input->GetRightKeyPressed())
		direction.x = 1;

	if (input->GetLeftKeyPressed() && input->GetRightKeyPressed())
		direction.x = 0;
	if (input->GetUpKeyPressed() && input->GetDownKeyPressed())
		direction.y = 0;

	if (input->GetSpaceKeyPressed())
		character->Shoot();

	character->Move(direction);
}
