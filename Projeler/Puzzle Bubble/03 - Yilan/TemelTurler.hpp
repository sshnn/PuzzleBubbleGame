#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include<functional>

typedef std::function<void(int, int)> FareHareketFonksiyonu;
typedef std::function<void(sf::Keyboard::Key)>	KlavyeFonksiyonu;
typedef std::vector<FareHareketFonksiyonu> FareHareketFonkListesi;

typedef std::vector<KlavyeFonksiyonu>	KlavyeFonksiyonListesi;
enum class YON
{
	YON_SOL,
	YON_SAG,
	YON_YUKARI,
	YON_ASAGI
};

