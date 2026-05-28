#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

#include "GameObject.h"
#include "Border.h"

// font of all game messages
#define FONT_FILE "Samson.ttf"

// names of game objects
#define BORDER_TAG "border"

const sf::Color DEAD_COLOR = sf::Color::Red; // color of dead side of border

const int BORDER_THICKNESS = 10; // thickness of border lines