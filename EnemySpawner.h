#pragma once
#include <vector>

#include "IEnemyCollisionNotifier.h"
#include "ImpCharacter.h"
#include "IPlacementGenerator.h"
#include "IUpdatable.h"
#include "ProximityFollower.h"

struct ProximityCharacter;
using namespace Tmpl8;

/**
 * \brief Spawning behaviour for spawning enemies.
 */
class EnemySpawner : public IUpdatable, public IDrawable, public IEnemyCollisionNotifier
{
public:
	/**
	 * \brief Creates a new enemy spawner.
	 * \param target The target to follow.
	 * \param collisionHandler The collision handler to manage collisions for the enemies.
	 */
	EnemySpawner(Character& target, CollisionHandler& collisionHandler);

	/**
	 * \brief Destroys the enemy spawner.
	 */
	~EnemySpawner();

	/**
	 * \brief Updates the behaviours of the enemies.
	 */
	void Update() override;

	/**
	 * \brief Draws the enemies to the screen.
	 * \param screen The screen to draw to.
	 */
	void Draw(Surface* screen) override;
	void NotifyEnemyCollision(const Character& character) const override;

	/**
	 * \brief Notifies of an enemy collision.
	 * \param character The character that was collided with.
	 */
	void NotifyEnemyCollision(const Character& character) const override;

private:
	/**
	 * \brief All the composed enemies.
	 */
	std::vector<ProximityCharacter*>* followers;

	/**
	 * \brief The target to follow.
	 */
	Character& target;

	/**
	 * \brief The start time of the object.
	 */
	float startTime;

	/**
	 * \brief The interval for spawning enemies.
	 */
	float interval;

	/**
	 * \brief The collision handler to manage collisions for the enemies.
	 */
	CollisionHandler& collisionHandler;

	/**
	 * \brief The placement generator for placing enemies.
	 */
	IPlacementGenerator* placementGenerator;

	/**
	 * \brief Creates an enemy.
	 */
	void CreateEnemy();

	/**
	 * \brief Called when an enemy collision occurs.
	 * \param enemy The enemy that was collided.
	 */
	void OnEnemyCollision(const ImpCharacter& enemy);
};

/**
 * \brief Defines a pair for a character and proximity follower.
 */
struct ProximityCharacter
{
	/**
	 * \brief Character reference.
	 */
	Character* character;

	/**
	 * \brief Follower reference.
	 */
	ProximityFollower* follower;

	/**
	 * \brief Creates a new proximity character.
	 * \param character Character reference.
	 * \param follower Follower reference.
	 */
	ProximityCharacter(Character* character, ProximityFollower* follower) : character(character), follower(follower)
	{
		
	}

	/**
	 * \brief Destroys the proximity character.
	 */
	~ProximityCharacter()
	{
		delete character;
		delete follower;
	}
};
