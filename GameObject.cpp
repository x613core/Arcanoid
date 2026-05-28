#include "GameObject.h"

GameObject::GameObject()
{
    tag = "NONE";
}

GameObject::GameObject(std::string tag)
{
    this->tag = tag;
}

void GameObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    sf::Font font;
    std::filesystem::path p = __FILE__;
    if (font.openFromFile(p.parent_path().string() + "/" + FONT_FILE))
    {
        sf::Text text(font, tag);
        target.draw(text, states);
    }
}