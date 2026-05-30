#include "Platform.h"

Platform::Platform(sf::Vector2u size, sf::Vector2i xPositionLimit)
{
    this->size = size;
    this->xPositionLimit = xPositionLimit;
    this->currentPosition = getPosition();
}

void Platform::setNewPosition(sf::Vector2i newPosition)
{
    auto currentPos = getPosition();
    if (newPosition.x > xPositionLimit.x && (newPosition.x + size.x) < xPositionLimit.y)
        this->newPosition.x = newPosition.x;
    else
        this->newPosition.x = currentPos.x;

    this->newPosition.y = currentPos.y;
}

void Platform::update()
{
    setPosition(sf::Vector2f(newPosition.x, newPosition.y));
    this->currentPosition = getPosition();
}

void Platform::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    sf::RectangleShape platform(sf::Vector2f(size.x, size.y));
    platform.setFillColor(BASE_COLOR);

    target.draw(platform, states);
}
