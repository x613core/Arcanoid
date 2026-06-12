#include "game.h"

int main()
{
    Arcanoid arcanoid;
    arcanoid.init();

    while (arcanoid.window.isOpen())
    {
        while (const auto event = arcanoid.window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                arcanoid.window.close();
            else if (event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (!arcanoid.isStarted())
                    arcanoid.start();
                else if (arcanoid.gameOver())
                    arcanoid.restart();
            }
        }

        arcanoid.update();
        arcanoid.draw();
        arcanoid.window.display();
    }
    return 0;
}
