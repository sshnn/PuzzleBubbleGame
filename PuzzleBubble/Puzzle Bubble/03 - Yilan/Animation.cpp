#include "Animation.hpp"


Animation::Animation()
{
	blue.loadFromFile("puzzle.png", sf::IntRect(sf::Vector2i(1, 624), sf::Vector2i(31, 31)));
	red.loadFromFile("puzzle.png", sf::IntRect(sf::Vector2i(1, 721), sf::Vector2i(31, 31)));
	yellow.loadFromFile("puzzle.png", sf::IntRect(sf::Vector2i(1, 818), sf::Vector2i(31, 31)));
	purple.loadFromFile("puzzle.png", sf::IntRect(sf::Vector2i(1, 915), sf::Vector2i(31, 31)));
}
