#include "Lista.h"
#include <list>

list <Lista*> lista;

void Lista::dodaj(Zespolona i)
{
	Lista * temp = new Lista;
	temp->el = i;
	lista.push_back(temp);
};

void Lista::usun()
{
	lista.clear();
};

void Lista::wypisz()
{
	for (list<Lista*>::iterator iter = lista.begin(); iter != lista.end(); ++iter)
		cout << (*iter)->el.Re << " + " << (*iter)->el.Im << "i" << endl;
};