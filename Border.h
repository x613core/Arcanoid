#pragma once
#include "game.h"

#ifdef GAME_OBJECT
class Border : public GameObject
{
private:
    sf::Vector2u size;

public:
    Border(sf::Vector2u size);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif