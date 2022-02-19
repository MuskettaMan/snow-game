#pragma once
#include "IDrawable.h"
#include "ScoreTracker.h"

using namespace Tmpl8;

/**
 * \brief Displays the score on the screen.
 */
class ScoreDisplay : public IDrawable
{
public:
	/**
	 * \brief Creates a new score display.
	 * \param scoreTracker The object that tracks the score of the player.
	 */
	ScoreDisplay(const ScoreTracker& scoreTracker);

	/**
	 * \brief Destroys the score display.
	 */
	~ScoreDisplay();

	/**
	 * \brief Draws the score display to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) override;

private:
	/**
	 * \brief The object that tracks the score of the player. 
	 */
	const ScoreTracker& scoreTracker;

	/**
	 * \brief The font face for how the score should be shown.
	 */
	Sprite* fontFace;
};

