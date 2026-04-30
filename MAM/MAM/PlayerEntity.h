#pragma once
#include "entity.h"
class PlayerEntity :
    public entity
{
public:
    PlayerEntity();
    void overlap(Collision* thisCollision, entity* otherEntity, Collision* otherCollision);
    sf::Vector2f update();
    //void render(sf::RenderWindow& window);
    char direction = 'U';

   

};

