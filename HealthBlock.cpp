#include "HealthBlock.h"

HealthBlock::HealthBlock(sf::Vector2u size, int health)
{
    this->size = size;
    this->health = (health > 0) ? health : 0;
    currentPosition = getPosition();
    tag = "";
}

int HealthBlock::Destroy()
{
    if (health == 0)
        _isDestroyed = 1;
    else
        health--;

    return 0;
}

void HealthBlock::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    sf::RectangleShape block(sf::Vector2f(size.x, size.y));
    block.setFillColor(BASE_COLOR);
    target.draw(block, states);

    sf::Font font;
    std::filesystem::path p = __FILE__;
    if (font.openFromFile(p.parent_path().string() + "/" + FONT_FILE))
    {
        sf::Text text(font, std::to_string(health));
        text.setFillColor(BACKGROUND_COLOR);
        states.transform.translate(sf::Vector2f(7, -7));
        target.draw(text, states);
    }
}
