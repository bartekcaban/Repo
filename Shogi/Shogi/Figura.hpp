#ifndef N3
#define N3
#include "Header.hpp"
#include <SFML/Graphics.hpp>

class Figura
{
public:
	bool status; // 0 - poza polem, 1 - w polu
	Promocja promocja;
	sf::Texture obraz;
	sf::Sprite sprajt;
	bool isMove = false;//true, jesli figura jest w ruchu
	Gracz gracz;
	std::string nazwa;
	Pole *pole; // pole, na ktorym znajduje sie figura, nullptr jesli poza polem
	void UstawPole(Pole *p) { pole = p; }
	void usun()
	{
		if (gracz == gracz_1)
		{
			gracz = gracz_2;
			promocja = bez_promocji;
			status = false;
		}
		else
		{
			gracz = gracz_1;
			promocja = bez_promocji;
			status = false;
		}
	}
};

#endif