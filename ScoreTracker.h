#pragma once

/**
 * \brief Keeps track of the score for the player.
 */
class ScoreTracker
{
public:
	/**
	 * \brief Creates a new score tracker.
	 */
	ScoreTracker();

	/**
	 * \brief Retrieves the score.
	 * \return The score of the player.
	 */
	int GetScore() const;

	/**
	 * \brief Increases the score by a given amount.
	 * \param amount The amount by which the score should be incremented.
	 */
	void IncrementScore(int amount);

private:
	/**
	 * \brief The current score.
	 */
	int score;
};

