#pragma once
#include <iostream>
#include "Monster.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Tower
{
	int damage;//obra¿enia
	int price;//cena
	int range;//zasiêg
	Texture texture;
	Sprite sprite;
	Texture arrow_texture;
	Sprite arrow_sprite;
	bool firing;//false - nie strzela, true - strzela
	Monster * target;//cel
public:
	Tower();
	virtual void display(RenderWindow * window) = 0;//funkcja realizuj¹ca wyœwietlanie wie¿y
	virtual Vector2i return_position() = 0;
	virtual int return_range() = 0;
	virtual bool is_firing() = 0;
	virtual void fire(Monster * monster) = 0;
};