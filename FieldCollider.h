#pragma once
#include "game.h"

#ifdef BORDER
#ifdef PLATFORM
class FieldCollider : public ICollider
{
private:
    Border *border;
    Platform *platform;

public:
    FieldCollider(Border *border, Platform *platform);

    virtual sf::Vector2f ballCollisionCoverDepth(sf::Vector2f position, int radius) override;
};
#endif
#endif
