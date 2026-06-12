#pragma once
#include "game.h"
#define GAME_OBJECT

class GameObject : public sf::Drawable, public sf::Transformable
{
public:
    GameObject();
    GameObject(std::string tag);

    std::string tag;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
