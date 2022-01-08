#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <iostream>
#include <vector>

#include "Character.h"
#include "CharacterController.h"
#include "Input.h"
#include "TileMap.h"
#include "SantaCharacter.h"
#include "ImpCharacter.h"
#include "IUpdatable.h"
#include "ProximityFollower.h"
#include "ColliderLibrary.h"
#include "ColliderSystem.h"

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

	ColliderSystem* colliderSystem;

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

		character = new SantaCharacter(0.2f);
		controller = new CharacterController(character, input);

		imp = new ImpCharacter(0.09f);
		proximityFollower = new ProximityFollower(imp, character, 250);

		colliderSystem = new ColliderSystem();
		colliderSystem->Register(character->GetCollider());
		colliderSystem->Register(imp->GetCollider());

		drawables = new std::vector<IDrawable*>();
		updatables = new std::vector<IUpdatable*>();

		drawables->push_back(tileMap);
		drawables->push_back(imp);
		drawables->push_back(character);

		updatables->push_back(colliderSystem);
		updatables->push_back(controller);
		updatables->push_back(proximityFollower);
		updatables->push_back(imp);
		updatables->push_back(character);
		updatables->push_back(input);
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

		delete colliderSystem;
	}
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		Game::deltaTime = deltaTime;
		Game::time += deltaTime;

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