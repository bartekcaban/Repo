#include <iostream>
#include <SFML\Graphics.hpp>
#include "Board.h"
using namespace sf;

Board::Board()
{
	try 
	{
		texture.loadFromFile("Board/board.png");
		route_texture.loadFromFile("Board/route.png");
	}
	catch (std::exception e)
	{
		e.what();
	}
	sprite.setTexture(texture);
	route_sprite.setTexture(route_texture);
	tower_type = tower1;
	for (int i = 0; i < 25; i++)
	{
		occupied_places[i] = true;//1 - wolne, 0 - zajête
	}
	//miejsca na wie¿e
	try
	{
		place_texture.loadFromFile("board/place.png");
	}
	catch (std::exception e)
	{
		e.what();
	}
	place[0].setTexture(place_texture);
	place[0].setPosition(10,190);
	place[1].setTexture(place_texture);
	place[1].setPosition(100, 190);
	place[2].setTexture(place_texture);
	place[2].setPosition(50, 380);
	place[3].setTexture(place_texture);
	place[3].setPosition(50, 500);
	place[4].setTexture(place_texture);
	place[4].setPosition(220, 320);
	place[5].setTexture(place_texture);
	place[5].setPosition(220, 440);
	place[6].setTexture(place_texture);
	place[6].setPosition(310, 320);
	place[7].setTexture(place_texture);
	place[7].setPosition(310, 440);
	place[8].setTexture(place_texture);
	place[8].setPosition(310, 190);
	place[9].setTexture(place_texture);
	place[9].setPosition(480, 250);
	place[10].setTexture(place_texture);
	place[10].setPosition(570, 250);
	place[11].setTexture(place_texture);
	place[11].setPosition(660, 250);
	place[12].setTexture(place_texture);
	place[12].setPosition(750, 250);
	place[13].setTexture(place_texture);
	place[13].setPosition(840, 250);
	place[14].setTexture(place_texture);
	place[14].setPosition(930, 250);
	place[15].setTexture(place_texture);
	place[15].setPosition(1020, 250);
	place[16].setTexture(place_texture);
	place[16].setPosition(1250, 250);
	place[17].setTexture(place_texture);
	place[17].setPosition(1250, 370);
	place[18].setTexture(place_texture);
	place[18].setPosition(480, 370);
	place[19].setTexture(place_texture);
	place[19].setPosition(480, 490);
	place[20].setTexture(place_texture);
	place[20].setPosition(480, 610);
	place[21].setTexture(place_texture);
	place[21].setPosition(720, 520);
	place[22].setTexture(place_texture);
	place[22].setPosition(810, 520);
	place[23].setTexture(place_texture);
	place[23].setPosition(900, 520);
	place[24].setTexture(place_texture);
	place[24].setPosition(990, 520);
}

void Board::display(RenderWindow * window)
{
	window->draw(sprite);
	window->draw(route_sprite);
}

void Board::display_places(RenderWindow * window)
{
	//rysowanie wolnych miejsc
	for (int i = 0; i < 25; i++)
	{
		if (occupied_places[i] != 0)
			window->draw(place[i]);
	}
}

bool Board::place_click(Vector2i pos)
{
	//sprawdzenie, czy mysz jest nad miejscem pod wierze
	for (int i = 0; i < 25; i++)
	{
		if (place[i].getGlobalBounds().contains(pos.x, pos.y))
			return true;
	}
	return false;
}

Tower* Board::set_tower(Vector2i pos, Player * player)
{
	Tower * pointer = nullptr;
	//szukamy miejsca, które zosta³o wskazane
	for (int i = 0; i < 25; i++)
	{
		if (place[i].getGlobalBounds().contains(pos.x, pos.y))
		{
			//tworzymy tam now¹ wie¿ê o zadanym typie
			if (tower_type == tower1)
			{
				if (player -> subtract_coins(100))
				{
					pointer = new Tower1(place[i].getPosition());
					occupied_places[i] = false;//miejsce oznaczamy jako zajête
				}
			}
			else
			{
				if (player -> subtract_coins(200))
				{
					pointer = new Tower2(place[i].getPosition());
					occupied_places[i] = false;//miejsce oznaczamy jako zajête
				}
			}
			

			break;
		}
	}
	return pointer;//zwracamy wskaŸnik na nowy obiekt
}

void Board::change_tower_type(bool type)
{
	//zapis, któr¹ wie¿e nale¿y stworzyæ
	if (type)
		tower_type = tower1;
	else
		tower_type = tower2;
}