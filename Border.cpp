#include "Border.h"

Border::Border(sf::Vector2u size)
{
    this->size = size;
    tag = BORDER_TAG;
}

void Border::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    auto startTransform = states.transform;

    sf::RectangleShape verticalLine(sf::Vector2f(BORDER_THICKNESS, size.y));
    sf::RectangleShape horisontalLine(sf::Vector2f(size.x, BORDER_THICKNESS));
    verticalLine.setFillColor(sf::Color::White);
    horisontalLine.setFillColor(sf::Color::White);
    target.draw(verticalLine, states);
    target.draw(horisontalLine, states);

    states.transform.translate(sf::Vector2f(size.x, 0));
    target.draw(verticalLine, states);

    states.transform = startTransform;
    states.transform.translate(sf::Vector2f(BORDER_THICKNESS, size.y - BORDER_THICKNESS));
    horisontalLine.setSize(sf::Vector2f(size.x - BORDER_THICKNESS, BORDER_THICKNESS));
    horisontalLine.setFillColor(sf::Color::Red);
    target.draw(horisontalLine, states);
}