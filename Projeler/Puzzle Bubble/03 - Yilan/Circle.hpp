#pragma once
#include "TemelTurler.hpp"
#include "Drawable.hpp"


class Direction;

class Circle : public Drawable
{
public:
	Circle(const float r);
	static std::shared_ptr<Circle> makeCircle(float radius);
	void throwCircle(float f);
	sf::Color randColor();
	virtual void draw(Window& pencere) override;

	
	float		m_r; // radius
	float		m_speed;
	bool		m_isBumb; // çarpma



	
	//YON							m_yon;
	sf::CircleShape				m_shape;
	//std::shared_ptr<Direction>	m_directPtr;
	sf::Color m_color;
};
typedef std::shared_ptr<Circle>	dairePtr;
typedef std::vector<dairePtr>	daireListesi;