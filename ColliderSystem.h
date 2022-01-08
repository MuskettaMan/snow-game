#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Collider.h"
#include "IUpdatable.h"
#include "ColliderLibrary.h"

class ColliderSystem : public IUpdatable
{
public:
	void Register(const Collider& collider);
	void Unregister(const Collider& collider);
	void Update() override;

private:
	std::vector<const Collider*> colliders;
};

