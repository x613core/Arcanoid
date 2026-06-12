#pragma once
#include "game.h"

#ifdef BLOCK
#define BORDER_BLOCK
class BorderBlock : public Block
{
public:
    BorderBlock() {};
    BorderBlock(sf::Vector2u size);

    virtual int Destroy() override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif