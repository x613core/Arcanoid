#pragma once
#include "game.h"

#ifdef BLOCK
#define HEALTH_BLOCK
class HealthBlock : public Block
{
private:
    int health;

public:
    HealthBlock() {};
    HealthBlock(sf::Vector2u size, int health);

    virtual int Destroy() override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif