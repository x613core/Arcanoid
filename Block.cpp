#include "Block.h"

Block::Block(sf::Vector2u size)
{
    currentPosition = getPosition();
    this->size = size;
    _isDestroyed = 0;
    tag = "";
}

bool Block::isDestryed()
{
    return _isDestroyed;
}

int Block::Destroy()
{
    _isDestroyed = 1;
    return 0;
}

void Block::updatePosition()
{
    currentPosition = getPosition();
}

void Block::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    sf::RectangleShape block(sf::Vector2f(size.x, size.y));
    block.setFillColor(BASE_COLOR);
    target.draw(block, states);
}
