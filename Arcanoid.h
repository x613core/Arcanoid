#pragma once
#include "game.h"

#ifdef GAME_OBJECT
#ifdef PLATFORM
#ifdef BALL
#ifdef BORDER
#ifdef FIELD_COLLIDER
#ifdef SCORE
class Arcanoid
{
private:
    std::list<GameObject *> scene;
    std::list<Uptadable *> dynamicObjects;

    Platform platform;
    Ball ball;
    Border border;
    Score score;
    FieldCollider sceneCollider;

    bool _isStarted;
    bool _gameOver;

public:
    sf::RenderWindow window;

    Arcanoid() {};

    bool isStarted();
    bool gameOver();

    void init();
    void start();
    void restart();
    void draw();
    void update();
};
#endif
#endif
#endif
#endif
#endif
#endif