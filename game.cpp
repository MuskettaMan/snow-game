#include "Game.h"
#include "surface.h"
#include <cstdio> //printf
#include <iostream>
#include <vector>

#include "Character.h"
#include "CharacterController.h"
#include "CollisionHandler.h"
#include "Input.h"
#include "TileMap.h"
#include "SantaCharacter.h"
#include "ImpCharacter.h"
#include "IUpdatable.h"
#include "PresentFactory.h"
#include "ProximityFollower.h"
#include "RandomPlacementGenerator.h"

namespace Tmpl8
{
	float Game::deltaTime;
	float Game::time;

	char map[TileMap::ROWS][TileMap::COLS * TileMap::DATA_AMOUNT] = {
		"af eb eb af fe ad ee ee fb fa fb db eb",
		"eb ec af eb eb ac fb fb ee fb fa dc eb",
		"eb eb ed ce cd dd fb ee ee ee fb db ec",
		"eb af ad ee fb ee ee ee fb ee fa dc eb",
		"eb fe ac fb fa fb fb fb ee ee fb db eb",
		"eb eb bc ba cb fb ee fb fb ab bb fd ec",
		"ec eb af eb bc ba bb ba bb fd eb eb eb",
		"eb ec eb ec eb eb eb fe eb eb ec eb fe"
	};

	void Game::Init()
	{
		groundSheet = new Surface("assets/ground_sheet.png");
		tileMapData =  new TileMapData(424, 64, 8, groundSheet);
		tileMap = new TileMap(map, *tileMapData);

		input = new Input();

		collisionHandler = new CollisionHandler();

		character = new SantaCharacter(vec2(100, 100), 0.2f, collisionHandler);
		controller = new CharacterController(character, input);

		imp = new ImpCharacter(vec2(500, 500), 0.09f);
		proximityFollower = new ProximityFollower(imp, character, 250);

		scoreTracker = new ScoreTracker();
		scoreDisplay = new ScoreDisplay(*scoreTracker);

		snowstormManager = new SnowstormManager();

		randomPlacementGenerator = new RandomPlacementGenerator(*character);
		presentFactory = new PresentFactory(*randomPlacementGenerator, collisionHandler, *scoreTracker);

		presentFactory->GeneratePresent();
		presentFactory->GeneratePresent();
		presentFactory->GeneratePresent();
		presentFactory->GeneratePresent();

		drawables = new std::vector<IDrawable*>();
		updatables = new std::vector<IUpdatable*>();

		collisionHandler->Register(&imp->GetCollider());
		collisionHandler->Register(&character->GetCollider());

		drawables->push_back(tileMap);
		drawables->push_back(presentFactory);
		drawables->push_back(imp);
		drawables->push_back(character);
		drawables->push_back(scoreDisplay);
		drawables->push_back(snowstormManager);

		updatables->push_back(proximityFollower);
		updatables->push_back(imp);
		updatables->push_back(character);
		updatables->push_back(input);
		updatables->push_back(collisionHandler);
		updatables->push_back(snowstormManager);
	}
	
	void Game::Shutdown()
	{
		delete updatables;
		delete drawables;

		delete presentFactory;
		delete randomPlacementGenerator;

		delete proximityFollower;
		delete imp;

		delete controller;
		delete character;

		delete collisionHandler;

		delete input;

		delete snowstormManager;

		delete scoreDisplay;
		delete scoreTracker;

		delete tileMap;
		delete tileMapData;
		delete groundSheet;
	}

	void Game::Tick(float deltaTime)
	{
		Game::deltaTime = deltaTime;
		Game::time += deltaTime;

		controller->ApplyMovement();

		for (int i = 0; i < updatables->size(); i++)
		{
			(*updatables)[i]->Update();
		}

		for (int i = 0; i < drawables->size(); i++)
		{
			(*drawables)[i]->Draw(screen);
		}
	}

	float Game::GetDeltaTime()
	{
		return deltaTime;
	}

	float Game::GetTime()
	{
		return time;
	}
};