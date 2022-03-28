#pragma once
#include "Window.hpp"
#include "GameController.hpp"
#include "Direction.hpp"
#include "TemelTurler.hpp"

class Frame;

class Game
{
public:
	Game();
	~Game();
	void startGame(unsigned int width = 600, unsigned int height = 600);
	void drawingFunction(); // çizim fonk
	void bindEvent();  // olaylarý baðla
	void mouseMove(int x, int y); // fareHareket
	void keyboardPressed(sf::Keyboard::Key tus); // klavyeBasildi
	void setGame();
	void closeGame();

	

private:
	void saatiYenidenBaslat();
	std::shared_ptr<Frame> m_frame;
	dairePtr			m_circle; // m_daire
	bubblePtr			m_gameController;
	directionPtr		m_direction;
	sf::Time			m_cerceveSuresi;
	Window				m_window;
	sf::Clock			m_saat;
	int					m_fps;
	int					m_width;
	int					m_height;

};

