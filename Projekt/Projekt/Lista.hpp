#ifndef N13
#define N13
#include "Header.hpp"
#include <string>
#include <fstream>

class Zapis
{
public:
	std::string a;//nazwa figury
	std::string b;//pole (na)
	std::string c;//pole (z)
	Zapis * next = nullptr;
	Zapis(std::string x, std::string y, std::string z)
	{
		a = x;
		b = y;
		c = z;
	}
};

class Lista
{
public:
	Zapis * head = nullptr;

	void zapisz(std::string nazwa, int x2, int y2, int x, int y)
	{
		std::string pole = std::to_string(x);
		std::string pole2 = std::to_string(x2);
		if (y == 1)
		{
			pole.append("a");
		}
		else if (y == 2)
		{
			pole.append("b");
		}
		else if (y == 3)
		{
			pole.append("c");
		}
		else if (y == 4)
		{
			pole.append("d");
		}
		else if (y == 5)
		{
			pole.append("e");
		}
		else if (y == 6)
		{
			pole.append("f");
		}
		else if (y == 7)
		{
			pole.append("g");
		}
		else if (y == 8)
		{
			pole.append("h");
		}
		else
		{
			pole.append("i");
		}

		if (y2 == 1)
		{
			pole2.append("a");
		}
		else if (y2 == 2)
		{
			pole2.append("b");
		}
		else if (y2 == 3)
		{
			pole2.append("c");
		}
		else if (y2 == 4)
		{
			pole2.append("d");
		}
		else if (y2 == 5)
		{
			pole2.append("e");
		}
		else if (y2 == 6)
		{
			pole2.append("f");
		}
		else if (y2 == 7)
		{
			pole2.append("g");
		}
		else if (y2 == 8)
		{
			pole2.append("h");
		}
		else
		{
			pole2.append("i");
		}

		if (head == nullptr)
		{
			head = new Zapis(nazwa, pole, pole2);
		}
		else
		{
			Zapis * temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new Zapis(nazwa, pole, pole2);
		}
	}
};

void wypisz(Lista L1, Lista L2)
{
	Zapis * temp1 = L1.head;
	Zapis * temp2 = L2.head;
	std::fstream plik;
	plik.open("zapis_gry.txt", std::ios::out);
	if (plik.is_open() == true)
	{
		while (temp1 != nullptr)
		{
			plik << temp1->a << temp1->c<< " "<< temp1->b<<" ";
			if (temp2 != nullptr)
			{
				plik << temp2->a << temp2->c << " " << temp2->b << std::endl;
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}
}

#endif
