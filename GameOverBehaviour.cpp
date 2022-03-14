#include "GameOverBehaviour.h"

#include <iostream>

GameOverBehaviour::GameOverBehaviour() : gameOverScreen(new Surface("assets/game_over.png")), isGameOver(false)
{
}

void GameOverBehaviour::Draw(Surface* screen)
{
	if (!isGameOver)
		return;
	
	gameOverScreen->CopyTo(screen, 0, 0);
}

void GameOverBehaviour::SetGameOver()
{
	isGameOver = true;
}
