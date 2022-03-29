#include "Window.hpp"

Window::Window()
{
	
	
}

void Window::create(unsigned int genislik, unsigned int yukseklik, sf::String baslik)
{
	m_window.create(sf::VideoMode(genislik, yukseklik), baslik);
	
}

void Window::startDrawing()
{
	m_window.clear();
}

void Window::finish()
{
	m_window.display();
}

bool Window::isOpen()
{
	return m_window.isOpen();
}

#include <iostream> // test
void Window::eventController()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

		if (event.type == sf::Event::KeyPressed )
		{
			for (auto next : m_keyPressFunc)
				next(event.key.code);
				
		}
		
		

		//if (event.type == sf::Event::MouseMoved) // test
		//{
		//	std::cout << event.mouseMove.x
		//		<< ", " << event.mouseMove.y
		//		<< "\n";

		//}
	}
}

void Window::draw(sf::Drawable& sekil)
{
	m_window.draw(sekil);

}

void Window::addMoveFunc(FareHareketFonksiyonu yeniFonksiyon)
{
	m_mouseFunc.push_back(yeniFonksiyon);
}

void Window::addKeyPressFunction(KlavyeFonksiyonu yeniFonk)
{
	m_keyPressFunc.push_back(yeniFonk);
	

}

void Window::close()
{
	m_window.close();
}
