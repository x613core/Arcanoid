#include "Score.h"

Score::Score()
{
    score = 0;
}

void Score::increase(int additionsPoints)
{
    score += additionsPoints;
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    sf::Font font;
    std::filesystem::path p = __FILE__;
    if (font.openFromFile(p.parent_path().string() + "/" + FONT_FILE))
    {
        sf::Text text(font, "Score: " + std::to_string(score));
        target.draw(text, states);
    }
}
