#include "ScoreDisplay.h"

#include <vector>

ScoreDisplay::ScoreDisplay(const ScoreTracker& scoreTracker) : scoreTracker(scoreTracker), fontFace(new Sprite(new Surface("assets/score_face.png"), 10))
{
}

ScoreDisplay::~ScoreDisplay()
{
	delete fontFace;
}

void ScoreDisplay::Draw(Surface* screen)
{
	std::vector<int> digits;
	for (int score = scoreTracker.GetScore(); score != 0; score /= 10)
		digits.push_back(score % 10);
	std::reverse(digits.begin(), digits.end());
	for (int i = 0; i < digits.size(); i++)
	{
		fontFace->SetFrame(digits[i]);
		//fontFace->Draw(screen, 10 + i * 33, 10);
	}
}
