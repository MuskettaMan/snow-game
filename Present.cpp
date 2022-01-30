#include "Present.h"

Present::Present(int pointsToReward, int spriteFrame, vec2 position) : pointsToReward(pointsToReward),
																	   sprite(new Sprite(new Surface("assets/gift_sheet.png"), 3)),
																	   rect(new Rect(position, { static_cast<float>(sprite->GetWidth()), static_cast<float>(sprite->GetHeight()) })),
																	   collider(new Collider(*rect, ColliderType::PRESENT, *this))
{
	sprite->SetFrame(spriteFrame);
}

Present::~Present()
{
	delete collider;
	delete rect;
	delete sprite;
}

int Present::GetPointsToReward() const
{
	return pointsToReward;
}

void Present::NotifyCollision(ColliderType colliderType)
{
}

void Present::Draw(Surface* screen)
{
	sprite->Draw(screen, rect->position.x, rect->position.y);
}

Rect* Present::GetRect()
{
	return rect;
}

Collider* Present::GetCollider()
{
	return collider;
}
