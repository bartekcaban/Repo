#include "Header.hpp"
#include "Pole.hpp"
#include "Goniec.hpp"
#include "Wieza.hpp"
#include "Skoczek.hpp"
#include "Lanca.hpp"
#include "Krol.hpp"
#include "Zloty_General.hpp"
#include "Srebrny_General.hpp"
#include "Pionek.hpp"
#include "Lista.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

bool wygrana(Krol K1, Krol K2)
{
	if (K1.status == false || K2.status == false)
		return true;
	else
		return false;
}


int main()
{	
	//tworzenie obiektow
	//I
	Lanca L1(1, gracz_1, bez_promocji, nullptr);
	Pole I1(9, 9, "Lanca", 0, 0, &L1, 0, 0, 0, 0, 0, 48, 685);
	L1.UstawPole(&I1);
	Skoczek S1(1, gracz_1, bez_promocji, nullptr);
	Pole I2(9, 8, "Skoczek", 0, &S1, 0, 0, 0, 0, 0, 0, 128, 685);
	S1.UstawPole(&I2);
	Srebrny_General SG1(1, gracz_1, bez_promocji, nullptr);
	Pole I3(9, 7, "Srebrny_General", 0, 0, 0, &SG1, 0, 0, 0, 0, 207, 685);
	SG1.UstawPole(&I3);
	Zloty_General ZG1(1, gracz_1, bez_promocji, nullptr);
	Pole I4(9, 6, "Zloty_General", 0, 0, 0, 0, &ZG1, 0, 0, 0, 285, 685);
	ZG1.UstawPole(&I4);
	Krol K1(9, gracz_1, bez_promocji, nullptr);
	Pole I5(9, 5, "Krol", 0, 0, 0, 0, 0, 0, 0, &K1, 365, 685);
	K1.UstawPole(&I5);
	Zloty_General ZG2(1, gracz_1, bez_promocji, nullptr);
	Pole I6(9, 4, "Zloty_General", 0, 0, 0, 0, &ZG2, 0, 0, 0, 445, 685);
	ZG2.UstawPole(&I6);
	Srebrny_General SG2(1, gracz_1, bez_promocji, nullptr);
	Pole I7(9, 3, "Srebrny_General", 0, 0, 0, &SG2, 0, 0, 0, 0, 523, 685);
	SG2.UstawPole(&I7);
	Skoczek S2(1, gracz_1, bez_promocji, nullptr);
	Pole I8(9, 2, "Skoczek", 0, &S2, 0, 0, 0, 0, 0, 0, 603, 685);
	S2.UstawPole(&I8);
	Lanca L2(1, gracz_1, bez_promocji, nullptr);
	Pole I9(9, 1, "Lanca", 0, 0, &L2, 0, 0, 0, 0, 0, 682, 685);
	L2.UstawPole(&I9);
	
	//H
	Pole H1(8, 9, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 48, 605);
	Goniec GO1(1, gracz_1, bez_promocji, nullptr);
	Pole H2(8, 8, "Goniec", 0, 0, 0, 0, 0, &GO1, 0, 0, 128, 605);
	GO1.UstawPole(&H2);
	Pole H3(8, 7, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 207, 605);
	Pole H4(8, 6, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 285, 605);
	Pole H5(8, 5, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 365, 605);
	Pole H6(8, 4, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 445, 605);
	Pole H7(8, 3, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 523, 605);
	Wieza W1(1, gracz_1, bez_promocji, nullptr);
	Pole H8(8, 2, "Wieza", 0, 0, 0, 0, 0, 0, &W1, 0, 603, 605);
	W1.UstawPole(&H8);
	Pole H9(8, 1, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 682, 605);
	
	//G
	Pionek P1(1, gracz_1, bez_promocji, nullptr);
	Pole G1(7, 9, "Pionek", &P1, 0, 0, 0, 0, 0, 0, 0, 48, 525);
	P1.UstawPole(&G1);
	Pionek P2(1, gracz_1, bez_promocji, nullptr);
	Pole G2(7, 8, "Pionek", &P2, 0, 0, 0, 0, 0, 0, 0, 128, 525);
	P2.UstawPole(&G2);
	Pionek P3(1, gracz_1, bez_promocji, nullptr);
	Pole G3(7, 7, "Pionek", &P3, 0, 0, 0, 0, 0, 0, 0, 207, 525);
	P3.UstawPole(&G3);
	Pionek P4(1, gracz_1, bez_promocji, nullptr);
	Pole G4(7, 6, "Pionek", &P4, 0, 0, 0, 0, 0, 0, 0, 285, 525);
	P4.UstawPole(&G4);
	Pionek P5(1, gracz_1, bez_promocji, nullptr);
	Pole G5(7, 5, "Pionek", &P5, 0, 0, 0, 0, 0, 0, 0, 365, 525);
	P5.UstawPole(&G5);
	Pionek P6(1, gracz_1, bez_promocji, nullptr);
	Pole G6(7, 4, "Pionek", &P6, 0, 0, 0, 0, 0, 0, 0, 445, 525);
	P6.UstawPole(&G6);
	Pionek P7(1, gracz_1, bez_promocji, nullptr);
	Pole G7(7, 3, "Pionek", &P7, 0, 0, 0, 0, 0, 0, 0, 523, 525);
	P7.UstawPole(&G7);
	Pionek P8(1, gracz_1, bez_promocji, nullptr);
	Pole G8(7, 2, "Pionek", &P8, 0, 0, 0, 0, 0, 0, 0, 603, 525);
	P8.UstawPole(&G8);
	Pionek P9(1, gracz_1, bez_promocji, nullptr);
	Pole G9(7, 1, "Pionek", &P9, 0, 0, 0, 0, 0, 0, 0, 682, 525);
	P9.UstawPole(&G9);
	
	//F
	Pole F1(6, 9, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 48, 445);
	Pole F2(6, 8, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 128, 445);
	Pole F3(6, 7, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 207, 445);
	Pole F4(6, 6, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 285, 445);
	Pole F5(6, 5, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 365, 445);
	Pole F6(6, 4, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 445, 445);
	Pole F7(6, 3, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 523, 445);
	Pole F8(6, 2, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 603, 445);
	Pole F9(6, 1, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 682, 445);

	//E
	Pole E1(5, 9, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 48, 365);
	Pole E2(5, 8, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 128, 365);
	Pole E3(5, 7, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 207, 365);
	Pole E4(5, 6, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 285, 365);
	Pole E5(5, 5, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 365, 365);
	Pole E6(5, 4, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 445, 365);
	Pole E7(5, 3, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 523, 365);
	Pole E8(5, 2, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 603, 365);
	Pole E9(5, 1, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 682, 365);

	//D
	Pole D1(4, 9, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 48, 285);
	Pole D2(4, 8, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 128, 285);
	Pole D3(4, 7, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 207, 285);
	Pole D4(4, 6, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 285, 285);
	Pole D5(4, 5, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 365, 285);
	Pole D6(4, 4, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 445, 285);
	Pole D7(4, 3, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 523, 285);
	Pole D8(4, 2, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 603, 285);
	Pole D9(4, 1, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 682, 285);

	//C
	Pionek P10(1, gracz_2, bez_promocji, nullptr);
	Pole C1(3, 9, "Pionek", &P10, 0, 0, 0, 0, 0, 0, 0, 48, 205);
	P10.UstawPole(&C1);
	Pionek P11(1, gracz_2, bez_promocji, nullptr);
	Pole C2(3, 8, "Pionek", &P11, 0, 0, 0, 0, 0, 0, 0, 128, 205);
	P11.UstawPole(&C2);
	Pionek P12(1, gracz_2, bez_promocji, nullptr);
	Pole C3(3, 7, "Pionek", &P12, 0, 0, 0, 0, 0, 0, 0, 207, 205);
	P12.UstawPole(&C3);
	Pionek P13(1, gracz_2, bez_promocji, nullptr);
	Pole C4(3, 6, "Pionek", &P13, 0, 0, 0, 0, 0, 0, 0, 285, 205);
	P13.UstawPole(&C4);
	Pionek P14(1, gracz_2, bez_promocji, nullptr);
	Pole C5(3, 5, "Pionek", &P14, 0, 0, 0, 0, 0, 0, 0, 365, 205);
	P14.UstawPole(&C5);
	Pionek P15(1, gracz_2, bez_promocji, nullptr);
	Pole C6(3, 4, "Pionek", &P15, 0, 0, 0, 0, 0, 0, 0, 445, 205);
	P15.UstawPole(&C6);
	Pionek P16(1, gracz_2, bez_promocji, nullptr);
	Pole C7(3, 3, "Pionek", &P16, 0, 0, 0, 0, 0, 0, 0, 523, 205);
	P16.UstawPole(&C7);
	Pionek P17(1, gracz_2, bez_promocji, nullptr);
	Pole C8(3, 2, "Pionek", &P17, 0, 0, 0, 0, 0, 0, 0, 603, 205);
	P17.UstawPole(&C8);
	Pionek P18(1, gracz_2, bez_promocji, nullptr);
	Pole C9(3, 1, "Pionek", &P18, 0, 0, 0, 0, 0, 0, 0, 682, 205);
	P18.UstawPole(&C9);

	//B
	Pole B1(2, 9, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 48, 125);
	Goniec GO2(1, gracz_2, bez_promocji, nullptr);
	Pole B2(2, 8, "Goniec", 0, 0, 0, 0, 0, &GO2, 0, 0, 128, 125);
	GO2.UstawPole(&B2);
	Pole B3(2, 7, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 207, 125);
	Pole B4(2, 6, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 285, 125);
	Pole B5(2, 5, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 365, 125);
	Pole B6(2, 4, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 445, 125);
	Pole B7(2, 3, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 523, 125);
	Wieza W2(1, gracz_2, bez_promocji, nullptr);
	Pole B8(2, 2, "Wieza", 0, 0, 0, 0, 0, 0, &W2, 0, 603, 125);
	W2.UstawPole(&B8);
	Pole B9(2, 1, "brak", 0, 0, 0, 0, 0, 0, 0, 0, 682, 125);

	//A
	Lanca L3(1, gracz_2, bez_promocji, nullptr);
	Pole A1(1, 9, "Lanca", 0, 0, &L3, 0, 0, 0, 0, 0, 48, 45);
	L3.UstawPole(&A1);
	Skoczek S3(1, gracz_2, bez_promocji, nullptr);
	Pole A2(1, 8, "Skoczek", 0, &S3, 0, 0, 0, 0, 0, 0, 128, 45);
	S3.UstawPole(&A2);
	Srebrny_General SG3(1, gracz_2, bez_promocji, nullptr);
	Pole A3(1, 7, "Srebrny_General", 0, 0, 0, &SG3, 0, 0, 0, 0, 207, 45);
	SG3.UstawPole(&A3);
	Zloty_General ZG3(1, gracz_2, bez_promocji, nullptr);
	Pole A4(1, 6, "Zloty_General", 0, 0, 0, 0, &ZG3, 0, 0, 0, 285, 45);
	ZG3.UstawPole(&A4);
	Krol K2(1, gracz_2, bez_promocji, nullptr);
	Pole A5(1, 5, "Krol", 0, 0, 0, 0, 0, 0, 0, &K2, 365, 45);
	K2.UstawPole(&A5);
	Zloty_General ZG4(1, gracz_2, bez_promocji, nullptr);
	Pole A6(1, 4, "Zloty_General", 0, 0, 0, 0, &ZG4, 0, 0, 0, 445, 45);
	ZG4.UstawPole(&A6);
	Srebrny_General SG4(1, gracz_2, bez_promocji, nullptr);
	Pole A7(1, 3, "Srebrny_General", 0, 0, 0, &SG4, 0, 0, 0, 0, 523, 45);
	SG4.UstawPole(&A7);
	Skoczek S4(1, gracz_2, bez_promocji, nullptr);
	Pole A8(1, 2, "Skoczek", 0, &S4, 0, 0, 0, 0, 0, 0, 603, 45);
	S4.UstawPole(&A8);
	Lanca L4(1, gracz_2, bez_promocji, nullptr);
	Pole A9(1, 1, "Lanca", 0, 0, &L4, 0, 0, 0, 0, 0, 682, 45);
	L4.UstawPole(&A9);
	//---------------------------------------------------------------------------------------

	RenderWindow okno(VideoMode(1200, 800, 32), "Shogi");//tworzenie okna

	Texture plansza;
	plansza.loadFromFile("plansza.png");
	Sprite s_plansza;
	s_plansza.setTexture(plansza);

	Texture tlo;
	tlo.loadFromFile("tlo.png");
	Sprite s_tlo;
	s_tlo.setTexture(tlo);

	Texture _wygrana;
	_wygrana.loadFromFile("wygrana.png");
	Sprite s_wygrana;
	s_wygrana.setTexture(_wygrana);

	Pole  *tab[81] = {
	 &A9, &A8, &A7, &A6, &A5, &A4, &A3, &A2, &A1 ,
	 &B9, &B8, &B7, &B6, &B5, &B4, &B3, &B2, &B1 ,
	 &C9, &C8, &C7, &C6, &C5, &C4, &C3, &C2, &C1 ,
	 &D9, &D8, &D7, &D6, &D5, &D4, &D3, &D2, &D1 ,
	 &E9, &E8, &E7, &E6, &E5, &E4, &E3, &E2, &E1 ,
	 &F9, &F8, &F7, &F6, &F5, &F4, &F3, &F2, &F1 ,
	 &G9, &G8, &G7, &G6, &G5, &G4, &G3, &G2, &G1 ,
	 &H9, &H8, &H7, &H6, &H5, &H4, &H3, &H2, &H1 ,
	 &I9, &I8, &I7, &I6, &I5, &I4, &I3, &I2, &I1 
	};

	Figura * f[40] = { &P1, &P2, &P3, &P4, &P5, &P6, &P7, &P8, &P9, &P10, &P11, &P12, &P13, &P14, &P15, &P16, &P17, &P18, &L1, &L2, &L3, &L4,
		&S1, &S2, &S3, &S4, &K1, &K2, &GO1, &GO2, &W1, &W2, &ZG1, &ZG2, &ZG3, &ZG4, &SG1, &SG2, &SG3, &SG4
	};

	Lista Li1;
	Lista Li2;

	int n = 0;
	Gracz gr = gracz_1;

	while (okno.isOpen())//petla programu
	{
		Vector2i poz = Mouse::getPosition(okno);

		Event zdarzenie;
		while (okno.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == Event::Closed)//zamkniecie okna i zapisanie gry
			{
				wypisz(Li1, Li2);
				okno.close();
			}

			if (zdarzenie.type == Event::MouseButtonPressed)
				if (zdarzenie.key.code == Mouse::Left)
					for (int i = 0; i<40; i++)
						if (f[i]->sprajt.getGlobalBounds().contains(poz.x, poz.y) && f[i]->gracz == gr)
						{
							f[i]->isMove = true;
							n = i;
						}
			if (zdarzenie.type == Event::MouseButtonReleased)
				if (zdarzenie.key.code == Mouse::Left)
				{
					if (gr == f[n]->gracz && f[n]->isMove == true && f[n]->status == true)
					{
						f[n]->isMove = false;
						for (int i = 0; i < 81; i++)
							if ((tab[i]->_x < poz.x) && (tab[i]->_y < poz.y) && (tab[i]->_x + 75 > poz.x) && (tab[i]->_y + 80 > poz.y))
							{
								if (f[n]->pole->status == "Pionek")
									if (f[n]->pole->p->Sprawdz_ruch(tab[i]))
									{
										if (f[n]->gracz == gracz_1)
										{
											gr = gracz_2;
											Li1.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										else
										{
											gr = gracz_1;
											Li2.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										f[n]->pole->p->Ruch(tab[i], f[n]->pole->p);
										break;
									}
								if (f[n]->pole->status == "Skoczek")
									if (f[n]->pole->s->Sprawdz_ruch(tab[i]))
									{
										if (f[n]->gracz == gracz_1)
										{
											gr = gracz_2;
											Li1.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										else
										{
											gr = gracz_1;
											Li2.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										f[n]->pole->s->Ruch(tab[i], f[n]->pole->s);
										break;
									}
								if (f[n]->pole->status == "Lanca")
									if (f[n]->pole->l->Sprawdz_ruch(tab[i], tab))
									{
										if (f[n]->gracz == gracz_1)
										{
											gr = gracz_2;
											Li1.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										else
										{
											gr = gracz_1;
											Li2.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										f[n]->pole->l->Ruch(tab[i], f[n]->pole->l);
										break;
									}
								if (f[n]->pole->status == "Krol")
									if (f[n]->pole->k->Sprawdz_ruch(tab[i]))
									{
										if (f[n]->gracz == gracz_1)
										{
											gr = gracz_2;
											Li1.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										else
										{
											gr = gracz_1;
											Li2.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										f[n]->pole->k->Ruch(tab[i], f[n]->pole->k);
										break;
									}
								if (f[n]->pole->status == "Goniec")
									if (f[n]->pole->g->Sprawdz_ruch(tab[i], tab))
									{
										if (f[n]->gracz == gracz_1)
										{
											gr = gracz_2;
											Li1.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										else
										{
											gr = gracz_1;
											Li2.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										f[n]->pole->g->Ruch(tab[i], f[n]->pole->g);
										break;
									}
								if (f[n]->pole->status == "Wieza")
									if (f[n]->pole->w->Sprawdz_ruch(tab[i], tab))
									{
										if (f[n]->gracz == gracz_1)
										{
											gr = gracz_2;
											Li1.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										else
										{
											gr = gracz_1;
											Li2.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										f[n]->pole->w->Ruch(tab[i], f[n]->pole->w);
										break;
									}
								if (f[n]->pole->status == "Srebrny_General")
									if (f[n]->pole->sg->Sprawdz_ruch(tab[i]))
									{
										if (f[n]->gracz == gracz_1)
										{
											gr = gracz_2;
											Li1.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										else
										{
											gr = gracz_1;
											Li2.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										f[n]->pole->sg->Ruch(tab[i], f[n]->pole->sg);
										break;
									}
								if (f[n]->pole->status == "Zloty_General")
									if (f[n]->pole->zg->Sprawdz_ruch(tab[i]))
									{
										if (f[n]->gracz == gracz_1)
										{
											gr = gracz_2;
											Li1.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										else
										{
											gr = gracz_1;
											Li2.zapisz(f[n]->pole->status, f[n]->pole->x, f[n]->pole->y, tab[i]->x, tab[i]->y);
										}
										f[n]->pole->zg->Ruch(tab[i], f[n]->pole->zg);
										break;
									}
							}
					}
					else if (f[n]->status == false)
					{
						for (int i = 0; i < 81; i++)
						{
							if ((tab[i]->_x < poz.x) && (tab[i]->_y < poz.y) && (tab[i]->_x + 75 > poz.x) && (tab[i]->_y + 80 > poz.y) && tab[i]->status == "brak")
							{
	
								//sprawdzenie, jaka to figura
								if (f[n]->nazwa == "Goniec")
								{
									if (GO1.status == false && GO1.gracz == gr)
									{
										tab[i]->setFigura(&GO1);
										GO1.UstawPole(tab[i]);
										GO1.status = true;
									}
									else if (GO2.status == false && GO2.gracz == gr)
									{
										tab[i]->setFigura(&GO2);
										GO2.UstawPole(tab[i]);
										GO2.status = true;
									}
								}
								else if (f[n]->nazwa == "Wieza")
								{
									if (W1.status == false && W1.gracz == gr)
									{
										tab[i]->setFigura(&W1);
										W1.UstawPole(tab[i]);
										W1.status = true;
									}
									else if (W2.status == false && W2.gracz == gr)
									{
										tab[i]->setFigura(&W2);
										W2.UstawPole(tab[i]);
										W2.status = true;
									}
								}
								else if (f[n]->nazwa == "Lanca")
								{
									if (L1.status == false && L1.gracz == gr)
									{
										tab[i]->setFigura(&L1);
										L1.UstawPole(tab[i]);
										L1.status = true;
									}
									else if (L2.status == false && L2.gracz == gr)
									{
										tab[i]->setFigura(&L2);
										L2.UstawPole(tab[i]);
										L2.status = true;
									}
									else if (L3.status == false && L3.gracz == gr)
									{
										tab[i]->setFigura(&L3);
										L3.UstawPole(tab[i]);
										L3.status = true;
									}
									else if (L4.status == false && L4.gracz == gr)
									{
										tab[i]->setFigura(&L4);
										L4.UstawPole(tab[i]);
										L4.status = true;
									}
								}
								else if (f[n]->nazwa == "Skoczek")
								{
									if (S1.status == false && S1.gracz == gr)
									{
										tab[i]->setFigura(&S1);
										S1.UstawPole(tab[i]);
										S1.status = true;
									}
									else if (S2.status == false && S2.gracz == gr)
									{
										tab[i]->setFigura(&S2);
										S2.UstawPole(tab[i]);
										S2.status = true;
									}
									else if (S3.status == false && S3.gracz == gr)
									{
										tab[i]->setFigura(&S3);
										S3.UstawPole(tab[i]);
										S3.status = true;
									}
									else if (S4.status == false && S4.gracz == gr)
									{
										tab[i]->setFigura(&S4);
										S4.UstawPole(tab[i]);
										S4.status = true;
									}
								}
								if (f[n]->nazwa == "Srebrny_General")
								{
									if (SG1.status == false && SG1.gracz == gr)
									{
										tab[i]->setFigura(&SG1);
										SG1.UstawPole(tab[i]);
										SG1.status = true;
									}
									else if (SG2.status == false && SG2.gracz == gr)
									{
										tab[i]->setFigura(&SG2);
										SG2.UstawPole(tab[i]);
										SG2.status = true;
									}
									else if (SG3.status == false && SG3.gracz == gr)
									{
										tab[i]->setFigura(&SG3);
										SG3.UstawPole(tab[i]);
										SG3.status = true;
									}
									else if (SG4.status == false && SG4.gracz == gr)
									{
										tab[i]->setFigura(&SG4);
										SG4.UstawPole(tab[i]);
										SG4.status = true;
									}
								}
								else if (f[n]->nazwa == "Zloty_General")
								{
									if (ZG1.status == false && ZG1.gracz == gr)
									{
										tab[i]->setFigura(&ZG1);
										ZG1.UstawPole(tab[i]);
										ZG1.status = true;
									}
									else if (ZG2.status == false && ZG2.gracz == gr)
									{
										tab[i]->setFigura(&ZG2);
										ZG2.UstawPole(tab[i]);
										ZG2.status = true;
									}
									else if (ZG3.status == false && ZG3.gracz == gr)
									{
										tab[i]->setFigura(&ZG3);
										ZG3.UstawPole(tab[i]);
										ZG3.status = true;
									}
									else if (ZG4.status == false && ZG4.gracz == gr)
									{
										tab[i]->setFigura(&ZG4);
										ZG4.UstawPole(tab[i]);
										ZG4.status = true;
									}
								}
								else
								{
									if (P1.status == false && P1.gracz == gr)
									{
										tab[i]->setFigura(&P1);
										P1.UstawPole(tab[i]);
										P1.status = true;
									}
									else if (P2.status == false && P2.gracz == gr)
									{
										tab[i]->setFigura(&P2);
										P2.UstawPole(tab[i]);
										P2.status = true;
									}
									else if (P3.status == false && P3.gracz == gr)
									{
										tab[i]->setFigura(&P3);
										P3.UstawPole(tab[i]);
										P3.status = true;
									}
									else if (P4.status == false && P4.gracz == gr)
									{
										tab[i]->setFigura(&P4);
										P4.UstawPole(tab[i]);
										P4.status = true;
									}
									else if (P5.status == false && P5.gracz == gr)
									{
										tab[i]->setFigura(&P5);
										P5.UstawPole(tab[i]);
										P5.status = true;
									}
									else if (P6.status == false && P6.gracz == gr)
									{
										tab[i]->setFigura(&P6);
										P6.UstawPole(tab[i]);
										P6.status = true;
									}
									else if (P7.status == false && P7.gracz == gr)
									{
										tab[i]->setFigura(&P7);
										P7.UstawPole(tab[i]);
										P7.status = true;
									}
									else if (P8.status == false && P8.gracz == gr)
									{
										tab[i]->setFigura(&P8);
										P8.UstawPole(tab[i]);
										P8.status = true;
									}
									else if (P9.status == false && P9.gracz == gr)
									{
										tab[i]->setFigura(&P9);
										P9.UstawPole(tab[i]);
										P9.status = true;
									}
									else if (P10.status == false && P10.gracz == gr)
									{
										tab[i]->setFigura(&P10);
										P10.UstawPole(tab[i]);
										P10.status = true;
									}
									else if (P11.status == false && P11.gracz == gr)
									{
										tab[i]->setFigura(&P11);
										P11.UstawPole(tab[i]);
										P11.status = true;
									}
									else if (P12.status == false && P12.gracz == gr)
									{
										tab[i]->setFigura(&P12);
										P12.UstawPole(tab[i]);
										P12.status = true;
									}
									else if (P13.status == false && P13.gracz == gr)
									{
										tab[i]->setFigura(&P13);
										P13.UstawPole(tab[i]);
										P13.status = true;
									}
									else if (P14.status == false && P14.gracz == gr)
									{
										tab[i]->setFigura(&P14);
										P14.UstawPole(tab[i]);
										P14.status = true;
									}
									else if (P15.status == false && P15.gracz == gr)
									{
										tab[i]->setFigura(&P15);
										P15.UstawPole(tab[i]);
										P15.status = true;
									}
									else if (P16.status == false && P16.gracz == gr)
									{
										tab[i]->setFigura(&P16);
										P16.UstawPole(tab[i]);
										P16.status = true;
									}
									else if (P17.status == false && P17.gracz == gr)
									{
										tab[i]->setFigura(&P17);
										P17.UstawPole(tab[i]);
										P17.status = true;
									}
									else if (P18.status == false && P18.gracz == gr)
									{
										tab[i]->setFigura(&P18);
										P18.UstawPole(tab[i]);
										P18.status = true;
									}

									if (f[n]->gracz == gracz_1)
										gr = gracz_2;
									else
										gr = gracz_1;
									break;
								}
							//----------------------------------------------------------------
							}
						}

						for(int j=0;j<40;j++)
							f[j]->isMove = false;
					}
				}
		}
		
		//wyswietlanie t³a i planszy
		okno.clear();
		s_plansza.setPosition(0, 0);
		okno.draw(s_plansza);
		s_tlo.setPosition(800, 0);
		okno.draw(s_tlo);

		//-----------------------------------------------------
		//wyswietlanie figur
		okno.draw(L1.wyswietl(poz));
		okno.draw(S1.wyswietl(poz));
		okno.draw(SG1.wyswietl(poz));
		okno.draw(ZG1.wyswietl(poz));
		okno.draw(K1.wyswietl(poz));
		okno.draw(ZG2.wyswietl(poz));
		okno.draw(SG2.wyswietl(poz));
		okno.draw(S2.wyswietl(poz));
		okno.draw(L2.wyswietl(poz));
		okno.draw(GO1.wyswietl(poz));
		okno.draw(W1.wyswietl(poz));
		okno.draw(P1.wyswietl(poz));
		okno.draw(P2.wyswietl(poz));
		okno.draw(P3.wyswietl(poz));
		okno.draw(P4.wyswietl(poz));
		okno.draw(P5.wyswietl(poz));
		okno.draw(P6.wyswietl(poz));
		okno.draw(P7.wyswietl(poz));
		okno.draw(P8.wyswietl(poz));
		okno.draw(P9.wyswietl(poz));

		okno.draw(L3.wyswietl(poz));
		okno.draw(S3.wyswietl(poz));
		okno.draw(SG3.wyswietl(poz));
		okno.draw(ZG3.wyswietl(poz));
		okno.draw(K2.wyswietl(poz));
		okno.draw(ZG4.wyswietl(poz));
		okno.draw(SG4.wyswietl(poz));
		okno.draw(S4.wyswietl(poz));
		okno.draw(L4.wyswietl(poz));
		okno.draw(GO2.wyswietl(poz));
		okno.draw(W2.wyswietl(poz));
		okno.draw(P10.wyswietl(poz));
		okno.draw(P11.wyswietl(poz));
		okno.draw(P12.wyswietl(poz));
		okno.draw(P13.wyswietl(poz));
		okno.draw(P14.wyswietl(poz));
		okno.draw(P15.wyswietl(poz));
		okno.draw(P16.wyswietl(poz));
		okno.draw(P17.wyswietl(poz));
		okno.draw(P18.wyswietl(poz));

		if (wygrana(K1, K2))
		{
			okno.draw(s_wygrana);
		}

		//-----------------------------------------------------
		//wyswietlanie wszystkiego na ekran
		okno.display();
	}
}