#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 1300;

const float PLAT_SIZE_X = 100.0f;
const float PLAT_SIZE_Y = 10.0f;

const string PLAYER_TEXTURE = "pinky.png";
const string PLATFORM_TEXTURE = "images/bar.png"; 
const float PLAYER_SPEED = 300.0f;
const float PLAYER_JUMP_HEIGHT = 200.0f;
const float PLAYER_WIDTH = 50.0f;
const float PLAYER_HEIGHT = 100.0f;
const float PLAYER_START_X = 206.0f;
const float PLAYER_START_Y = 206.0f;


const float PLAT_WIDTH = 150.0f;
const float PLAT_HEIGHT = 150.0;