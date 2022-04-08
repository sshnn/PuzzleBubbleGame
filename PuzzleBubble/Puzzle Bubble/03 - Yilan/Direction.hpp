#pragma once

#include "Drawable.hpp"
#include "BasicTypes.hpp"

class Direction : public Drawable
{
public:
	Direction(float size);
	virtual void draw(Window& window) override;
	void chanceAngle(DIRECTION);
	void setAngle(); // rotate
	

	sf::RectangleShape	m_arrow;
	float				m_size;
	float				m_degree;
	DIRECTION			m_direction;
	
};

using directionPtr = std::shared_ptr<Direction>;
