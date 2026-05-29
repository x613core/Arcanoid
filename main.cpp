#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(900, 900)), "Arcanoid");
    window.setFramerateLimit(FPS_LIMIT);

    std::vector<GameObject *> scene;
    Border border(sf::Vector2u(700, 700));
    Ball ball(10, 3, 0.25 * M_PI, &border);
    GameObject score("score");
    scene.push_back(&ball);
    scene.push_back(&border);
    scene.push_back(&score);
    ball.setPosition(sf::Vector2f(450, 600));
    score.setPosition(sf::Vector2f(10, 10));
    border.setPosition(sf::Vector2f(50, 50));

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
        ball.update();
    }
    return 0;
}
