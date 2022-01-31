#include "ScoreTracker.h"

ScoreTracker::ScoreTracker() : score(0)
{
}

int ScoreTracker::GetScore() const
{
	return score;
}

void ScoreTracker::IncrementScore(int amount)
{
	score += amount;
}
