#include <iostream>
#include <string>

using namespace std;

class Walidator
{
	virtual bool sprawdz(string x) = 0;
	bool sprawdzenie(Telefon_kom * nk, Telefon_sta * ns, Kwota * k, Email * e, Liczba_rzymska * l);
	virtual void czytaj(string nazwa) = 0;
};

class Telefon_kom : public Walidator
{
public:
	string numer;
	virtual bool sprawdz();
	virtual void czytaj(string nazwa);
};

class Telefon_sta : public Walidator
{
public:
	string numer;
	virtual bool sprawdz();
	virtual void czytaj(string nazwa);
};

class Kwota : public Walidator
{
public:
	string kwota;
	virtual bool sprawdz();
	virtual void czytaj(string nazwa);
};

class Email : public Walidator
{
public:
	string email;
	virtual bool sprawdz();
	virtual void czytaj(string nazwa);
};

class Liczba_rzymska : public Walidator
{
public:
	string liczba;
	virtual bool sprawdz();
	virtual void czytaj(string nazwa);
};

//___________________________________________________________

class Forma_platnosci
{
public:
	float kwota;
	float prowizja;
	string waluta;

	virtual bool wykonaj_platnosc(string w, float k);
	virtual bool nalicz_oplate(string w, float k);
};

class Przelew_odbior : public Forma_platnosci
{

};

class Przelew : public Forma_platnosci
{

};

class Systemy_platnosci_elektronicznej : public Forma_platnosci
{

};

//______________________________________________________________
class Efekt_specjalny
{
public:
	virtual void efekt() = 0;
};

class Deszcz : public Efekt_specjalny
{
public:
	virtual void efekt();
};

class Wybuch : public Efekt_specjalny
{
public:
	virtual void efekt();
};

class Ogien : public Efekt_specjalny
{
public:
	virtual void efekt();
};

class Blysk : public Efekt_specjalny
{
public:
	virtual void efekt();
};

class Dym : public Efekt_specjalny
{
public:
	virtual void efekt();
};
