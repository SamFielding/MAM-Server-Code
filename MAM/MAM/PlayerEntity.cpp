#include "PlayerEntity.h"
#include "SFML/Graphics.hpp"
#include <iostream>

PlayerEntity::PlayerEntity()
{
	col->onOverlap.bind(this, &PlayerEntity::overlap);

	col->addCollision();

}

void PlayerEntity::overlap(Collision* thisCollision, entity* otherEntity, Collision* otherCollision)
{
	//if (WallEntity* wall = dynamic_cast<WallEntity*>(otherEntity))
	//{

	//}

}

sf::Vector2f PlayerEntity::update()
{
	if (direction == 'u')
	{

	}
	else if (direction == 'D')
	{

	}
	else if (direction = 'L')
	{

	}
	else if (direction = 'R')
	{

	}
	else
	{
		std::cout << "Invalid Direction" << std::endl;
	}
	return sf::Vector2f();
}

void PlayerEntity::render(sf::RenderWindow& window)
{
	sf::RectangleShape playerSprite;
	playerSprite.setPosition(200.f, 200.f);

	playerSprite.setFillColor(sf::Color(255, 0, 0, 0));

	window.draw(playerSprite);


}
