#pragma once
#include <iostream>
#include "Tower.h"
#include "Monster.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Tower1 :public Tower
{
	int damage;
	int price;
	int range;
	Texture texture;
	Sprite sprite;
	Texture arrow_texture;
	Sprite arrow_sprite;
	bool firing;
	Monster * target;
public:
	Tower1(Vector2f pos);
	void display(RenderWindow * window);
	Vector2i return_position();
	int return_range();
	bool is_firing();
	void fire(Monster * monster);
};
