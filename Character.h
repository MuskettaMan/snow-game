#pragma once
#include "CharacterShooter.h"
#include "surface.h"
#include "template.h"
#include "IDrawable.h"
#include "IUpdatable.h"

using namespace Tmpl8;

class Character : public IDrawable, public IUpdatable
{
public:
	Character(char* sheet);
	~Character();
	virtual void Move(vec2 direction);
	virtual void Draw(Surface* screen) = 0;
	virtual void Update();
	bool GetIsMoving() const;
	bool GetIsFacingRight() const;
	vec2 GetPosition() const;
	vec2 GetLastMovingDirection() const;
protected:
	Sprite* GetSprite() const;
private:
	vec2 position;
	Sprite* sprite;
	bool isMoving;
	vec2 velocity;
	vec2 lastMovingDirection;
	bool isFacingRight;
};

