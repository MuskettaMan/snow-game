#pragma once
#include "IInput.h"
#include "IUpdatable.h"


/**
 * \brief An input implementation.
 */
class Input : public IInput, public IUpdatable
{
public:
	/**
	 * \brief Whether the up key is pressed down.
	 * \return Whether the up key is pressed down.
	 */
	bool GetUpKeyPressed() override;

	/**
	 * \brief Whether the down key is pressed down.
	 * \return Whether the down key is pressed down.
	 */
	bool GetDownKeyPressed() override;

	/**
	 * \brief Whether the left key is pressed down.
	 * \return Whether the left key is pressed down.
	 */
	bool GetLeftKeyPressed() override;

	/**
	 * \brief Whether the right key is pressed down.
	 * \return Whether the right key is pressed down.
	 */
	bool GetRightKeyPressed() override;

	/**
	 * \brief Whether the space key is pressed down.
	 * \return Whether the space key is pressed down.
	 */
	bool GetSpaceKeyPressed() override;

	/**
	 * \brief Polls for input.
	 */
	void Update() override;

private:
	/**
	 * \brief Whether up key is pressed.
	 */
	bool up;

	/**
	 * \brief Whether down key is pressed.
	 */
	bool down;

	/**
	 * \brief Whether left key is pressed.
	 */
	bool left;

	/**
	 * \brief Whether right key is pressed.
	 */
	bool right;

	/**
	 * \brief Whether space key is pressed.
	 */
	bool space;
};

