#pragma once
#include <vector>

#include "IDrawable.h"
#include "IUpdatable.h"
#include "Snowflake.h"

using namespace Tmpl8;

/**
 * \brief Manages the snowstorm of snowflakes.
 */
class SnowstormManager : public IDrawable, public IUpdatable
{
public:
	/**
	 * \brief Creates a new snowstorm.
	 */
	SnowstormManager();

	/**
	 * \brief Destroys the snowstorm.
	 */
	~SnowstormManager();

	/**
	 * \brief Draws all the flakes to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) override;

	/**
	 * \brief Updates all the positions of the snowflakes.
	 */
	void Update() override;

	/**
	 * \brief The gravity of the snowstorm.
	 */
	const vec2 GRAVITY = vec2(0, 0.5f);

private:
	/**
	 * \brief All the composed snowflakes.
	 */
	std::vector<Snowflake*>* snowflakes;

	/**
	 * \brief The last spawn time of a snow flake.
	 */
	float lastSpawnTime;

	/**
	 * \brief The interval to spawn in.
	 */
	float interval;
};

