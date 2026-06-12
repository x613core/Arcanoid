#pragma once
#include "game.h"

#ifdef BORDER
#ifdef PLATFORM
#ifdef GAME_OBJECT
#ifdef BLOCK
#ifdef BORDER_BLOCK
#ifdef HEALTH_BLOCK
#ifdef SPEED_BLOCK
#define FIELD_COLLIDER
class FieldCollider : public ICollider, public GameObject
{
private:
    Border *border;
    Platform *platform;
    std::list<Block *> blocks;
    Block block;
    BorderBlock borderBlock;
    HealthBlock healthBlock;
    SpeedBlock freazeBlock;
    SpeedBlock speedBlock;

    int score;
    bool _needToIncreaseSpeed;
    bool _needToDecreaseSpeed;

public:
    FieldCollider() {};
    FieldCollider(Border *border, Platform *platform);

    void init();
    int getScore();
    void resetScore();
    bool needToIncreaseSpeed();
    bool needToDecreaseSpeed();
    void resetSpeedMarks();

    virtual sf::Vector2f
    ballCollisionCoverDepth(sf::Vector2f position, int radius) override;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif
#endif
#endif
#endif
#endif
#endif
#endif