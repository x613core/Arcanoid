#pragma once
#include "game.h"

enum class SpeedMode
{
    none = 0,
    increase,
    decrease
};

#ifdef BLOCK
#define SPEED_BLOCK
class SpeedBlock : public Block
{
private:
    SpeedMode mode;

public:
    SpeedBlock() {};
    SpeedBlock(sf::Vector2u size, SpeedMode mode);

    virtual int Destroy() override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif
