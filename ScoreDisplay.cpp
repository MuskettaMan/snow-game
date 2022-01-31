#include "ScoreDisplay.h"

ScoreDisplay::ScoreDisplay(const ScoreTracker& scoreTracker) : scoreTracker(scoreTracker)
{
}

void ScoreDisplay::Draw(Surface* screen)
{
	char numChar[10 + sizeof(char)];
	std::sprintf(numChar, "%d", scoreTracker.GetScore());
	screen->Print(numChar, 10, 10, 0x000000);
}
