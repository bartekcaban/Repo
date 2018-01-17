#include "Element.h"

Element::Element(float r,float i, Element* wsk)
{
	element.Re = r;
	element.Im = i;
	next = wsk;
}