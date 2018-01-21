#ifndef N2
#define N2
#include <iostream>
#include "Figura.hpp"
#include "Header.hpp"
#include "SFML/Graphics.hpp"

class Pole
{
public:
	//wskazniki na figury:
	Pionek *p = nullptr;
	Lanca *l = nullptr;
	Skoczek *s = nullptr;
	Srebrny_General *sg = nullptr;
	Zloty_General *zg = nullptr;
	Goniec *g = nullptr;
	Wieza *w = nullptr;
	Krol *k = nullptr;
	std::string status;//nazwa figury, jaka znajduje sie na polu
	int x, y;//wspolrzedne
	float _x, _y;//wspolrzene pola w oknie
	Pole(int a, int b, std::string s, Pionek *_p, Skoczek *_s, Lanca *_l, Srebrny_General *_sg, Zloty_General *_zg, Goniec *_g, Wieza *_w, Krol *_k, float c, float d)
	{
		x = b;
		y = a;
		_x = c;
		_y = d;
		status = s;
		if (status == "Pionek")//przypisanie polu figury
			setFigura(_p);
		else if (status == "Lanca")
			setFigura(_l);
		else if (status == "Skoczek")
			setFigura(_s);
		else if (status == "Srebrny_General")
			setFigura(_sg);
		else if (status == "Zloty_General")
			setFigura(_zg);
		else if (status == "Goniec")
			setFigura(_g);
		else if (status == "Wieza")
			setFigura(_w);
		else if (status == "Krol")
			setFigura(_k);
	}

	void setFigura(Pionek *_p)
	{
		p = _p;
		status = "Pionek";
	}
	void setFigura(Skoczek *_s)
	{
		s = _s;
		status = "Skoczek";
	}
	void setFigura(Lanca *_l)
	{
		l = _l;
		status = "Lanca";
	}
	void setFigura(Srebrny_General *_sg)
	{
		sg = _sg;
		status = "Srebrny_General";
	}
	void setFigura(Zloty_General *_zg)
	{
		zg = _zg;
		status = "Zloty_General";
	}
	void setFigura(Goniec *_g)
	{
		g = _g;
		status = "Goniec";
	}
	void setFigura(Wieza *_w)
	{
		w = _w;
		status = "Wieza";
	}
	void setFigura(Krol *_k)
	{
		k = _k;
		status = "Krol";
	}
};

#endif