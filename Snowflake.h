#pragma once
#include "IDrawable.h"
#include "template.h"
#include <random>

#include "IUpdatable.h"

using namespace Tmpl8;

/**
 * \brief A snowflake on the screen.
 */
class Snowflake : public IDrawable, public IUpdatable
{
public:
	/**
	 * \brief Creates a new snowflake.
	 */
	Snowflake();

	/**
	 * \brief Draws the snowflake to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) override;

	/**
	 * \brief Updates the snowflakes position and velocity.
	 */
	void Update() override;

	/**
	 * \brief Whether it reached the bottom of the screen.
	 * \return Whether it reached the bottom of the screen.
	 */
	bool GetReachedBottom() const;

	/**
	 * \brief Applies force to the snowflake.
	 * \param force The force to apply.
	 */
	void ApplyForce(vec2 force);

private:
	/**
	 * \brief Position of the snowflake on the screen.
	 */
	vec2 position;

	/**
	 * \brief Velocity of the snowflake.
	 */
	vec2 velocity;

	/**
	 * \brief Acceleration of the snowflake.
	 */
	vec2 acceleration;

	/**
	 * \brief The mass of the snowflake.
	 */
	float mass;

	/**
	 * \brief The radius of the snowflake.
	 */
	int radius;

	/**
	 * \brief Whether the snowflake reached the bottom.
	 */
	bool reachedBottom;

	/**
	 * \brief Clamps in screen space.
	 * \param value The value to clamp.
	 * \param max The maximum value.
	 * \return The clamped value.
	 */
	float ClampScreenSpace(float value, float max);

	/**
	 * \brief Performs an inverse linear interpolation.
	 * \param a Point a.
	 * \param b Point b.
	 * \param v The value.
	 * \return The inverse.
	 */
	float InvLerp(float a, float b, float v);
};

