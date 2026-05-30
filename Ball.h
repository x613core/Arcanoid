#pragma once
#include "game.h"
#define BALL

#ifdef GAME_OBJECT
#ifdef BORDER
class Ball : public GameObject, public Uptadable
{
private:
    bool _isDeleted;

    int radius;
    double speed;
    double horisontalAngle; // in radians
    ICollider *collider;

    double newAngleVerticalHit();
    double newAngleHorisontalHit();
    void setAngle(double angle);

public:
    Ball(int radius, int speed, double angleInRadians, ICollider *collider);

    bool isDeleted();
    virtual void update() override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif
#endif