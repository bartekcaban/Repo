#ifndef N12
#define N12
#include "Header.hpp"
#include "Pole.hpp"
#include "Krol.hpp"
#include "Goniec.hpp"
#include "Wieza.hpp"
#include "Skoczek.hpp"
#include "Lanca.hpp"
#include "Zloty_General.hpp"
#include "Srebrny_General.hpp"
#include "Pionek.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Gracz zwroc_gracza(Pole *p)
{
	if (p->status == "Pionek")
		return p->p->gracz;
	if (p->status == "Wieza")
		return p->w->gracz;
	if (p->status == "Krol")
		return p->k->gracz;
	if (p->status == "Goniec")
		return p->g->gracz;
	if (p->status == "Skoczek")
		return p->s->gracz;
	if (p->status == "Lanca")
		return p->l->gracz;
	if (p->status == "Srebrny_General")
		return p->sg->gracz;
	if (p->status == "Zloty_General")
		return p->zg->gracz;
	return brak;
}


bool Krol::Sprawdz_ruch(Pole * p)
{
	if (zwroc_gracza(p) == this->gracz)
		return false;
	if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y + 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y -1) || (p->x == pole->x + 1 && p->y == pole->y -1))
		return true;
	else
		return false;
}
void Krol::Ruch(Pole *p, Krol *K)
{
	pole->k = nullptr;
	pole->status = "brak";
	pole = p;
	if (pole->status == "brak")
		pole->setFigura(K);
	else
	{
		if (pole->status == "Krol")
		{
			pole->k->usun();//wygrana
		}
		else if (pole->status == "Pionek")
		{
			pole->p->usun();
			pole->p = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Skoczek")
		{
			pole->s->usun();
			pole->s = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Lanca")
		{
			pole->l->usun();
			pole->l = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Goniec")
		{
			pole->g->usun();
			pole->g = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Wieza")
		{
			pole->w->usun();
			pole->w = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Srebrny_General")
		{
			pole->sg->usun();
			pole->sg = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Zloty_General")
		{
			pole->zg->usun();
			pole->zg = nullptr;
			pole->setFigura(K);
		}
	}
}
bool Goniec::Sprawdz_ruch(Pole * p, Pole * tab[])
{
	if (zwroc_gracza(p) == this->gracz)
		return false;
	if (promocja == promowana)
	{
		if ((p->x == pole->x - 1 && p->y == pole->y) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x && p->y == pole->y - 1))
			return true;

		for (int j = 0; j < 81; j++)
		{
			for (int i = 1; i < 10; i++)
			{
				if (((tab[j]->x == pole->x + i && tab[j]->y == pole->y + i && tab[j]->status != "brak" && tab[j]->x < p->x && tab[j]->y < p->y) || (tab[j]->x == pole->x - i && tab[j]->y == pole->y - i && tab[j]->status != "brak" && tab[j]->x > p->x && tab[j]->y > p->y) || (tab[j]->x == pole->x - i && tab[j]->y == pole->y + i && tab[j]->status != "brak" && tab[j]->x > p->x && tab[j]->y < p->y) || (tab[j]->x == pole->x + i && tab[j]->y == pole->y - i && tab[j]->status != "brak" && tab[j]->x < p->x && tab[j]->y > p->y)))
				{
					return false;
				}
			}
		}

		int i = 1;
		while (i <= 9)
		{	
			if ((p->x == pole->x + i && p->y == pole->y + i) || (p->x == pole->x - i && p->y == pole->y - i) || (p->x == pole->x - i && p->y == pole->y + i) || (p->x == pole->x + i && p->y == pole->y - i))
				return true;
			i++;
		}
		return false;
	}
	else
	{
		for (int j = 0; j < 81; j++)
		{
			for (int i = 1; i < 10; i++)
			{
				if (((tab[j]->x == pole->x + i && tab[j]->y == pole->y + i && tab[j]->status != "brak" && tab[j]->x < p->x && tab[j]->y < p->y) || (tab[j]->x == pole->x - i && tab[j]->y == pole->y - i && tab[j]->status != "brak" && tab[j]->x > p->x && tab[j]->y > p->y) || (tab[j]->x == pole->x - i && tab[j]->y == pole->y + i && tab[j]->status != "brak" && tab[j]->x > p->x && tab[j]->y < p->y) || (tab[j]->x == pole->x + i && tab[j]->y == pole->y - i && tab[j]->status != "brak" && tab[j]->x < p->x && tab[j]->y > p->y)))
				{
					return false;
				}
			}
		}

		int i = 1;
		while (i <= 9)
		{
			if ((p->x == pole->x + i && p->y == pole->y + i) || (p->x == pole->x - i && p->y == pole->y - i) || (p->x == pole->x - i && p->y == pole->y + i) || (p->x == pole->x + i && p->y == pole->y - i))
				return true;
			i++;
		}
		return false;
	}
}
void Goniec::Ruch(Pole *p, Goniec *K)
{
	pole->g = nullptr;
	pole->status = "brak";
	pole = p;
	if (pole->status == "brak")
		pole->setFigura(K);
	else
	{
		if (pole->status == "Krol")
		{
			pole->k->usun();//wygrana
		}
		else if (pole->status == "Pionek")
		{
			pole->p->usun();
			pole->p = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Skoczek")
		{
			pole->s->usun();
			pole->s = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Lanca")
		{
			pole->l->usun();
			pole->l = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Goniec")
		{
			pole->g->usun();
			pole->g = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Wieza")
		{
			pole->w->usun();
			pole->w = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Srebrny_General")
		{
			pole->sg->usun();
			pole->sg = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Zloty_General")
		{
			pole->zg->usun();
			pole->zg = nullptr;
			pole->setFigura(K);
		}
	}

	if (gracz == gracz_2)
	{
		if (pole->y >= 7)
			Promoj();
	}
	else
	{
		if (pole->y <= 3)
			Promoj();
	}
}
bool Pionek::Sprawdz_ruch(Pole * p)
{
	if (zwroc_gracza(p) == this->gracz)
		return false;
	if (this->gracz == gracz_2)
	{
		if (promocja == bez_promocji)
		{
			if (p->x == pole->x && p->y == pole->y + 1)
				return true;
			else
				return false;
		}
		else
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y + 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
				return true;
			else
				return false;
		}
	}
	else
	{
		if (promocja == bez_promocji)
		{
			if (p->x == pole->x && p->y == pole->y - 1)
				return true;
			else
				return false;
		}
		else
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y - 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
				return true;
			else
				return false;
		}
	}
	
}
void Pionek::Ruch(Pole *p, Pionek *K)
{
	pole->p = nullptr;
	pole->status = "brak";
	pole = p;
	
	if (pole->status == "brak")
	{
		pole->setFigura(K);
	}
	else
	{
		if (pole->status == "Krol")
		{
			pole->k->usun();//wygrana
		}
		else if (pole->status == "Pionek")
		{
			pole->p->usun();
			pole->p = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Skoczek")
		{
			pole->s->usun();
			pole->s = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Lanca")
		{
			pole->l->usun();
			pole->l = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Goniec")
		{
			pole->g->usun();
			pole->g = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Wieza")
		{
			pole->w->usun();
			pole->w = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Srebrny_General")
		{
			pole->sg->usun();
			pole->sg = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Zloty_General")
		{
			pole->zg->usun();
			pole->zg = nullptr;
			pole->setFigura(K);
		}
	}

	if (gracz == gracz_2)
	{
		if (pole->y >= 7)
			Promoj();
	}
	else
	{
		if (pole->y <= 3)
			Promoj();
	}
}
bool Wieza::Sprawdz_ruch(Pole * p, Pole * tab[])
{
	if (zwroc_gracza(p) == this->gracz)
		return false;
	
	if (promocja == bez_promocji)
	{
		if (p->x > pole->x)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->x > pole->x && tab[i]->x < p->x && tab[i]->y == pole->y && tab[i]->status != "brak")
					return false;
			}
		}
		else if (p->x < pole->x)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->x < pole->x && tab[i]->x > p->x && tab[i]->y == pole->y && tab[i]->status != "brak")
					return false;
			}
		}
		else if (p->y > pole->y)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->y > pole->y && tab[i]->y < p->y && tab[i]->x == pole->x && tab[i]->status != "brak")
					return false;
			}
		}
		else if (p->y < pole->y)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->y < pole->y && tab[i]->y > p->y && tab[i]->x == pole->x && tab[i]->status != "brak")
					return false;
			}
		}

		if(p->y == pole->y || p->x == pole->x)
			return true;
		else
			return false;
	}
	else
	{
		if ( (p->x == pole->x +1 && p->y == pole->y +1) || (p->x == pole->x - 1 && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y - 1) || (p->x == pole->x - 1 && p->y == pole->y - 1))
			return true;
		if (p->x > pole->x)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->x > pole->x && tab[i]->x < p->x && tab[i]->y == pole->y && tab[i]->status != "brak")
					return false;
			}
		}
		else if (p->x < pole->x)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->x < pole->x && tab[i]->x > p->x && tab[i]->y == pole->y && tab[i]->status != "brak")
					return false;
			}
		}
		else if (p->y > pole->y)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->y > pole->y && tab[i]->y < p->y && tab[i]->x == pole->x && tab[i]->status != "brak")
					return false;
			}
		}
		else if (p->y < pole->y)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->y < pole->y && tab[i]->y > p->y && tab[i]->x == pole->x && tab[i]->status != "brak")
					return false;
			}
		}
		if (p->y == pole->y || p->x == pole->x)
			return true;
		else
			return false;
	}
}
void Wieza::Ruch(Pole *p, Wieza *K)
{
	pole->w = nullptr;
	pole->status = "brak";
	pole = p;
	if (pole->status == "brak")
		pole->setFigura(K);
	else
	{
		if (pole->status == "Krol")
		{
			pole->k->usun();//wygrana
		}
		else if (pole->status == "Pionek")
		{
			pole->p->usun();
			pole->p = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Skoczek")
		{
			pole->s->usun();
			pole->s = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Lanca")
		{
			pole->l->usun();
			pole->l = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Goniec")
		{
			pole->g->usun();
			pole->g = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Wieza")
		{
			pole->w->usun();
			pole->w = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Srebrny_General")
		{
			pole->sg->usun();
			pole->sg = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Zloty_General")
		{
			pole->zg->usun();
			pole->zg = nullptr;
			pole->setFigura(K);
		}
	}

	if (gracz == gracz_2)
	{
		if (pole->y >= 7)
			Promoj();
	}
	else
	{
		if (pole->y <= 3)
			Promoj();
	}
}
bool Lanca::Sprawdz_ruch(Pole * p, Pole * tab[])
{
	if (zwroc_gracza(p) == this->gracz)
		return false;
	if (gracz == gracz_2)
	{
		if (promocja == bez_promocji)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->y < p->y && tab[i]->y > pole->y && tab[i]->x==pole->x && tab[i]->status != "brak")
				{
					return false;
				}
			}
			if (p->x == pole->x && p->y > pole->y)
				return true;
			else
				return false;
		}
		else
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y + 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
				return true;
			else
				return false;
		}
	}
	else
	{
		if (promocja == bez_promocji)
		{
			for (int i = 0; i < 81; i++)
			{
				if (tab[i]->y > p->y && tab[i]->y < pole->y && tab[i]->x == pole->x && tab[i]->status != "brak")
					return false;
			}
			if (p->x == pole->x && p->y < pole->y)
				return true;
			else
				return false;
		}
		else
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y - 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
				return true;
			else
				return false;
		}
	}
}
void Lanca::Ruch(Pole *p, Lanca *K)
{
	pole->l = nullptr;
	pole->status = "brak";
	pole = p;
	if (pole->status == "brak")
		pole->setFigura(K);
	else
	{
		if (pole->status == "Krol")
		{
			pole->k->usun();//wygrana
		}
		else if (pole->status == "Pionek")
		{
			pole->p->usun();
			pole->p = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Skoczek")
		{
			pole->s->usun();
			pole->s = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Lanca")
		{
			pole->l->usun();
			pole->l = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Goniec")
		{
			pole->g->usun();
			pole->g = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Wieza")
		{
			pole->w->usun();
			pole->w = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Srebrny_General")
		{
			pole->sg->usun();
			pole->sg = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Zloty_General")
		{
			pole->zg->usun();
			pole->zg = nullptr;
			pole->setFigura(K);
		}
	}

	if (gracz == gracz_2)
	{
		if (pole->y >= 7)
			Promoj();
	}
	else
	{
		if (pole->y <= 3)
			Promoj();
	}
}
bool Skoczek::Sprawdz_ruch(Pole * p)
{
	if (zwroc_gracza(p) == this->gracz)
		return false;
	if (gracz == gracz_2)
	{
		if (promocja == bez_promocji)
		{
			if ((p->x == pole->x + 1 && p->y == pole->y + 2) || (p->x == pole->x - 1 && p->y == pole->y + 2))
				return true;
			else
				return false;
		}
		else
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y + 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
				return true;
			else
				return false;
		}
	}
	else
	{
		if (promocja == bez_promocji)
		{
			if ((p->x == pole->x + 1 && p->y == pole->y - 2) || (p->x == pole->x - 1 && p->y == pole->y - 2))
				return true;
			else
				return false;
		}
		else
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y - 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
				return true;
			else
				return false;
		}
	}
}
void Skoczek::Ruch(Pole *p, Skoczek *K)
{
	pole->s = nullptr;
	pole->status = "brak";
	pole = p;
	if (pole->status == "brak")
		pole->setFigura(K);
	else
	{
		if (pole->status == "Krol")
		{
			pole->k->usun();//wygrana
		}
		else if (pole->status == "Pionek")
		{
			pole->p->usun();
			pole->p = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Skoczek")
		{
			pole->s->usun();
			pole->s = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Lanca")
		{
			pole->l->usun();
			pole->l = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Goniec")
		{
			pole->g->usun();
			pole->g = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Wieza")
		{
			pole->w->usun();
			pole->w = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Srebrny_General")
		{
			pole->sg->usun();
			pole->sg = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Zloty_General")
		{
			pole->zg->usun();
			pole->zg = nullptr;
			pole->setFigura(K);
		}
	}

	if (gracz == gracz_2)
	{
		if (pole->y >= 7)
			Promoj();
	}
	else
	{
		if (pole->y <= 3)
			Promoj();
	}
}
bool Srebrny_General::Sprawdz_ruch(Pole * p)
{
	if (zwroc_gracza(p) == this->gracz)
		return false;
	if (gracz == gracz_2)
	{
		if (promocja == bez_promocji)
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y - 1) || (p->x == pole->x - 1 && p->y == pole->y - 1))
				return true;
			else
				return false;
		}
		else
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y + 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
				return true;
			else
				return false;
		}
	}
	else
	{
		if (promocja == bez_promocji)
		{
			if ((p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y - 1) || (p->x == pole->x - 1 && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y + 1))
				return true;
			else
				return false;
		}
		else
		{
			if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y - 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
				return true;
			else
				return false;
		}
	}
}
void Srebrny_General::Ruch(Pole *p, Srebrny_General *K)
{
	pole->sg = nullptr;
	pole->status = "brak";
	pole = p;
	if (pole->status == "brak")
		pole->setFigura(K);
	else
	{
		if (pole->status == "Krol")
		{
			pole->k->usun();//wygrana
		}
		else if (pole->status == "Pionek")
		{
			pole->p->usun();
			pole->p = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Skoczek")
		{
			pole->s->usun();
			pole->s = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Lanca")
		{
			pole->l->usun();
			pole->l = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Goniec")
		{
			pole->g->usun();
			pole->g = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Wieza")
		{
			pole->w->usun();
			pole->w = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Srebrny_General")
		{
			pole->sg->usun();
			pole->sg = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Zloty_General")
		{
			pole->zg->usun();
			pole->zg = nullptr;
			pole->setFigura(K);
		}
	}
	if (gracz == gracz_2)
	{
		if (pole->y >= 7)
			Promoj();
	}
	else
	{
		if (pole->y <= 3)
			Promoj();
	}
}
bool Zloty_General::Sprawdz_ruch(Pole * p)
{
	if (zwroc_gracza(p) == this->gracz)
		return false;
	if (gracz == gracz_2)
	{
		if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x + 1 && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y + 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
			return true;
		else
			return false;
	}
	else
	{
		if ((p->x == pole->x && p->y == pole->y + 1) || (p->x == pole->x - 1 && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y - 1) || (p->x == pole->x && p->y == pole->y - 1) || (p->x == pole->x + 1 && p->y == pole->y) || (p->x == pole->x - 1 && p->y == pole->y))
			return true;
		else
			return false;
	}
}
void Zloty_General::Ruch(Pole *p, Zloty_General *K)
{
	pole->zg = nullptr;
	pole->status = "brak";
	pole = p;
	if (pole->status == "brak")
		pole->setFigura(K);
	else
	{
		if (pole->status == "Krol")
		{
			pole->k->usun();//wygrana
		}
		else if (pole->status == "Pionek")
		{
			pole->p->usun();
			pole->p = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Skoczek")
		{
			pole->s->usun();
			pole->s = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Lanca")
		{
			pole->l->usun();
			pole->l = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Goniec")
		{
			pole->g->usun();
			pole->g = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Wieza")
		{
			pole->w->usun();
			pole->w = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Srebrny_General")
		{
			pole->sg->usun();
			pole->sg = nullptr;
			pole->setFigura(K);
		}
		else if (pole->status == "Zloty_General")
		{
			pole->zg->usun();
			pole->zg = nullptr;
			pole->setFigura(K);
		}
	}
}


#endif