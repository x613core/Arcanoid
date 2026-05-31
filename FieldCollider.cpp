#include "FieldCollider.h"

FieldCollider::FieldCollider(Border *border, Platform *platform)
{
    this->border = border;
    this->platform = platform;
    score = 0;
    _needToDecreaseSpeed = 0;
    _needToIncreaseSpeed = 0;
}

void FieldCollider::init()
{
    block = Block(sf::Vector2u(BLOCK_SIZE, BLOCK_SIZE));
    block.setPosition(sf::Vector2f(130, 100));
    block.updatePosition();
    borderBlock = BorderBlock(sf::Vector2u(BLOCK_SIZE, BLOCK_SIZE));
    borderBlock.setPosition(sf::Vector2f(160, 100));
    borderBlock.updatePosition();
    healthBlock = HealthBlock(sf::Vector2u(BLOCK_SIZE, BLOCK_SIZE), 4);
    healthBlock.setPosition(sf::Vector2f(100, 100));
    healthBlock.updatePosition();
    freazeBlock = SpeedBlock(sf::Vector2u(BLOCK_SIZE, BLOCK_SIZE), SpeedMode::decrease);
    freazeBlock.setPosition(sf::Vector2f(130, 130));
    freazeBlock.updatePosition();
    speedBlock = SpeedBlock(sf::Vector2u(BLOCK_SIZE, BLOCK_SIZE), SpeedMode::increase);
    speedBlock.setPosition(sf::Vector2f(100, 130));
    speedBlock.updatePosition();
    blocks = std::list<Block *>{&block, &borderBlock, &healthBlock, &freazeBlock, &speedBlock};
}

int FieldCollider::getScore()
{
    return score;
}

void FieldCollider::resetScore()
{
    score = 0;
}

bool FieldCollider::needToIncreaseSpeed()
{
    return _needToIncreaseSpeed;
}

bool FieldCollider::needToDecreaseSpeed()
{
    return _needToDecreaseSpeed;
}

void FieldCollider::resetSpeedMarks()
{
    _needToDecreaseSpeed = 0;
    _needToIncreaseSpeed = 0;
}

sf::Vector2f FieldCollider::ballCollisionCoverDepth(sf::Vector2f position, int radius)
{
    sf::Vector2f result = border->ballCollisionCoverDepth(position, radius);
    if (result != sf::Vector2f(0, 0))
        return result;
    for (const auto &object : blocks)
    {
        result = object->ballCollisionCoverDepth(position, radius);
        if (result != sf::Vector2f(0, 0))
        {
            int res = object->Destroy();
            if (object->isDestryed())
            {
                blocks.remove(object);
                score += SCORE_POINT_FOR_BLOCK;
            }

            if (res == (int)SpeedMode::increase)
                _needToIncreaseSpeed = true;
            else if (res == (int)SpeedMode::decrease)
                _needToDecreaseSpeed = true;

            return result;
        }
    }

    return platform->ballCollisionCoverDepth(position, radius);
}

void FieldCollider::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const auto &object : blocks)
        target.draw(*object, states);
}
