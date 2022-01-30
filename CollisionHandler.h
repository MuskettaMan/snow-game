#pragma once
#include <vector>
#include <algorithm>

#include "Collider.h"
#include "IUpdatable.h"

class CollisionHandler : public IUpdatable
{
public:
	CollisionHandler();
	~CollisionHandler();
	void Update() override;
	void Register(Collider* collider) const;
	void Deregister(Collider* collider);

private:
	std::vector<Collider*>* colliders;
};

