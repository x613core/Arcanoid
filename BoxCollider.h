#pragma once
#include "game.h"

#define BOX_COLLIDER
class BoxCollider : public ICollider
{
protected:
    sf::Vector2u size;
    sf::Vector2f currentPosition;

public:
    virtual sf::Vector2f ballCollisionCoverDepth(sf::Vector2f position, int radius) override;
};