#include <iostream>
#include "Zespolona.cpp"
using namespace std;

class Element
{
public:
	Zespolona element;
	Element * next;

	Element(float r=1, float i=0, Element * wsk= nullptr);
};