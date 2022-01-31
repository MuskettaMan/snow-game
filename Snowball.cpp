#include "Snowball.h"

#include "Game.h"

Snowball::Snowball(vec2 origin, vec2 direction, ISnowballCollisionNotifier& snowballCollisionNotifier) : position(origin), velocity(direction.normalized() * Game::GetDeltaTime() * 0.4f), startTime(Game::GetTime()), rect(new Rect()), collider(new Collider(*rect, ColliderType::PROJECTILE, *this)), snowballCollisionNotifier(snowballCollisionNotifier)
{
	sprite = new Sprite(new Surface("assets/snowball.png"), 1);
	rect->size = vec2(sprite->GetWidth(), sprite->GetHeight());
}

Snowball::~Snowball()
{
	delete sprite;
	delete collider;
	delete rect;
}

void Snowball::Update()
{
	position += velocity;
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

Collider& Snowball::GetCollider() const
{
	return *collider;
}

void Snowball::NotifyCollision(ColliderType colliderType)
{
	snowballCollisionNotifier.NotifySnowballCollision(*this, colliderType);
}
