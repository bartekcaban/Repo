#pragma once
#include <iostream>
#include "Player.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Monster
{
	int hp;//punkty �ycia
	int damage;//obra�enia
	int speed;//pr�dko��
	int coins;//monety
	Texture texture;
	Sprite sprite;
	//wsp�rz�dne na planszy
	float x;
	float y;
public:
	Monster();
	virtual bool move_display(RenderWindow * window, Player * player) = 0;//funkcja, kt�ra realizuje przemieszczenie i wy�wietlenie potwora
	virtual Vector2i return_position() = 0;
	virtual bool contain(Vector2f arrow_pos) = 0;
	virtual void get_damage(int dmg) = 0;
	virtual bool is_dead() = 0;
	virtual int return_coins() = 0;
};
