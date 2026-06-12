#include "Arcanoid.h"

bool Arcanoid::isStarted()
{
    return _isStarted;
}

bool Arcanoid::gameOver()
{
    return _gameOver;
}

void Arcanoid::init()
{
    window.create(sf::VideoMode(sf::Vector2u(WINDOW_SIZE, WINDOW_SIZE)), "Arcanoid");
    window.setFramerateLimit(FPS_LIMIT);

    border = Border(sf::Vector2u(BORDER_SIZE_X, BORDER_SIZE_Y));
    platform = Platform(sf::Vector2u(PLATFORM_START_SIZE, PLATFORM_WIDTH),
                        sf::Vector2i(FIELD_POSITION.x + BORDER_THICKNESS,
                                     FIELD_POSITION.x + BORDER_SIZE_X));
    sceneCollider = FieldCollider(&border, &platform);
    sceneCollider.init();
    ball = Ball(BALL_START_RADIUS, BALL_START_SPEED, BALL_START_ANGLE, &sceneCollider);
    platform.setBall(&ball);
    score = Score();

    scene = std::list<GameObject *>{&score, &platform, &ball, &border, &sceneCollider};
    dynamicObjects = std::list<Uptadable *>{&platform, &ball};

    score.setPosition(sf::Vector2f(10, 10));
    border.setPosition(FIELD_POSITION);
    ball.setPosition(BALL_START_POSITION);
    platform.setPosition(PLATFORM_START_POSITION);

    _isStarted = 0;
    _gameOver = 0;
}

void Arcanoid::start()
{
    _isStarted = 1;
}

void Arcanoid::restart()
{
    window.close();
    init();
}

void Arcanoid::draw()
{
    window.clear(BACKGROUND_COLOR);
    for (const auto &object : scene)
        window.draw(*object);
}

void Arcanoid::update()
{
    if (_isStarted && !_gameOver)
    {
        platform.setNewPosition(sf::Mouse::getPosition(window));
        for (const auto &object : dynamicObjects)
            object->update();

        if (border.redZoneToched())
            _gameOver = 1;
        else if (platform.platformInBall())
        {
            ball.resetYPosition();
            ball.update();
        }
        if (sceneCollider.needToDecreaseSpeed())
        {
            ball.setSpeed(ball.getSpeed() / BALL_SPEED_CHANGE_KOEFF);
            sceneCollider.resetSpeedMarks();
        }
        else if (sceneCollider.needToIncreaseSpeed())
        {
            ball.setSpeed(ball.getSpeed() * BALL_SPEED_CHANGE_KOEFF);
            sceneCollider.resetSpeedMarks();
        }

        if (sceneCollider.getScore() != 0)
        {
            score.increase(sceneCollider.getScore());
            sceneCollider.resetScore();
        }
    }
}
