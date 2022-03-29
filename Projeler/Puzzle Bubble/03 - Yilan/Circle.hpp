#pragma once
#include "BasicTypes.hpp"
#include "Drawable.hpp"



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


	sf::CircleShape				m_shape;
	sf::Color m_color;
};
typedef std::shared_ptr<Circle>	circlePtr;
typedef std::vector<circlePtr>	circleList;