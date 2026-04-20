#pragma once
#include "vector"
#include "Collision.h"

class CollisionManager
{
public:
	
	static CollisionManager& instance();

	void update()
	{
		for (Collision* collision1 : allCollision)
		{
			for (Collision* collision2 : allCollision)
			{
				if (collision1 == collision2)
				{
					continue;
				}
				sf::FloatRect CollisionA(collision1->GetPos(), collision1->GetSize());
				sf::FloatRect CollisionB(collision2->GetPos(), collision2->GetSize());

				if (CollisionA.intersects(CollisionB))
				{
					collision1->onOverlap.invoke(collision1, collision2->getOwner(), collision2);
					collision2->onOverlap.invoke(collision2, collision1->getOwner(), collision1);
				}
				
			}
		}
	}
	void addCollision(Collision* collision)
	{
		allCollision.push_back(collision);
	}

private:
	std::vector<Collision*> allCollision;
	CollisionManager() = default;

};

