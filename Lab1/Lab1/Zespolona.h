#include <iostream>
using namespace std;

class Zespolona
{
public:
	float Re;
	float Im;
	static int licznik; 

	void set();
	void get();
	~Zespolona();// destruktor
	Zespolona();  // konstruktor bezargumentwoy
	Zespolona(float); // konstruktor 1argumentowy
	Zespolona(float, float); // konstruktor wieloargumentowy
	Zespolona(const Zespolona &zespolona);// konstruktor kopiuj¹cy
};