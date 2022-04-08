#pragma once
#include "Window.hpp"
#include "GameController.hpp"
#include "Direction.hpp"


class Frame;

class Game
{
public:
	Game();
	~Game();
	void startGame(unsigned int width = 600, unsigned int height = 600);
	void drawingFunction(); 
	void bindEvent();  
	void mouseMove(int x, int y); 
	void keyboardPressed(sf::Keyboard::Key tus); 
	void setGame();
	void closeGame();
	void align(); // süreye baðlý oyunu daraltýr
	void endGame();
	void printScore();

private:

	std::shared_ptr<Frame> m_frame;
	circlePtr			m_circle; 
	bubblePtr			m_gameController;
	directionPtr		m_direction;
	sf::Time			m_frameTimer;
	sf::Clock			m_score;
	sf::Clock			m_timer;
	Window				m_window;
	sf::Clock			m_ftime;
	int					m_fps;
	int					m_width;
	int					m_height;

};

