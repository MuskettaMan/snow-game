#pragma once
#include "CharacterShooter.h"
#include "surface.h"
#include "template.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include "Rect.h"
#include "Collider.h"

using namespace Tmpl8;

class Character : public IDrawable, public IUpdatable
{
public:
	Character(char* sheet, int frames, float speed, vec2 position = vec2(400, 250));
	~Character();
	virtual void Move(vec2 direction);
	virtual void Shoot();
	virtual void Draw(Surface* screen) = 0;
	virtual void Update();
	bool GetIsMoving() const;
	bool GetIsFacingRight() const;
	vec2 GetPosition() const;
	vec2 GetLastMovingDirection() const;
	const Rect& GetRect() const;
	const Collider& GetCollider() const;
protected:
	Sprite* GetSprite() const;
private:
	Collider* collider;
	Rect* rect;
	vec2 position;
	Sprite* sprite;
	bool isMoving;
	vec2 velocity;
	vec2 lastMovingDirection;
	bool isFacingRight;
	float speed;
};

