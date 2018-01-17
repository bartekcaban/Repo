#ifndef N5
#define N5
#include "Header.hpp"
#include "Figura.hpp"
#include "Pole.hpp"
#include <SFML/Graphics.hpp>


class Goniec : public Figura
{
public:
	Goniec(bool s, Gracz g, Promocja p, Pole *po)
	{
		gracz = g;
		promocja = p;
		pole = po;
		status = s;
		nazwa = "Goniec";

		obraz.loadFromFile("goniec.png");
		sprajt.setTexture(obraz);
	}

	bool Sprawdz_ruch(Pole *p, Pole * tab[]);
	void Ruch(Pole *p, Goniec *K);

	sf::Sprite wyswietl(sf::Vector2i v)
	{
		if (isMove == true)
		{
			sprajt.setPosition(v.x-30, v.y-30);
		}
		else if (status == true && isMove == false)
		{
			sprajt.setPosition(pole->_x, pole->_y);
		}
		else
		{
			if (gracz == gracz_2)
			{
				sprajt.setPosition(920, 125);
			}
			else
				sprajt.setPosition(920, 590);
		}
		if(promocja == bez_promocji)
		{
		obraz.loadFromFile("goniec.png");
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
		obraz.loadFromFile("goniec+.png");
		sprajt.setTexture(obraz);
	};
};
#endif