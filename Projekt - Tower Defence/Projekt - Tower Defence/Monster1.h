#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Monster.h"
using namespace sf;

class Monster1 :public Monster
{
	int hp;
	int damage;
	int speed;
	int coins;
	Texture texture;
	Sprite sprite;
	float x;
	float y;
public:
	Monster1();
	bool move_display(RenderWindow * window, Player * player);
	Vector2i return_position();
	bool contain(Vector2f arrow_pos);
	void get_damage(int dmg);
	bool is_dead();
	int return_coins();
};