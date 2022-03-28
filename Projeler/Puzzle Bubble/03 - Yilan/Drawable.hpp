#pragma once
#include<SFML/Graphics.hpp>
class Window;

class Drawable
{
public:
	virtual void draw(Window& window) = 0;

	sf::Vector2f m_pos; // m_konum
};
