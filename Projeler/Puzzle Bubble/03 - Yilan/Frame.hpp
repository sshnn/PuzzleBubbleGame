#pragma once

#include "Drawable.hpp"
#include<SFML/Graphics.hpp>
class Frame : public Drawable
{
public:
	Frame();

	void set(float size);


	// Inherited via Cizilebilir
	virtual void draw(Window& pencere) override;



	sf::RectangleShape m_horizontalLimit;
	sf::RectangleShape m_verticalLimit;
	float	m_distance;
	static int	m_limit_y;
};
