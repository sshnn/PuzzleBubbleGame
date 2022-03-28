#include "Circle.hpp"
#include "Window.hpp"
#include "Direction.hpp"
#include "Frame.hpp"


Circle::Circle(const float r)
{
	m_pos = sf::Vector2f(270, 540);
    m_r = r;
	m_speed = r / 2;
	m_shape.setRadius(r);
	m_isBumb = true;
    m_shape.setFillColor(randColor());
	m_shape.setOutlineThickness(2);
	m_shape.setOutlineColor(sf::Color::White);
	
}

std::shared_ptr<Circle> Circle::makeCircle(float r)
{
	return std::make_shared<Circle>(r);
}



#include <cmath>
#include <iostream>
#define PI 3.14159265
void Circle::throwCircle(float angle)
{	
	m_pos.x -= cos(angle * PI / 180.0) * m_speed;
	m_pos.y -= sin(angle * PI / 180.0) * m_speed;
}

sf::Color Circle::randColor()
{	
	srand(time(nullptr));
	sf::Color color[4] { sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Green };
	m_color = color[rand() % 4];
	return m_color;
}



void Circle::draw(Window& window)
{
    m_shape.setPosition(m_pos);
	window.draw(m_shape);
}


