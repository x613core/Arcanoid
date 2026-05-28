#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(900, 900)), "Arcanoid");
    std::vector<std::unique_ptr<GameObject>> scene;

    scene.push_back(std::make_unique<GameObject>("player"));
    scene.push_back(std::make_unique<Border>(sf::Vector2u(700, 700)));
    scene.push_back(std::make_unique<GameObject>("score"));
    (*scene[0]).setPosition(sf::Vector2f(450, 600));
    (*scene[2]).setPosition(sf::Vector2f(10, 10));
    (*scene[1]).setPosition(sf::Vector2f(50, 50));

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        for (const auto &object : scene)
            window.draw(*object);
        window.display();
    }
    return 0;
}
