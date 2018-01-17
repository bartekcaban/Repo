#ifndef N11
#define N11
#include "Header.hpp"
#include "Figura.hpp"
#include "Pole.hpp"
#include <SFML/Graphics.hpp>


class Pionek : public Figura
{
public:
	Pionek(bool s, Gracz g, Promocja p, Pole *po)
	{
		gracz = g;
		promocja = p;
		pole = po;
		status = s;
		nazwa = "Pionek";

		obraz.loadFromFile("pionek.png");
		sprajt.setTexture(obraz);
	}

	bool Sprawdz_ruch(Pole *p);
	void Ruch(Pole *p, Pionek *K);

	sf::Sprite wyswietl(sf::Vector2i v)
	{
		if (isMove == true)
		{
			sprajt.setPosition(v.x - 30, v.y - 30);
		}
		else if (status == true && isMove == false)
		{
			sprajt.setPosition(pole->_x, pole->_y);
		}
		else
		{
			if (gracz == gracz_2)
			{
				sprajt.setPosition(800, 45);
			}
			else
				sprajt.setPosition(800, 690);
		}

		if (promocja == bez_promocji)
		{
			obraz.loadFromFile("pionek.png");
			sprajt.setTexture(obraz);
		}
	
		if (gracz == gracz_2)
		{
			sprajt.setOrigin(70, 70);
			sprajt.setRotation(180);
		}
		else
		{
			sprajt.setOrigin(0, 0);
			sprajt.setRotation(0);
		}
		return sprajt;
	}
	void Promoj()
	{
		promocja = promowana;
		obraz.loadFromFile("pionek+.png");
		sprajt.setTexture(obraz);
	};
};
#endif