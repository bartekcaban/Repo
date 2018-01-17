#include <iostream>

using namespace std;

class Samolot :public Silnik
{
public:
	float paliwo;
	float dystans;
private:
	int x, y, z;
public:
	float wysokosc;
	const int masa;
	Silnik sil;

	Samolot(float p, float d, int a, int b, int c, float w, int m);
};

void wypisz(Samolot s);

Samolot zmien(Samolot s, float korekta);

class Silnik
{
public:
	bool stan;
	int szybkosc;
	int id;
};