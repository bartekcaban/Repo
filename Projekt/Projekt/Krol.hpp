#ifndef N4
#define N4
#include "Header.hpp"
#include "Figura.hpp"
#include "Pole.hpp"
#include <SFML/Graphics.hpp>



class Krol : public Figura
{
public:
	Krol(bool s, Gracz g, Promocja p, Pole *po)
	{
		gracz = g;
		promocja = p;
		pole = po;
		status = s;
		
		obraz.loadFromFile("krol.png");
		sprajt.setTexture(obraz);
	}

	bool Sprawdz_ruch(Pole *p);
	void Ruch(Pole *p, Krol *K);
	
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
			//przegrana
		}
		if (gracz == gracz_2)
		{
			sprajt.setOrigin(70, 70);
			sprajt.setRotation(180);
		}
		return sprajt;
	}
};
#endif