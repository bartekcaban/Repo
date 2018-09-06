#include <iostream>
#include <SFML/Graphics.hpp>
#include "Level.h"

Level::Level()
{
	counter = 4000;
	no_waves = 3;
}

void Level::add_tower(Tower* new_tower)
{
	if (new_tower != nullptr)
		tower_list.push_back(new_tower);
}

void Level::display_towers(RenderWindow * window)
{
	for (std::list<Tower *>::iterator it = tower_list.begin(); it != tower_list.end(); it++)
		(*it)->display(window);
}

void Level::display_monsters(RenderWindow * window, Player * player)
{
	std::list<Monster *>::iterator i;
	bool delete_permission = false;//znak stop, który pozwala na usuniêcie danego obiektu
	for (std::list<Monster *>::iterator it = monster_list.begin(); it != monster_list.end(); it++)
	{
		if ((*it)->move_display(window, player))
		{
			i = it;//zapisanie iteratora do usuniêcia
			delete_permission = true;//i przyzwolenie na to
		}
		if ((*it)->is_dead())
		{
			i = it;//zapisanie iteratora do usuniêcia
			delete_permission = true;//i przyzwolenie na to
			player->add_coins((*i)->return_coins());
		}
	}
	if (delete_permission)
	{
		monster_list.erase(i);
		delete_permission = false;
	}
}

bool Level::generate_monsters()
{
	if (counter == 0)
	{
		if (wave_manager())
			return true;
	}
	if (counter % 500 == 0 && counter !=0)
	{
		Monster * m = new Monster2();
		monster_list.push_back(m);
	}
	else if (counter % 200 == 0 && counter !=0)
	{
		Monster * m = new Monster1();
		monster_list.push_back(m);
	}
	counter = counter - 4;
	return false;
}

void Level::tower_firing()
{
	for (std::list<Tower *>::iterator it = tower_list.begin(); it != tower_list.end(); it++)
	{
		for (std::list<Monster *>::iterator i = monster_list.begin(); i != monster_list.end(); i++)
		{
			if ((*it)->is_firing() == false && (sqrt((((*it)->return_position().x - (*i)->return_position().x) * ((*it)->return_position().x - (*i)->return_position().x)) + (((*it)->return_position().y - (*i)->return_position().y) * ((*it)->return_position().y - (*i)->return_position().y)))) < (*it)->return_range())
				(*it)->fire((*i));
		}
	}
}

bool Level::wave_manager()
{
	if (no_waves == 3)
	{
		no_waves = 2;
		counter = 6000;
		return false;
	}
	else if (no_waves == 2)
	{
		no_waves = 1;
		counter = 8000;
		return false;
	}
	else if (no_waves == 1)
	{
		no_waves = 0;
		counter = 12000;
		return false;
	}
	else if (no_waves == 0 && monster_list.empty())
	{
		return true;
	}
	return false;
}
