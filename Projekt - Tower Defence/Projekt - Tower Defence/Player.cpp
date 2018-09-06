#include "Player.h"
#include <iostream>
#include <sstream>
#include <SFML\Graphics.hpp>
using namespace std;

Player::Player()
{
	coins = 200;
	hp = 100;
	//zamiana int na string poprzez wywo³anie tych funkcji
	add_coins(0);
	decrease_hp(0);
	//za³adowanie czcionki
	try 
	{
		font.loadFromFile("Board/Arial.ttf");
	}
	catch (exception e)
	{
		e.what();
	}
	//ustawienie pozycji i charakterystyki tekstu
	hp_text.setPosition(1385, 760);
	hp_text.setCharacterSize(20);
	hp_text.setFillColor(sf::Color::Cyan);
	hp_text.setOutlineColor(sf::Color::Cyan);
	hp_text.setStyle(sf::Text::Regular);
	hp_text.setFont(font);
	coins_text.setPosition(1385, 660);
	coins_text.setCharacterSize(20);
	coins_text.setFillColor(sf::Color::Cyan);
	coins_text.setOutlineColor(sf::Color::Cyan);
	coins_text.setStyle(sf::Text::Regular);
	coins_text.setFont(font);
}

void Player::add_coins(int c)
{
	coins = coins + c;
	//zamiana int na string
	ostringstream ss;
	ss << coins;
	string str = ss.str();
	//zapis stringa do tekstu do wyswielenia
	coins_text.setString(str);
}

bool Player::subtract_coins(int c)
{
	if (coins >= c)
	{
		coins = coins - c;
		//zamiana int na string
		ostringstream ss;
		ss << coins;
		string str = ss.str();
		//zapis stringa do tekstu do wyswielenia
		coins_text.setString(str);
		return true;
	}
	else
		return false;
}

bool Player::decrease_hp(int h)
{
	hp = hp - h;
	//zamiana int na string
	ostringstream ss;
	ss << hp;
	string str = ss.str();
	//zapis stringa do tekstu do wyswielenia
	hp_text.setString(str);

	return true;
}

bool Player::display(sf::RenderWindow * window)
{
	window -> draw(hp_text);
	window -> draw(coins_text);
	if (hp == 0)
		return true;
	else;
		return false;
}