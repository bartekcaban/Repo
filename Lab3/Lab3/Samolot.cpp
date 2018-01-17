#include "Samolot.h"

Samolot::Samolot(float p = 1000, float d = 9000, int a = 1, int b = 1, int c = 1, float w = 2000, int m = 30000) : masa(m)
{
	paliwo = p;
	dystans = d;
	x = a;
	y = b;
	z = c;
	wysokosc = d;
}

void wypisz(Samolot s)
{
	cout << "Dystans samolotu to:" << s.dystans << "Pozostale paliwo:" << s.paliwo << endl;
}

Samolot zmien(Samolot s, float korekta)
{
	Samolot temp = s;
	temp.wysokosc = temp.wysokosc - korekta;
	return temp;
}