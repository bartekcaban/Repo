#pragma once
#include <iostream>
#include <sstream>
#include <SFML\Graphics.hpp>

class Player
{
	int hp;//punkty �ycia
	int coins;//ilo�� pieni�dzy
	sf::Text hp_text;
	sf::Text coins_text;
	sf::Font font;
	
public:
	Player();
	void add_coins(int c);//dodawanie monet
	bool subtract_coins(int c);//odejmowanie monet
	bool decrease_hp(int h);//odejmowanie hp
	bool display(sf::RenderWindow * window);//wyswietlanie ilo�ci monet i �ycia
};