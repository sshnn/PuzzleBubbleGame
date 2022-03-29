#include "Game.hpp"
#include <iostream>
#include "Frame.hpp"
#include "Circle.hpp"
#include "Direction.hpp"




Game::Game()
{
	m_fps = 60;
	m_cerceveSuresi = sf::seconds(1.0f / m_fps);
	


}

Game::~Game()
{
}


void Game::setGame()
{
	m_frame = std::make_shared<Frame>();
	m_frame->set(m_width);

	
	m_direction = std::make_shared<Direction>(100.f);
	m_circle = Circle::makeCircle(30.f);
	m_gameController = std::make_shared<GameController>(30.0f);

	bindEvent();

	

}

void Game::closeGame()
{
	m_window.close();
}

void Game::align()
{
	if (m_timer.getElapsedTime().asSeconds() > 20.f) {
		Frame::m_limit_y += 50;
		m_gameController->lowPos(50);
		m_timer.restart();
	}
}

void Game::endGame()
{
	
}

void Game::startGame(unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;
	m_window.create(width, height, "oyun");

	setGame();

	saatiYenidenBaslat();
	while (m_window.isOpen())
	{
		m_window.eventController();

		if (m_saat.getElapsedTime() >= m_cerceveSuresi)
		{
			drawingFunction();
			saatiYenidenBaslat();
		}
		else
		{
			sf::sleep(m_cerceveSuresi - m_saat.getElapsedTime());
		}

	}
}

void Game::drawingFunction()
{
	m_window.startDrawing();


	//std::cout << m_direction->m_derece << "\n";
	m_frame->draw(m_window);
	
	m_direction->draw(m_window);
	m_direction->setAngle();

	m_gameController->draw(m_window);
	m_gameController->throwCircle(m_direction->m_degree);
	m_gameController->set_degree(m_direction->m_degree);
	
	//std::cout << m_timer.getElapsedTime().asSeconds() << "\n"; // test
	align();
	m_window.finish();
}

void Game::bindEvent()
{
	m_window.addMoveFunc(
		std::bind(&Game::mouseMove, this, std::placeholders::_1, std::placeholders::_2));

	
	m_window.addKeyPressFunction(
		std::bind(&Game::keyboardPressed, this, std::placeholders::_1));
}

void Game::mouseMove(int x, int y)
{
	/*for (auto siradaki : m_panelListesi)
	{
		if (siradaki->icerdemi(x, y))
			siradaki->fareHareket(x, y);

	}*/


}

void Game::keyboardPressed(sf::Keyboard::Key key)
{

	if (key == sf::Keyboard::Right)
	{
		m_direction->chanceAngle(YON::YON_SAG);
		
	}
	if (key == sf::Keyboard::Left)
	{
		m_direction->chanceAngle(YON::YON_SOL);
		
	}
	if (key == sf::Keyboard::Up)
	{
		
		m_direction->chanceAngle(YON::YON_YUKARI);
	}
	if (key == sf::Keyboard::Space )
	{
		
		m_gameController->m_circles.back()->m_isBumb = false;
		m_gameController->m_degree = 0;
		
	}
	if (key == sf::Keyboard::Enter)
	{
		Frame::m_limit_y += 50;
		m_gameController->lowPos(50);
		//m_bubble->randomCircles();
		//m_bubble->addCircle();
		
	}

}




void Game::saatiYenidenBaslat()
{
	m_saat.restart();
}
