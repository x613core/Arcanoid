#pragma once
#include "game.h"

#ifdef GAME_OBJECT
#ifdef BOX_COLLIDER
#define BLOCK
class Block : public BoxCollider, public GameObject
{
protected:
    bool _isDestroyed;

public:
    Block() {};
    Block(sf::Vector2u size);

    bool isDestryed();
    virtual int Destroy();
    void updatePosition();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif
#endif