#pragma once
#include "game.h"
#define BORDER

#ifdef GAME_OBJECT
class Border : public GameObject
{
private:
    sf::Vector2u size;

public:
    Border(sf::Vector2u size);

    bool ballEnteredCollision(sf::Vector2f position, int radius);
    sf::Vector2f ballCollisionCoverDepth(sf::Vector2f position, int radius);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif