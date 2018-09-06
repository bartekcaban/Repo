#include "Monster1.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;

Monster1::Monster1()
{
	hp = 3;
	damage = 5;
	speed = 2;
	coins = 5;
	try
	{
		texture.loadFromFile("Monster/monster1.png");
	}
	catch (std::exception e)
	{
		e.what();
	}
	sprite.setTexture(texture);
	x = 0;
	y = 270;
	sprite.setPosition(x,y);
}

bool Monster1::move_display(RenderWindow * window, Player * player)
{
	if (sprite.getPosition().x < 140 && sprite.getPosition().y == 270)
	{
		x = x + speed;
	}
	if (sprite.getPosition().x == 140 && sprite.getPosition().y < 520)
	{
		y = y + speed;
	}
	if (sprite.getPosition().x < 390 && sprite.getPosition().y == 520)
	{
		x = x + speed;
	}
	if (sprite.getPosition().x == 390 && sprite.getPosition().y <= 520 && y > 140)
	{
		y = y - speed;
	}
	if (sprite.getPosition().x < 1160 && sprite.getPosition().y == 140)
	{
		x = x + speed;
	}
	if (sprite.getPosition().x == 1160 && sprite.getPosition().y < 400)
	{
		y = y + speed;
	}
	if (sprite.getPosition().x > 640 && sprite.getPosition().y == 400)
	{
		x = x - speed;
	}
	if (sprite.getPosition().x == 640 && sprite.getPosition().y < 650 && y > 350)
	{
		y = y + speed;
	}
	if (sprite.getPosition().x < 1160 && sprite.getPosition().y == 650)
	{
		x = x + speed;
	}
	if (sprite.getPosition().x == 1160 && sprite.getPosition().y == 650)
	{
		player->decrease_hp(damage);
		return true;
	}
	sprite.setPosition(x, y);
	window->draw(sprite);
	return false;
}

Vector2i Monster1::return_position()
{
	Vector2i vec;
	vec.x = sprite.getPosition().x + 40;
	vec.y = sprite.getPosition().y + 40;
	return vec;
}

void Monster1::get_damage(int dmg)
{
	hp = hp - dmg;
}

bool Monster1::contain(Vector2f arrow_pos)
{
	if (sprite.getGlobalBounds().contains(arrow_pos.x, arrow_pos.y))
		return true;
	else
		return false;
}

bool Monster1::is_dead()
{
	if (hp <= 0)
		return true;
	else
		return false;
}

int Monster1::return_coins()
{
	return coins;
}