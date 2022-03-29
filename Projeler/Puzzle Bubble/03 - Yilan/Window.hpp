#pragma once
#include<sfml/Graphics.hpp>
#include "TemelTurler.hpp"


class Window
{
public:
	Window(); 
	void create(unsigned int w,		
		unsigned int h,
		sf::String title);
	void startDrawing(); 
	void finish(); 
	bool isOpen(); 
	void eventController();
	void draw(sf::Drawable& obj);
	void addMoveFunc(FareHareketFonksiyonu yeniFonksiyon); 

	void addKeyPressFunction(KlavyeFonksiyonu newFunc); 
	void close(); 


private:
	sf::RenderWindow m_window; 
	KlavyeFonksiyonListesi	m_keyPressFunc;
	FareHareketFonkListesi	m_mouseFunc; 

};