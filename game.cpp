#include "game.h"
#include "surface.h"
#include <cstdio> //printf

#include "Character.h"
#include "CharacterController.h"
#include "Input.h"
#include "TileMap.h"

namespace Tmpl8
{
	Surface* ground_sheet;
	TileMapData* tileMapData;
	TileMap* tileMap;
	Character* character;
	CharacterController* controller;
	Input* input;

	float Game::deltaTime;

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

		character = new Character();
		input = new Input();
		controller = new CharacterController(character, input);
	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
		delete ground_sheet;
		delete tileMapData;
		delete tileMap;

		delete character;
		delete input;
	}
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		Game::deltaTime = deltaTime;
		input->Poll();

		controller->ApplyMovement();

		tileMap->Draw(screen);
		character->Draw(screen);
	}

	float Game::GetDeltaTime()
	{
		return deltaTime;
	}
};