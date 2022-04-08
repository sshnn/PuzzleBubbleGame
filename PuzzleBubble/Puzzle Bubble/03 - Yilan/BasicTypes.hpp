#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include<functional>

using mouseMoveFunctions = std::function<void(int, int)>;
using mouseMoveFuncList = std::vector<mouseMoveFunctions>;

using keyboardFunc = std::function<void(sf::Keyboard::Key)>;
using keyboardFuncList = std::vector<keyboardFunc>;
enum class DIRECTION
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
};

