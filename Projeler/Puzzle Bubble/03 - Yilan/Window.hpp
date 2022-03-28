#pragma once
#include<sfml/Graphics.hpp>
#include "TemelTurler.hpp"


class Window
{
public:
	Window(); // Pencere()
	void create(unsigned int w,		// olustur
		unsigned int h,
		sf::String title);
	void startDrawing(); // cizimeBasla
	void finish(); // finish
	bool isOpen(); // acýk mý
	void eventController();// olay control
	void draw(sf::Drawable& obj);//draw
	void addMoveFunc(FareHareketFonksiyonu yeniFonksiyon); // hareket fonk ekle

	void addKeyPressFunction(KlavyeFonksiyonu newFunc); //tusBasilmaFonksiyonuEkle
	void close(); //kapat


private:
	sf::RenderWindow m_window; // m_pencere
	KlavyeFonksiyonListesi	m_keyPressFunc;// m_tusBasmaFonkListesi
	FareHareketFonkListesi	m_mouseFunc; // m_fareHareketFonkListesi

};