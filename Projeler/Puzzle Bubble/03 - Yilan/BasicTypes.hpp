#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include<functional>

typedef std::function<void(int, int)> mouseMoveFunctions;
typedef std::vector<mouseMoveFunctions> mouseMoveFuncList;

typedef std::function<void(sf::Keyboard::Key)>	keyboardFunc;
typedef std::vector<keyboardFunc>	keyboardFuncList;
enum class DIRECTION
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
};

