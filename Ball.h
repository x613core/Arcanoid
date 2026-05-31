#pragma once
#include "game.h"

#ifdef GAME_OBJECT
#ifdef BORDER
#define BALL
class Ball : public GameObject, public Uptadable
{
private:
    bool _isDeleted;

    int radius;
    double speed;
    double horisontalAngle; // in radians
    ICollider *collider;

public:
    Ball() {};
    Ball(int radius, int speed, double angleInRadians, ICollider *collider);

    bool isDeleted();
    int getRadius();
    void resetYPosition();
    double newAngleVerticalHit();
    double newAngleHorisontalHit();
    void setAngle(double angle);
    double getSpeed();
    void setSpeed(double speed);

    virtual void update() override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif
#endif