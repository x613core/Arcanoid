#pragma once
#include "game.h"

#ifdef GAME_OBJECT
#define SCORE
class Score : public GameObject
{
private:
    int score;

public:
    Score();

    void increase(int additionsPoints);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif