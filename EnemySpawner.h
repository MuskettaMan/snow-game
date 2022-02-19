#pragma once
#include <vector>

#include "IEnemyCollisionNotifier.h"
#include "ImpCharacter.h"
#include "IPlacementGenerator.h"
#include "IUpdatable.h"
#include "ProximityFollower.h"

struct ProximityCharacter;
using namespace Tmpl8;

class EnemySpawner : public IUpdatable, public IDrawable, public IEnemyCollisionNotifier
{
public:
	EnemySpawner(Character& target, CollisionHandler& collisionHandler);
	~EnemySpawner();
	void Update() override;
	void Draw(Surface* screen) override;
	void NotifyEnemyCollision(const Character& character) const override;

private:
	std::vector<ProximityCharacter*>* followers;
	Character& target;
	float startTime;
	float interval;
	CollisionHandler& collisionHandler;
	IPlacementGenerator* placementGenerator;

	void CreateEnemy();
	void OnEnemyCollision(const ImpCharacter& enemy);
};

struct ProximityCharacter
{
	Character* character;
	ProximityFollower* follower;

	ProximityCharacter(Character* character, ProximityFollower* follower) : character(character), follower(follower)
	{
		
	}

	~ProximityCharacter()
	{
		delete character;
		delete follower;
	}
};
