#pragma once
class ScoreTracker
{
public:
	ScoreTracker();
	int GetScore() const;
	void IncrementScore(int amount);

private:
	int score;
};

