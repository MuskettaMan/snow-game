#include "game.h"
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
#include "ProximityFollower.h"

namespace Tmpl8
{
	Surface* ground_sheet;
	TileMapData* tileMapData;
	TileMap* tileMap;
	SantaCharacter* character;
	CharacterController* controller;
	Input* input;

	ImpCharacter* imp;
	ProximityFollower* proximityFollower;

	CollisionHandler* collisionHandler;

	std::vector<IDrawable*>* drawables;
	std::vector<IUpdatable*>* updatables;

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


	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{
		ground_sheet = new Surface("assets/ground_sheet.png");
		tileMapData =  new TileMapData(424, 64, 8, ground_sheet);
		tileMap = new TileMap(map, *tileMapData);

		input = new Input();

		character = new SantaCharacter(vec2(100, 100), 0.2f);
		controller = new CharacterController(character, input);

		imp = new ImpCharacter(vec2(500, 500), 0.09f);
		proximityFollower = new ProximityFollower(imp, character, 250);

		drawables = new std::vector<IDrawable*>();
		updatables = new std::vector<IUpdatable*>();

		collisionHandler = new CollisionHandler();
		collisionHandler->Register(&imp->GetCollider());
		collisionHandler->Register(&character->GetCollider());

		drawables->push_back(tileMap);
		drawables->push_back(imp);
		drawables->push_back(character);

		updatables->push_back(proximityFollower);
		updatables->push_back(imp);
		updatables->push_back(character);
		updatables->push_back(input);
		updatables->push_back(collisionHandler);
	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
		delete drawables;
		delete updatables;

		delete ground_sheet;
		delete tileMapData;
		delete tileMap;

		delete character;
		delete input;

		delete collisionHandler;
	}
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
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