#pragma once

/**
 * \brief Defines an input interface.
 */
class IInput
{
public:
	/**
	 * \brief Destroys the input.
	 */
	virtual ~IInput() = default;

	/**
	 * \brief Whether the up key is pressed down.
	 * \return Whether the up key is pressed down.
	 */
	virtual bool GetUpKeyPressed() = 0;

	/**
	 * \brief Whether the down key is pressed down.
	 * \return Whether the down key is pressed down.
	 */
	virtual bool GetDownKeyPressed() = 0;

	/**
	 * \brief Whether the left key is pressed down.
	 * \return Whether the left key is pressed down.
	 */
	virtual bool GetLeftKeyPressed() = 0;

	/**
	 * \brief Whether the right key is pressed down.
	 * \return Whether the right key is pressed down.
	 */
	virtual bool GetRightKeyPressed() = 0;

	/**
	 * \brief Whether the space key is pressed down.
	 * \return Whether the space key is pressed down.
	 */
	virtual bool GetSpaceKeyPressed() = 0;
};

