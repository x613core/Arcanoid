#pragma once
#include "game.h"

#ifdef GAME_OBJECT
#ifdef BOX_COLLIDER
#define PLATFORM

class Platform : public GameObject, public Uptadable, public BoxCollider
{
private:
    sf::Vector2i newPosition;
    sf::Vector2i xPositionLimit;

public:
    Platform(sf::Vector2u size, sf::Vector2i xPositionLimit);
    void setNewPosition(sf::Vector2i newPosition);

    virtual void update() override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif
#endif
