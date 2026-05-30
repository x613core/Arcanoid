#pragma once
#include "game.h"

class ICollider
{
public:
    virtual sf::Vector2f ballCollisionCoverDepth(sf::Vector2f position, int radius) = 0;
};
