#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "Updatable.h"
#include "ICollider.h"
#include "BoxCollider.h"
#include "GameObject.h"
#include "Border.h"
#include "Ball.h"
#include "Block.h"
#include "BorderBlock.h"
#include "HealthBlock.h"
#include "SpeedBlock.h"
#include "Platform.h"
#include "FieldCollider.h"
#include "Score.h"
#include "Arcanoid.h"

// font of all game messages
#define FONT_FILE "Samson.ttf"

// names of game objects
#define BORDER_TAG "border"
#define INCREASE_SPEED_BLOCK_TAG "increaseBlock"
#define DECREASE_SPEED_BLOCK_TAG "decreaseBlock"

constexpr sf::Color BACKGROUND_COLOR = sf::Color::Black;            // background color
constexpr sf::Color BASE_COLOR = sf::Color::White;                  // base color of bordeer, ball, player, ect.
constexpr sf::Color DEAD_COLOR = sf::Color::Red;                    // color of dead side of border
constexpr sf::Color BORDER_BLOCK_COLOR = sf::Color(125, 125, 125);  // color of border block
constexpr sf::Color INCREASE_SPEED_BLOCK_COLOR = sf::Color::Yellow; // color of speed up block
const sf::Color DECREASE_SPEED_BLOCK_COLOR = sf::Color::Blue;       // color of freaze block

constexpr int WINDOW_SIZE = 900;

constexpr int BORDER_THICKNESS = 10; // thickness of border lines
constexpr int BORDER_SIZE_X = 700;   // border width
constexpr int BORDER_SIZE_Y = 700;   // border height

constexpr int BALL_START_RADIUS = 10;           // start ball radius
constexpr int BALL_START_SPEED = 3;             // start ball speed
constexpr double BALL_START_ANGLE = 0.2 * M_PI; // start ball speed horisontal angle in radians

constexpr int PLATFORM_START_SIZE = 200; // start platform size
constexpr int PLATFORM_WIDTH = 15;       // start platform width

constexpr int BLOCK_SIZE = 30; // Block size

constexpr int SCORE_POINT_FOR_BLOCK = 50; // points for 1 block

constexpr double BALL_SPEED_CHANGE_KOEFF = 2; // speed will be multiplyed of devided by this

constexpr sf::Vector2f FIELD_POSITION(50, 50); // field position
// platform position
constexpr sf::Vector2f PLATFORM_START_POSITION(BORDER_SIZE_X / 2 + FIELD_POSITION.x -
                                                   PLATFORM_START_SIZE / 2,
                                               BORDER_SIZE_Y + FIELD_POSITION.y -
                                                   BORDER_THICKNESS - PLATFORM_WIDTH - 5);
// ball position
constexpr sf::Vector2f BALL_START_POSITION(PLATFORM_START_POSITION.x + PLATFORM_START_SIZE / 2 -
                                               BALL_START_RADIUS,
                                           PLATFORM_START_POSITION.y - 2 * BALL_START_RADIUS);

constexpr int FPS_LIMIT = 70;