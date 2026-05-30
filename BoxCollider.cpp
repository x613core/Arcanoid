#include "BoxCollider.h"

sf::Vector2f BoxCollider::ballCollisionCoverDepth(sf::Vector2f position, int radius)
{
    position = sf::Vector2f(position.x + radius, position.y + radius);

    if (position.x + radius < currentPosition.x ||
        position.x - radius > currentPosition.x + size.x)
        return sf::Vector2f(0, 0);
    else if (position.y - radius > currentPosition.y + size.y ||
             position.y + radius < currentPosition.y)
        return sf::Vector2f(0, 0);
    else if (position.x > currentPosition.x && position.x < currentPosition.x + size.x)
    {
        float resultY = std::abs(position.y - currentPosition.y) + radius;
        return sf::Vector2f(0, resultY);
    }
    else if (position.y > currentPosition.y && position.y < currentPosition.y + size.y)
    {
        float resultX = std::abs(position.x - currentPosition.x) + radius;
        return sf::Vector2f(resultX, 0);
    }

    return sf::Vector2f(0, 0);
}