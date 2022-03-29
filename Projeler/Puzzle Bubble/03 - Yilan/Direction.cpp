#include "Direction.hpp"
#include "Window.hpp"



Direction::Direction(float size) : m_size{size}, m_degree{90.f}
{
	
	m_pos = sf::Vector2f(270, 540);
	m_arrow.setPosition(sf::Vector2f(300, 575));
	m_arrow.setOrigin(sf::Vector2f(0.5, 100));

	
	//m_arrow.rotate(sf::degrees(m_derece));

	m_arrow.setSize(sf::Vector2f(1, size));
	m_arrow.setOutlineThickness(2);
	m_arrow.setOutlineColor(sf::Color::White);
	m_arrow.setFillColor(sf::Color::Black);


}


void Direction::draw(Window& window)
{
	window.draw(m_arrow);
}

void Direction::chanceAngle(DIRECTION direction)
{
	m_direction = direction;
}


void Direction::setAngle()
{
	switch (m_direction)
	{
	case DIRECTION::DIRECTION_LEFT:
		if (m_degree != 35)
		{
			m_degree -= 5.f;
			m_direction = DIRECTION::DIRECTION_UP; // degrees(0)
			m_arrow.rotate(sf::degrees(-5.f));
			break;
		}
		
	case DIRECTION::DIRECTION_RIGHT:
		if (m_degree != 145 )
		{
			m_degree += 5.f;
			m_direction = DIRECTION::DIRECTION_UP;
				m_arrow.rotate(sf::degrees(5.f));
				break;
		}
		

	case DIRECTION::DIRECTION_UP:
		m_arrow.rotate(sf::degrees(0));
		break;
	
	}
	
	
}

