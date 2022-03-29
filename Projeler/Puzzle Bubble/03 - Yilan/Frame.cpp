#include "Frame.hpp"
#include "Window.hpp"
Frame::Frame() 
{
	m_verticalLimit.setFillColor(sf::Color::Blue);
	m_horizontalLimit.setFillColor(sf::Color::Blue);
	
}
int Frame::m_limit_y{};

void Frame::set(float size)
{
	m_horizontalLimit.setSize(sf::Vector2f(size, 4));
	m_verticalLimit.setSize(sf::Vector2f(4, size));
}
void Frame::draw(Window& window)
{
	sf::Vector2f siradakiKonum;
	siradakiKonum.y = m_limit_y;

	m_horizontalLimit.setPosition(siradakiKonum);
	window.draw(m_horizontalLimit);

	for (int i = 0; i < 2; ++i)
	{
		siradakiKonum.x = m_pos.x + i * 596;
		m_verticalLimit.setPosition(siradakiKonum);
		window.draw(m_verticalLimit);

	}
}
