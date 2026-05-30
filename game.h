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
#include "Platform.h"
#include "FieldCollider.h"

// font of all game messages
#define FONT_FILE "Samson.ttf"

// names of game objects
#define BORDER_TAG "border"

const sf::Color BACKGROUND_COLOR = sf::Color::Black; // background color
const sf::Color BASE_COLOR = sf::Color::White;       // base color of bordeer, ball, player, ect.
const sf::Color DEAD_COLOR = sf::Color::Red;         // color of dead side of border

const int BORDER_THICKNESS = 10; // thickness of border lines
const int BORDER_SIZE_X = 700;   // border width
const int BORDER_SIZE_Y = 700;   // border height

const int BALL_START_RADIUS = 10;           // start ball radius
const int BALL_START_SPEED = 3;             // start ball speed
const double BALL_START_ANGLE = 0.2 * M_PI; // start ball speed horisontal angle in radians

const int PLATFORM_START_SIZE = 200; // start platform size
const int PLATFORM_WIDTH = 15;       // start platform width

const sf::Vector2f FIELD_POSITION(50, 50); // field position
// platform position
const sf::Vector2f PLATFORM_START_POSITION(BORDER_SIZE_X / 2 + FIELD_POSITION.x -
                                               PLATFORM_START_SIZE / 2,
                                           BORDER_SIZE_Y + FIELD_POSITION.y -
                                               BORDER_THICKNESS - PLATFORM_WIDTH - 5);
// ball position
const sf::Vector2f BALL_START_POSITION(PLATFORM_START_POSITION.x + PLATFORM_START_SIZE / 2 -
                                           BALL_START_RADIUS,
                                       PLATFORM_START_POSITION.y - 2 * BALL_START_RADIUS);

const int FPS_LIMIT = 70;