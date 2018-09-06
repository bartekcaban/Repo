#include <iostream>
#include <SFML\Graphics.hpp>
#include "Board.h"
#include "Menu.h"
#include "Player.h"
#include "Level.h"

using namespace std;

int main()
{
	Board board;//plansza
	Menu menu;
	Player player;//gracz
	Level level;//poziom
	sf::RenderWindow window(sf::VideoMode(1450, 800, 32), "Tower Defence");//okno programu
	window.setFramerateLimit(60);//ustawienie limitu klatek/s
	bool pause = false;//pauza
	bool tower_place_pause = false;//pauza s³u¿¹ca do wyœwietlania miejsc pod wie¿yczki
	bool win = false;//zwyciêstwo
	bool lose = false;//pora¿ka


	while (window.isOpen())//petla gry
	{
		sf::Event event;//zdarzenie w programie
		sf::Vector2i position = sf::Mouse::getPosition(window);//pozycja myszy
		
		while (window.pollEvent(event))//sprawdzenie, jakie zdarzenie nast¹pi³o
		{
			if (event.type == sf::Event::Closed)//zamkniecie okna
			{
				window.close();
			}
			if (pause == false && event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left && menu.pause_click(position))//pauza on
				pause = true;
			else if (pause == true && event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left && menu.pause_click(position) && !(win || lose))//pauza off
				pause = false;
			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left && menu.tower1_click(position))//klikniêcie tower1
			{
				board.change_tower_type(true);//true - tower1
				tower_place_pause = true;
			}
			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left && menu.tower2_click(position))//klikniêcie tower2
			{
				board.change_tower_type(false);//false - tower2
				tower_place_pause = true;
			}
			if (tower_place_pause && event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Right && !pause)//prawy klawisz myszy anuluje wybór miejsca dla wie¿y
				tower_place_pause = false;
			if (tower_place_pause && event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left && board.place_click(position))//stawianie wie¿y
			{
				level.add_tower(board.set_tower(position, &player));//utworzenie wie¿y
				tower_place_pause = false;
			}
		}
		
		if (!pause)
		{
			window.clear();//czyszczenie okna

			board.display(&window);//wyswietlenie planszy
			level.display_towers(&window);//wyswietlenie wie¿
			menu.display(&window);//wyswietlenie menu
			if (player.display(&window))//wyswietlenie ilosci pieniedzy i zdrowia
			{
				lose = true;
				pause = true;
			}
			level.display_monsters(&window, &player);//wyswietlanie potworow
			level.tower_firing();//strzelanie wie¿yczek
			if (level.generate_monsters())//generowanie potworów
			{
				win = true;
				pause = true;
			}
		}

		if (tower_place_pause)//wyswietlanie miejsc dla wie¿yczek
		{
			board.display_places(&window);
		}

		window.display();//wyswietlenie okna

		if (lose)
		{
			window.clear();
			board.display(&window);
			menu.display(&window);
			player.display(&window);
			Texture lose;
			try
			{
				lose.loadFromFile("lose.png");
			}
			catch(exception e)
			{
				e.what();
			}
			Sprite s_lose;
			s_lose.setTexture(lose);
			s_lose.setPosition(500, 350);
			window.draw(s_lose);
		}

		if (win)
		{
			window.clear();
			board.display(&window);
			menu.display(&window);
			player.display(&window);
			Texture win;
			try 
			{
				win.loadFromFile("win.png");
			}
			catch (exception e)
			{
				e.what();
			}
			Sprite s_win;
			s_win.setTexture(win);
			s_win.setPosition(500, 350);
			window.draw(s_win);
		}
	}
	return 0;
}