#include "FieldCollider.h"

FieldCollider::FieldCollider(Border *border, Platform *platform)
{
    this->border = border;
    this->platform = platform;
}

sf::Vector2f FieldCollider::ballCollisionCoverDepth(sf::Vector2f position, int radius)
{
    sf::Vector2f result = border->ballCollisionCoverDepth(position, radius);
    if (result != sf::Vector2f(0, 0))
        return result;
    else
        return platform->ballCollisionCoverDepth(position, radius);
}
