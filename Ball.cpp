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

Ball::Ball(int radius, int speed, double angleInRadians, Border *border)
{
    this->radius = radius;
    this->speed = speed;
    this->border = border;
    setAngle(angleInRadians);
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    sf::CircleShape ball(radius);
    ball.setFillColor(BASE_COLOR);
    target.draw(ball, states);
}

void Ball::update()
{
    this->move(sf::Vector2f(speed * cos(horisontalAngle), -speed * sin(horisontalAngle)));
    double startSpeed = speed;

    sf::Vector2f collisionEnter = (*border).ballCollisionCoverDepth(getPosition(), radius);
    if (collisionEnter != sf::Vector2f(0, 0))
    {
        double speedX = collisionEnter.x / std::abs(cos(horisontalAngle));
        double speedY = collisionEnter.y / std::abs(sin(horisontalAngle));
        speed = std::max(speedX, speedY);
        this->move(sf::Vector2f(-speed * cos(horisontalAngle),
                                speed * sin(horisontalAngle)));

        if (speedX > speedY)
            setAngle(newAngleVerticalHit());
        else if (speedY > speedX)
            setAngle(newAngleHorisontalHit());
        else
            setAngle(M_PI + horisontalAngle);
    }
    speed = startSpeed;
}