#include "Snowball.h"

#include "game.h"

Snowball::Snowball(Tmpl8::vec2 origin, Tmpl8::vec2 direction) : position(origin), velocity(direction.normalized() * Tmpl8::Game::GetDeltaTime() * 0.4f), startTime(Tmpl8::Game::GetTime())
{
	sprite = new Tmpl8::Sprite(new Tmpl8::Surface("assets/snowball.png"), 1);
}

Snowball::~Snowball()
{
	delete sprite;
}

void Snowball::Update()
{
	position += velocity;
}

void Snowball::Draw(Tmpl8::Surface* screen) const
{
	sprite->Draw(screen, position.x, position.y);
}

float Snowball::GetStartTime()
{
	return startTime;
}
