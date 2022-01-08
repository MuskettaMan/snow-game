#include "ColliderSystem.h"
#include <iostream>

void ColliderSystem::Register(const Collider& collider)
{
	if (&collider == NULL)
		throw new std::invalid_argument("collider");

	colliders.push_back(&collider);
}

void ColliderSystem::Unregister(const Collider& collider)
{
	if (&collider == NULL)
		throw new std::invalid_argument("collider");

	std::vector<const Collider const*>::iterator it = std::find(colliders.begin(), colliders.end(), &collider);
	if (it != colliders.end())
	{
		colliders.erase(it);
	}
}

void ColliderSystem::Update()
{
	for (int i = 0; i < colliders.size(); i++)
	{
		for (int j = 0; j < colliders.size(); j++)
		{
			// Skip if both elements are the same.
			if (i == j)
				continue;

			bool overlap = ColliderLibrary::RectRect(colliders[i]->GetRect(), colliders[j]->GetRect());
			if (overlap)
			{
				colliders[i]->Collides(*colliders[j]);
				colliders[j]->Collides(*colliders[i]);
			}
		}
	}
}
