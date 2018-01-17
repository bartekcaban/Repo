#include "Zespolona.h"

int Zespolona::licznik = 0;

void Zespolona::set() 
{
	cout << "Podaj realis:" << endl;
	cin >> Re;
	cout << "Podaj imaginaris" << endl;
	cin >> Im;
};

void Zespolona::get() 
{
	cout << Re <<" + "<< Im<<"i" << endl;
};

Zespolona::~Zespolona()
{
	licznik--;
	cout << "Wywolany zostal destruktor" << endl;
}

Zespolona::Zespolona(const Zespolona &zespolona)
{
	Re = zespolona.Re;
	Im = zespolona.Im;
	licznik++;
	cout << "Wywolany zostal konstruktor wieloargumentowy" << endl;
}

Zespolona::Zespolona(float r, float i)
{
	Re = r;
	Im = i;
	licznik ++ ;
	cout << "Wywolany zostal konstruktor kopiujacy" << endl;
}

Zespolona::Zespolona(float r)
{
	Re = r;
	Im = 0;
	licznik++;
	cout << "Wywolany zostal konstruktor jednoargumentowy" << endl;
}

Zespolona::Zespolona()
{
	licznik++;
	cout << "Wywolany zostal konstruktor bezargumentowy" << endl;
}