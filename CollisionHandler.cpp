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
	std::set<int> nullIndices;
	for (int i = 0; i < colliders->size(); ++i)
	{
		for (int j = 0; j < colliders->size(); ++j)
		{
			if (colliders->at(i) == nullptr)
				nullIndices.insert(i);

			// Since we're double iterating over the same collection, if the indices are the same we know that it's the same object.
			// And we don't have to check twice on the same object for collision.
			if(i == j ||  colliders->at(i) == nullptr || colliders->at(j) == nullptr)
				continue;

			colliders->at(i)->Collides(*colliders->at(j));
		}
	}

	for (int nullIndex : nullIndices)
	{
		colliders->erase(colliders->begin() + nullIndex);
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
