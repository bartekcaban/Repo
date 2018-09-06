#include <iostream>
#include "Tower2.h"
using namespace sf;

Tower2::Tower2(Vector2f pos)
{
	try
	{
		texture.loadFromFile("Tower/tower2.png");
		arrow_texture.loadFromFile("Tower/arrow.png");
	}
	catch (std::exception e)
	{
		e.what();
	}
	sprite.setTexture(texture);
	sprite.setPosition(pos.x, pos.y);
	arrow_sprite.setTexture(arrow_texture);
	arrow_sprite.setPosition(return_position().x, return_position().y);
	damage = 2;
	price = 200;
	range = 400;
	firing = false;
	target = nullptr;
}

void Tower2::display(RenderWindow * window)
{
	window->draw(sprite);
	if (firing)
	{
		if (arrow_sprite.getPosition().x > target->return_position().x && arrow_sprite.getPosition().y < target->return_position().y)
			arrow_sprite.setPosition(arrow_sprite.getPosition().x - 2, arrow_sprite.getPosition().y + 2);
		else if (arrow_sprite.getPosition().x > target->return_position().x && arrow_sprite.getPosition().y > target->return_position().y)
			arrow_sprite.setPosition(arrow_sprite.getPosition().x - 2, arrow_sprite.getPosition().y - 2);
		else if (arrow_sprite.getPosition().x < target->return_position().x && arrow_sprite.getPosition().y > target->return_position().y)
			arrow_sprite.setPosition(arrow_sprite.getPosition().x + 2, arrow_sprite.getPosition().y - 2);
		else if (arrow_sprite.getPosition().x < target->return_position().x && arrow_sprite.getPosition().y < target->return_position().y)
			arrow_sprite.setPosition(arrow_sprite.getPosition().x + 2, arrow_sprite.getPosition().y + 2);
		else if (arrow_sprite.getPosition().x == target->return_position().x && arrow_sprite.getPosition().y <= target->return_position().y)
			arrow_sprite.setPosition(arrow_sprite.getPosition().x, arrow_sprite.getPosition().y + 4);
		else if (arrow_sprite.getPosition().x == target->return_position().x && arrow_sprite.getPosition().y >= target->return_position().y)
			arrow_sprite.setPosition(arrow_sprite.getPosition().x, arrow_sprite.getPosition().y - 4);
		else if (arrow_sprite.getPosition().x >= target->return_position().x && arrow_sprite.getPosition().y == target->return_position().y)
			arrow_sprite.setPosition(arrow_sprite.getPosition().x - 4, arrow_sprite.getPosition().y);
		else if (arrow_sprite.getPosition().x <= target->return_position().x && arrow_sprite.getPosition().y == target->return_position().y)
			arrow_sprite.setPosition(arrow_sprite.getPosition().x + 4, arrow_sprite.getPosition().y);
		else
			firing = false;
		window->draw(arrow_sprite);
		if (target->contain(arrow_sprite.getPosition()))
		{
			target->get_damage(damage);
			firing = false;
		}
	}
}

Vector2i Tower2::return_position()
{
	Vector2i vec;
	vec.x = sprite.getPosition().x + 40;
	vec.y = sprite.getPosition().y + 40;
	return vec;
}

int Tower2::return_range()
{
	return range;
}

bool Tower2::is_firing()
{
	return firing;
}

void Tower2::fire(Monster * monster)
{
	target = monster;
	firing = true;
	arrow_sprite.setPosition(return_position().x, return_position().y);
}