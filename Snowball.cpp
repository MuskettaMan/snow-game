#include "Snowball.h"

#include "game.h"

Snowball::Snowball(vec2 origin, vec2 direction) : position(origin), velocity(direction.normalized() * Game::GetDeltaTime() * 0.4f), startTime(Game::GetTime())
{
	sprite = new Sprite(new Surface("assets/snowball.png"), 1);
	rect = new Rect(position, vec2(sprite->GetWidth(), sprite->GetHeight()));
	collider = new Collider(*rect, CollisionType::Projectile);
}

Snowball::~Snowball()
{
	delete collider;
	delete rect;
	delete sprite;
}

void Snowball::Update()
{
	position += velocity;
	rect->size = vec2(sprite->GetWidth(), sprite->GetHeight());
	rect->position = position;
}

void Snowball::Draw(Surface* screen) const
{
	sprite->Draw(screen, position.x, position.y);
}

float Snowball::GetStartTime()
{
	return startTime;
}

const Collider& Snowball::GetCollider() const
{
	return *collider;
}
