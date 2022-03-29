#pragma once
#include<sfml/Graphics.hpp>
#include "BasicTypes.hpp"


class Window
{
public:
	Window() = default; 
	void create(unsigned int w,		
		unsigned int h,
		sf::String title);
	void startDrawing(); 
	void finish(); 
	bool isOpen(); 
	void eventController();
	void draw(sf::Drawable& obj);
	void addMoveFunc(mouseMoveFunctions yeniFonksiyon);

	void addKeyPressFunction(keyboardFunc newFunc);
	void close(); 


private:
	sf::RenderWindow m_window; 
	keyboardFuncList	m_keyPressFunc;
	mouseMoveFuncList  	m_mouseFunc;

};