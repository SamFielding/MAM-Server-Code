#pragma once
#include "SFML/Graphics.hpp"
#include "delegate.h"

class entity;
class Collision
{
public:
	Collision();
	const sf::Vector2f& GetPos() const;
	const sf::Vector2f& GetSize() const;

	void SetPos(const sf::Vector2f& pos);
	void SetSize(const sf::Vector2f& size);
	bool ContainsPoint(const sf::Vector2f& pos);
	bool IsOverlapping(const Collision& col);
	void setOwner(entity*owner);
	entity* getOwner() const;
	Delegate<Collision*, entity*, Collision*> onOverlap;
	void addCollision();
	

private:
	sf::Vector2f pos;
	sf::Vector2f size;

	entity* owner;

	



};

