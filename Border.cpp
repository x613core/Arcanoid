#include "Border.h"

Border::Border(sf::Vector2u size)
{
    this->size = size;
    tag = BORDER_TAG;
    _redZoneToched = 0;
}

bool Border::redZoneToched()
{
    return _redZoneToched;
}

bool Border::ballEnteredCollision(sf::Vector2f position, int radius)
{
    sf::Vector2f thisPosition = getPosition();
    return position.x <= thisPosition.x ||
           position.y <= thisPosition.y ||
           position.x + 2 * radius >= thisPosition.x + size.x ||
           position.y + 2 * radius >= thisPosition.y + size.y;
}

sf::Vector2f Border::ballCollisionCoverDepth(sf::Vector2f position, int radius)
{
    _redZoneToched = 0;
    sf::Vector2f result;
    sf::Vector2f thisPosition = getPosition();

    if (position.x <= thisPosition.x + BORDER_THICKNESS)
        result.x = thisPosition.x + BORDER_THICKNESS - position.x;
    else if (position.x + 2 * radius >= thisPosition.x + size.x)
        result.x = position.x + 2 * radius - thisPosition.x - size.x;
    else
        result.x = 0;

    if (position.y <= thisPosition.y + BORDER_THICKNESS)
        result.y = thisPosition.y + BORDER_THICKNESS - position.y;
    else if (position.y + 2 * radius >= thisPosition.y + size.y - BORDER_THICKNESS)
    {
        result.y = position.y + 2 * radius - thisPosition.y - size.y + BORDER_THICKNESS;
        _redZoneToched = 1;
    }
    else
        result.y = 0;

    return result;
}

void Border::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    auto startTransform = states.transform;

    sf::RectangleShape verticalLine(sf::Vector2f(BORDER_THICKNESS, size.y));
    sf::RectangleShape horisontalLine(sf::Vector2f(size.x, BORDER_THICKNESS));
    verticalLine.setFillColor(BASE_COLOR);
    horisontalLine.setFillColor(BASE_COLOR);
    target.draw(verticalLine, states);
    target.draw(horisontalLine, states);

    states.transform.translate(sf::Vector2f(size.x, 0));
    target.draw(verticalLine, states);

    states.transform = startTransform;
    states.transform.translate(sf::Vector2f(BORDER_THICKNESS, size.y - BORDER_THICKNESS));
    horisontalLine.setSize(sf::Vector2f(size.x - BORDER_THICKNESS, BORDER_THICKNESS));
    horisontalLine.setFillColor(DEAD_COLOR);
    target.draw(horisontalLine, states);
}