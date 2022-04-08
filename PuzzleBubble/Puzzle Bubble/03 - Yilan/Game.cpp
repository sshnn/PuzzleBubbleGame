#include "Game.hpp"
#include <iostream>
#include "Frame.hpp"
#include "Circle.hpp"
  


Game::Game() : m_fps{60}
{
	m_frameTimer = sf::seconds(1.0f / m_fps);
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
	for (const auto& pos : m_gameController->m_posVec ) {
		if (pos.y > 400 || m_gameController->m_isFinish) {
			closeGame();
			printScore();
		}
	}
}

void Game::printScore()
{
	if(m_gameController->m_isFinish)
		std::cout <<"CONGRATULATIONS...\n" << "SCORE: " << m_score.getElapsedTime().asSeconds() << "\n";
	else
		std::cout << "GAME OVER!!!\n" << "SCORE: " << m_score.getElapsedTime().asSeconds() << "\n";
}

void Game::startGame(unsigned int width, unsigned int height)
{
	m_width = width;
	m_height = height;
	m_window.create(width, height, "Puzzle Bubble");

	setGame();

	m_ftime.restart(); 
	while (m_window.isOpen())
	{
		m_window.eventController();

		if (m_ftime.getElapsedTime() >= m_frameTimer)
		{
			drawingFunction();
			m_ftime.restart();
		}
		else
		{
			sf::sleep(m_frameTimer - m_ftime.getElapsedTime());
		}

	}
}

void Game::drawingFunction()
{
	m_window.startDrawing();



	m_frame->draw(m_window);
	
	m_direction->draw(m_window);
	m_direction->setAngle();

	m_gameController->draw(m_window);
	m_gameController->throwCircle(m_direction->m_degree);
	m_gameController->set_degree(m_direction->m_degree);

	align();
	m_window.finish();
	endGame();
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
	
}

void Game::keyboardPressed(sf::Keyboard::Key key)
{

	if (key == sf::Keyboard::Right)
	{
		m_direction->chanceAngle(DIRECTION::DIRECTION_RIGHT);
		
	}
	if (key == sf::Keyboard::Left)
	{
		m_direction->chanceAngle(DIRECTION::DIRECTION_LEFT);
		
	}
	if (key == sf::Keyboard::Up)
	{
		
		m_direction->chanceAngle(DIRECTION::DIRECTION_UP);
	}
	if (key == sf::Keyboard::Space )
	{
		
		m_gameController->m_circles.back()->m_isBumb = false;
		m_gameController->m_degree = 0;
		
	}
	if (key == sf::Keyboard::Enter)
	{
		/*Frame::m_limit_y += 50;
		m_gameController->lowPos(50);*/

		
	}

}



Game::~Game()
{
}

