#include "Collision.h"
#include "CollisionManager.h"

Collision::Collision()
{
	//Collision.entCollision.onOverlap.bind(this, &Entity::overlap);

}

const sf::Vector2f& Collision::GetPos() const
{

	return pos;
	// TODO: insert return statement here
}

const sf::Vector2f& Collision::GetSize() const
{

	return size;
	// TODO: insert return statement here
}

void Collision::SetPos(const sf::Vector2f& pos)
{
	this->pos = pos;

}

void Collision::SetSize(const sf::Vector2f& size)
{
	this->size = size;
}

bool Collision::ContainsPoint(const sf::Vector2f& pos)
{
	sf::FloatRect thisCollision(this->pos, size);
	
	return thisCollision.contains(pos);
}

bool Collision::IsOverlapping(const Collision& col)
{
	sf::FloatRect thisCollision(pos, size);
	sf::FloatRect otherCollision(col.GetPos(), col.GetSize());

	return thisCollision.intersects(otherCollision);
}

void Collision::setOwner(entity* owner)
{
	this->owner = owner;
}

entity* Collision::getOwner() const
{
	return owner;
}

void Collision::addCollision()
{
	CollisionManager::instance().addCollision(this);
}
