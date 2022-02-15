#include "CollisionHandler.h"

#include <set>

CollisionHandler::CollisionHandler() : colliders(new std::vector<Collider*>())
{
}

CollisionHandler::~CollisionHandler()
{
	colliders->clear();
	delete colliders;
}

void CollisionHandler::Update()
{
	for (int i = 0; i < colliders->size(); ++i)
	{
		for (int j = 0; j < colliders->size(); ++j)
		{
			// Since we're double iterating over the same collection, if the indices are the same we know that it's the same object.
			// And we don't have to check twice on the same object for collision.
			if(i == j ||  colliders->at(i) == nullptr || colliders->at(j) == nullptr)
				continue;

			colliders->at(i)->Collides(*colliders->at(j));
		}
	}
	
	for (int i = colliders->size() - 1; i >= 0; --i)
	{
		if ((*colliders)[i] == nullptr)
			colliders->erase(colliders->begin() + i);
	}
}

void CollisionHandler::Register(Collider* collider) const
{
	colliders->push_back(collider);
}

void CollisionHandler::Deregister(Collider* collider)
{
	std::vector<Collider*>::iterator result = std::find(colliders->begin(), colliders->end(), collider);
	if (result != colliders->end())
		*result = nullptr;
}
