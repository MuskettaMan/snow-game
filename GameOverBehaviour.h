#pragma once
#include "IDrawable.h"
#include "IUpdatable.h"

using namespace Tmpl8;

class GameOverBehaviour : public IDrawable
{
public:
	GameOverBehaviour();
	void Draw(Surface* screen) override;
	void SetGameOver();

private:
	Surface* gameOverScreen;
	bool isGameOver;
};

