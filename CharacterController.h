#pragma once
#include "Character.h"
#include "IInput.h"

/**
 * \brief Used for controlling a character instance based on the given input.
 */
class CharacterController
{
public:
	/**
	 * \brief Creates a new controller instance that controls the given character, based on the given input.
	 * \param character The character to control.
	 * \param input The input to poll from.
	 */
	CharacterController(Character* character, IInput* input);

	/**
	 * \brief Applies the movement from the input to the character.
	 */
	void ApplyMovement();

private:
	/**
	 * \brief The character to control.
	 */
	Character* character;

	/**
	 * \brief The input to use to move the player.
	 */
	IInput* input;
};

