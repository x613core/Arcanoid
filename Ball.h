#pragma once
#include "game.h"

#ifdef GAME_OBJECT
#ifdef BORDER
class Ball : public GameObject, public Uptadable
{
private:
    int radius;
    double speed;
    double horisontalAngle; // in radians
    Border *border;

    double newAngleVerticalHit();
    double newAngleHorisontalHit();
    void setAngle(double angle);

public:
    Ball(int radius, int speed, double angleInRadians, Border *border);

    virtual void update() override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif
#endif