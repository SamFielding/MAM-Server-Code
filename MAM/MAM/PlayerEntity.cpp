#include "PlayerEntity.h"
#include "SFML/Graphics.hpp"

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

void PlayerEntity::render(sf::RenderWindow& window)
{
	sf::RectangleShape playerSprite;
	playerSprite.setPosition(200.f, 200.f);

	playerSprite.setFillColor(sf::Color(255, 0, 0, 0));

	window.draw(playerSprite);


}
