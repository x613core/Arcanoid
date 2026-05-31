#pragma once
#include "game.h"

#ifdef GAME_OBJECT
#define BORDER

class Border : public GameObject, public ICollider
{
private:
    sf::Vector2u size;
    bool _redZoneToched;

public:
    Border() {};
    Border(sf::Vector2u size);

    bool redZoneToched();
    bool ballEnteredCollision(sf::Vector2f position, int radius);

    virtual sf::Vector2f ballCollisionCoverDepth(sf::Vector2f position, int radius) override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif