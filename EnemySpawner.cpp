#include "EnemySpawner.h"

#include <iostream>

#include "Game.h"

EnemySpawner::EnemySpawner(Character& target, CollisionHandler& collisionHandler) : followers(new std::vector<ProximityCharacter*>), target(target), startTime(Game::GetTime()), interval(10000), collisionHandler(collisionHandler), placementGenerator(new RandomPlacementGenerator(target))
{
	CreateEnemy();
}

EnemySpawner::~EnemySpawner()
{
	for (int i = 0; i < followers->size(); ++i)
	{
		collisionHandler.Deregister(&followers->at(i)->character->GetCollider());
		delete followers->at(i);
	}
	delete followers;
	delete placementGenerator;
}

void EnemySpawner::Update()
{
	for (int i = 0; i < followers->size(); ++i)
	{
		followers->at(i)->follower->Update();
		followers->at(i)->character->Update();
	}

	if(Game::GetTime() - startTime > interval)
	{
		startTime = Game::GetTime();
		interval *= 0.95f;

		CreateEnemy();
	}
}

void EnemySpawner::Draw(Surface* screen)
{
	for (int i = 0; i < followers->size(); ++i)
	{
		followers->at(i)->character->Draw(screen);
	}
}

void EnemySpawner::NotifyEnemyCollision(const Character& character) const
{
	std::vector<ProximityCharacter*>::iterator it;
	ProximityCharacter* found;
	for (it = followers->begin(); it != followers->end(); ++it)
	{
		if ((*it)->character == &character)
		{
			found = *it;

			break;
		}
	}

	collisionHandler.Deregister(&found->character->GetCollider());
	followers->erase(it);
	delete found;
}

void EnemySpawner::CreateEnemy()
{
	ImpCharacter* imp = new ImpCharacter(placementGenerator->GetPlacement(), 0.09f, *this);
	ProximityFollower* follower = new ProximityFollower(imp, &target, 500);
	followers->push_back(new ProximityCharacter(imp, follower));
	collisionHandler.Register(&imp->GetCollider());
}
