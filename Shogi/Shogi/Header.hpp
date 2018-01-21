#ifndef N1
#define N1
#include <iostream>

enum Gracz
{
	brak,
	gracz_1,
	gracz_2
};

enum Promocja
{
	bez_promocji,
	promowana
};

class Lista;
class Zapis;
class Pole;
class Figura;
class Krol;
class Wieza;
class Goniec;
class Lanca;
class Skoczek;
class Zloty_General;
class Srebrny_General;
class Pionek;

void wypisz(Lista L1, Lista L2);
bool wygrana(Krol K1, Krol K2);
Gracz zwroc_gracza(Pole *p);

#endif