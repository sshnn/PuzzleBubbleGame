#include "Direction.hpp"
#include "Window.hpp"



Direction::Direction(float size)
{
	m_size = size;
	m_pos = sf::Vector2f(270, 540);
	m_arrow.setPosition(sf::Vector2f(300, 575));
	m_arrow.setOrigin(sf::Vector2f(0.5, 100));
	m_degree = 90.f;
	
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

void Direction::chanceAngle(YON direction)
{
	m_direction = direction;
}


void Direction::setAngle()
{
	switch (m_direction)
	{
	case YON::YON_SOL:
		if (m_degree != 20)
		{
			m_degree -= 5.f;
			m_direction = YON::YON_YUKARI; // degrees(0)
			m_arrow.rotate(sf::degrees(-5.f));
			break;
		}
		
	case YON::YON_SAG:
		if (m_degree != 160 )
		{
			m_degree += 5.f;
			m_direction = YON::YON_YUKARI;
				m_arrow.rotate(sf::degrees(5.f));
				break;
		}
		

	case YON::YON_YUKARI:
		m_arrow.rotate(sf::degrees(0));
		break;
	
	}
	
	
}
