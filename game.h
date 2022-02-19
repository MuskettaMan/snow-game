#pragma once
#include <vector>

#include "CharacterController.h"
#include "EnemySpawner.h"
#include "IDrawable.h"
#include "ImpCharacter.h"
#include "Input.h"
#include "IUpdatable.h"
#include "PresentFactory.h"
#include "ProximityFollower.h"
#include "RandomPlacementGenerator.h"
#include "SantaCharacter.h"
#include "ScoreDisplay.h"
#include "SnowstormManager.h"
#include "TileMap.h"

namespace Tmpl8 {

class Surface;

/**
 * \brief Manages all the variables for the game.
 */
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }

	static float GetDeltaTime();
	static float GetTime();
private:
	Surface* screen;

	/**
	 * \brief The spritesheet for the ground tiles.
	 */
	Surface* groundSheet;

	/**
	 * \brief The tilemap data for the ground.
	 */
	TileMapData* tileMapData;

	/**
	 * \brief The tilemap for the ground.
	 */
	TileMap* tileMap;

	/**
	 * \brief The santa character.
	 */
	SantaCharacter* character;

	/**
	 * \brief The controller for moving the santa character.
	 */
	CharacterController* controller;

	/**
	 * \brief The input for providing input.
	 */
	Input* input;

	/**
	 * \brief Spawns enemies.
	 */
	EnemySpawner* enemySpawner;

	/**
	 * \brief Handles the collison for all the colliders.
	 */
	CollisionHandler* collisionHandler;

	/**
	 * \brief Provides random placements.
	 */
	RandomPlacementGenerator* randomPlacementGenerator;

	/**
	 * \brief Generates presents.
	 */
	PresentFactory* presentFactory;

	/**
	 * \brief Tracks the score of the player.
	 */
	ScoreTracker* scoreTracker;

	/**
	 * \brief Displays the score.
	 */
	ScoreDisplay* scoreDisplay;

	/**
	 * \brief Manages the snowstorm.
	 */
	SnowstormManager* snowstormManager;

	/**
	 * \brief All the objects that can be drawn to the screen.
	 */
	std::vector<IDrawable*>* drawables;

	/**
	 * \brief All the objects that can be updated.
	 */
	std::vector<IUpdatable*>* updatables;

	/**
	 * \brief The delta time of the current frame.
	 */
	static float deltaTime;

	/**
	 * \brief The total time passed.
	 */
	static float time;
};

}