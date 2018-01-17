#include "Header.h"
#include <fstream>

bool Telefon_kom::sprawdz()
{
	if (numer.length() != 9)
	{
		cout << "Bledny numer telefonu komorkowego" << endl;
		return false;
	}
	return true;
}
bool Telefon_sta::sprawdz()
{
	if (numer.length() != 9)
	{
		cout << "Bledny numer telefonu stacjonarnego" << endl;
		return false;
	}
	return true;
}

bool Kwota::sprawdz()
{
	if (kwota[0] == '-')
	{
		cout << "Podano bledna kwote" << endl;
		return false;
	}
	return true;
}
bool Email::sprawdz()
{
	int m = 0;
	int n = 0;
	for (int i = 0; i < email.length(); i++)
	{
		if (email[i] == '@')
			m++;
		if (email[i] == '.')
			n++;
	}
	if (!(m == 1 & n >= 1))
	{
		cout << "Podano zly email" << endl;
		return false;
	}
	return true;
}

bool Liczba_rzymska::sprawdz()
{
	for (int i = 0; i < liczba.length(); i++)
	{
		if (liczba[i] != 'X' || liczba[i] != 'V' || liczba[i] != 'I' || liczba[i] != 'M' || liczba[i] != 'D' || liczba[i] != 'C' || liczba[i] != 'L')
		{
			cout << "To nie jest liczba rzymska" << endl;
			return false;
		}
		return true;
	}
}

bool Walidator::sprawdzenie(Telefon_kom * nk, Telefon_sta * ns, Kwota * k, Email * e, Liczba_rzymska * l)
{
	if (sprawdz(nk ->numer) == 1 && sprawdz(ns -> numer) == 1 && sprawdz(k ->kwota) == 1 && sprawdz(e -> email) == 1 && sprawdz(l -> liczba) == 1)
	{
		cout << "Dane sa poprawne" << endl;
		return true;
	}
	else
	{
		cout << "Dane sa bledne" << endl;
		return false;
	}
}
//____________________________________________________________________

bool Forma_platnosci::nalicz_oplate(string w, float k)
{
	if (w != waluta)
	{
		cout << "Niezgodna waluta" << endl;
		return false;
	}

	kwota = kwota + k - prowizja;
	return true;
}

bool Forma_platnosci::wykonaj_platnosc(string w, float k)
{
	if (w != waluta)
	{
		cout << "Niezgodna waluta" << endl;
		return false;
	}
	if (kwota < k)
	{
		cout << "Za malo pieniedzy na koncie" << endl;
		return false;
	}
	else
		kwota = kwota - k;
	return true;
}

//____________________________________________________________________
void Deszcz::efekt()
{
	cout << "Deszcz" << endl;
	cout << " '    '    ' '  ' ''' '       ' '  ' '   '    ' '     ' ' '" << endl;
	cout << " ' '     ' ' '  '''    '  '  ' '  ' '     '   ' ' '       '" << endl;
	cout << " '     '    ' ' ' '''     '      '  ' '   '     ' ' ' ''  '" << endl;
	cout << "     ' '     '  '   ' '''    ' '   ''   ' ' ' '  '    '  ' " << endl;
	cout << " ' '    ' ' ' '   ''        ' '  ' '        ' ' '       ' '" << endl;
	cout << " ' '    ' ' ' '''    ' '    ' '  ' '    '   ' ' '  '      '" << endl;
	cout << "     '  '    ' ' '''      '  ''  '  ' '  '      '   ' ' ' '" << endl;
	cout << " '  '        ' ' ' ''''        ' '  ' '    '   ' '    ' ' '" << endl;
	cout << " ' '    ' ' ' '''        ' '  ' '  '     ' ' ' '  '  ' '  '" << endl;
}

void Wybuch::efekt()
{
	cout << "Wybuch" << endl;
}

void Ogien::efekt()
{
	cout << "Ogien" << endl;
}

void Blysk::efekt()
{
	cout << "Blysk" << endl;
}

void Dym::efekt()
{
	cout << "Dym" << endl;
}
//_______________________________________________________-

void Telefon_kom :: czytaj(string nazwa)
{
	fstream plik;
	plik.open(nazwa, std::ios::in );
	if (plik.good() == true)
	{
		plik >> numer;
		plik.close();
	}
}
void Telefon_sta::czytaj(string nazwa)
{
	fstream plik;
	plik.open(nazwa, std::ios::in);
	if (plik.good() == true)
	{
		plik >>numer;
			plik.close();
	}
}

void Kwota::czytaj(string nazwa)
{
	fstream plik;
	plik.open(nazwa, std::ios::in);
	if (plik.good() == true)
	{
		plik >> kwota;
			plik.close();
	}
}

void Email::czytaj(string nazwa)
{
	fstream plik;
	plik.open(nazwa, std::ios::in);
	if (plik.good() == true)
	{
		plik >> email;
			plik.close();
	}
}

void Liczba_rzymska::czytaj(string nazwa)
{
	fstream plik;
	plik.open(nazwa, std::ios::in);
	if (plik.good() == true)
	{
		plik >> liczba;
			plik.close();
	}
}
