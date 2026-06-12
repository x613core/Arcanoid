#include "SpeedBlock.h"

SpeedBlock::SpeedBlock(sf::Vector2u size, SpeedMode mode)
{
    this->size = size;
    this->mode = mode;
    currentPosition = getPosition();
    if (mode == SpeedMode::increase)
        this->tag = INCREASE_SPEED_BLOCK_TAG;
    else if (mode == SpeedMode::decrease)
        this->tag = DECREASE_SPEED_BLOCK_TAG;
    else
        this->tag = "None";
}

int SpeedBlock::Destroy()
{
    _isDestroyed = 1;
    if (mode == SpeedMode::decrease)
        return (int)SpeedMode::decrease;
    else if (mode == SpeedMode::increase)
        return (int)SpeedMode::increase;

    return 0;
}

void SpeedBlock::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    sf::RectangleShape block(sf::Vector2f(size.x, size.y));
    if (mode == SpeedMode::increase)
        block.setFillColor(INCREASE_SPEED_BLOCK_COLOR);
    else if (mode == SpeedMode::decrease)
        block.setFillColor(DECREASE_SPEED_BLOCK_COLOR);
    target.draw(block, states);
}
