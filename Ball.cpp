#include "Ball.h"

double Ball::newAngleVerticalHit()
{
    if (horisontalAngle > M_PI)
        return 3 * M_PI - horisontalAngle;
    else
        return M_PI - horisontalAngle;
}

double Ball::newAngleHorisontalHit()
{
    return 2 * M_PI - horisontalAngle;
}

void Ball::setAngle(double angle)
{
    while (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    while (angle < 0)
        angle += 2 * M_PI;
    horisontalAngle = angle;
}

double Ball::getSpeed()
{
    return speed;
}

void Ball::setSpeed(double speed)
{
    this->speed = (speed > 0) ? speed : 0;
}

Ball::Ball(int radius, int speed, double angleInRadians, ICollider *collider)
{
    _isDeleted = 0;
    this->radius = radius;
    this->speed = speed;
    this->collider = collider;
    setAngle(angleInRadians);
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    sf::CircleShape ball(radius);
    ball.setFillColor(BASE_COLOR);
    target.draw(ball, states);
}

bool Ball::isDeleted()
{
    return _isDeleted;
}

int Ball::getRadius()
{
    return radius;
}

void Ball::resetYPosition()
{
    sf::Vector2f newPos = getPosition();
    newPos.y = BALL_START_POSITION.y;
    setPosition(newPos);
}

void Ball::update()
{
    this->move(sf::Vector2f(speed * cos(horisontalAngle), -speed * sin(horisontalAngle)));
    double startSpeed = speed;

    sf::Vector2f collisionEnter = (*collider).ballCollisionCoverDepth(getPosition(), radius);

    if (collisionEnter != sf::Vector2f(0, 0))
    {
        double speedX = collisionEnter.x / std::abs(cos(horisontalAngle));
        double speedY = collisionEnter.y / std::abs(sin(horisontalAngle));
        speed = std::max(speedX, speedY);

        if (speedX > speedY)
            setAngle(newAngleVerticalHit());
        else if (speedY > speedX)
            setAngle(newAngleHorisontalHit());
        else
            setAngle(M_PI + horisontalAngle);
    }
    speed = startSpeed;
}