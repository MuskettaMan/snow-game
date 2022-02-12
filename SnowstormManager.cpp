#include "SnowstormManager.h"

#include <iostream>

#include "Game.h"

SnowstormManager::SnowstormManager() : lastSpawnTime(0), interval(100)
{
	snowflakes = new std::vector<Snowflake*>();
}

SnowstormManager::~SnowstormManager()
{
	for (int i = 0; i < snowflakes->size(); ++i)
	{
		delete (*snowflakes)[i];
	}
	delete snowflakes;
}

void SnowstormManager::Draw(Surface* screen)
{
	for (int i = 0; i < snowflakes->size(); ++i)
	{
		(*snowflakes)[i]->Draw(screen);
	}
}

/**
 * \brief
 * TODO: Make use of pooling for optimization.
 */
void SnowstormManager::Update()
{
	if(Game::GetTime() - (lastSpawnTime + interval) > 0)
	{
		lastSpawnTime = Game::GetTime();
		snowflakes->push_back(new Snowflake());
	}
	std::vector<int> indicesToRemove;
	for (int i = 0; i < snowflakes->size(); ++i)
	{
		(*snowflakes)[i]->ApplyForce(GRAVITY);
		(*snowflakes)[i]->Update();

		if((*snowflakes)[i]->GetReachedBottom())
		{
			delete (*snowflakes)[i];
			(*snowflakes)[i] = nullptr;
			indicesToRemove.push_back(i);
		}
	}

	for (int i = indicesToRemove.size() - 1; i >= 0; --i)
	{
		snowflakes->erase(snowflakes->begin() + indicesToRemove[i]);
	}
}
