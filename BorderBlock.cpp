#include "BorderBlock.h"

BorderBlock::BorderBlock(sf::Vector2u size)
{
    this->size = size;
    currentPosition = getPosition();
    tag = "";
}

int BorderBlock::Destroy()
{
    return 0;
}

void BorderBlock::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    sf::RectangleShape block(sf::Vector2f(size.x, size.y));
    block.setFillColor(BORDER_BLOCK_COLOR);
    target.draw(block, states);
}
