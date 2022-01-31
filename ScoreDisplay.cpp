#include "ScoreDisplay.h"

ScoreDisplay::ScoreDisplay(const ScoreTracker& scoreTracker) : scoreTracker(scoreTracker)
{
}

void ScoreDisplay::Draw(Surface* screen)
{
	char numChar[10 + sizeof(char)];
	std::sprintf(numChar, "%d", scoreTracker.GetScore());
	screen->Print(numChar, 20, 20, 0x000000);
}
