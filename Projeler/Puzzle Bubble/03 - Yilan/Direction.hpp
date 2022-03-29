#pragma once

#include "Drawable.hpp"
#include "TemelTurler.hpp"

class Direction : public Drawable
{
public:
	Direction(float size);

	// Inherited via Cizilebilir
	virtual void draw(Window& window) override;
	void chanceAngle(YON);
	void setAngle(); // rotate
	

	sf::RectangleShape m_arrow;
	
	float		m_size;
	float		m_degree;
	YON			m_direction;
	
};

typedef std::shared_ptr<Direction> directionPtr;
