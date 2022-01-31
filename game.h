#pragma once
#include <vector>

#include "CharacterController.h"
#include "IDrawable.h"
#include "ImpCharacter.h"
#include "Input.h"
#include "IUpdatable.h"
#include "PresentFactory.h"
#include "ProximityFollower.h"
#include "RandomPlacementGenerator.h"
#include "SantaCharacter.h"
#include "TileMap.h"

namespace Tmpl8 {

class Surface;
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
	Surface* groundSheet;
	TileMapData* tileMapData;
	TileMap* tileMap;
	SantaCharacter* character;
	CharacterController* controller;
	Input* input;

	ImpCharacter* imp;
	ProximityFollower* proximityFollower;

	CollisionHandler* collisionHandler;

	RandomPlacementGenerator* randomPlacementGenerator;
	PresentFactory* presentFactory;

	std::vector<IDrawable*>* drawables;
	std::vector<IUpdatable*>* updatables;
	static float deltaTime;
	static float time;
};

}; // namespace Tmpl8