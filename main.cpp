#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(900, 900)), "Arcanoid");
    window.setFramerateLimit(FPS_LIMIT);

    std::list<GameObject *> scene;
    std::list<Uptadable *> dynamicObjects;
    Border border(sf::Vector2u(BORDER_SIZE_X, BORDER_SIZE_Y));
    Platform platform(sf::Vector2u(PLATFORM_START_SIZE, PLATFORM_WIDTH),
                      sf::Vector2i(FIELD_POSITION.x + BORDER_THICKNESS,
                                   FIELD_POSITION.x + BORDER_SIZE_X));
    FieldCollider collider(&border, &platform);
    Ball ball(BALL_START_RADIUS, BALL_START_SPEED, BALL_START_ANGLE, &collider);

    GameObject score("score");
    scene.push_back(&score);
    scene.push_back(&border);
    scene.push_back(&ball);
    scene.push_back(&platform);
    dynamicObjects.push_back(&ball);
    dynamicObjects.push_back(&platform);

    score.setPosition(sf::Vector2f(10, 10));
    border.setPosition(FIELD_POSITION);
    ball.setPosition(BALL_START_POSITION);
    platform.setPosition(PLATFORM_START_POSITION);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(BACKGROUND_COLOR);
        for (const auto &object : scene)
            window.draw(*object);
        window.display();
        platform.setNewPosition(sf::Mouse::getPosition(window));
        for (const auto &object : dynamicObjects)
            object->update();
        if (ball.isDeleted())
        {
            scene.remove(&ball);
            dynamicObjects.remove(&ball);
        }
    }
    return 0;
}
