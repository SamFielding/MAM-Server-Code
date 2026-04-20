#include "CollisionManager.h"

CollisionManager& CollisionManager::instance()
{

    static CollisionManager instance;
    return instance;
    // TODO: insert return statement here
}
