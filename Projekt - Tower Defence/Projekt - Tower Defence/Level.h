#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Tower.h"
#include "Monster.h"
#include "Monster1.h"
#include "Monster2.h"
#include "Player.h"
#include <list>
using namespace sf;

class Level
{
	//wykorzystuj¹c kontener biblioteki stl - list, zaimplementowano listy wie¿ i potworów
	std::list<Monster *> monster_list;
	std::list<Tower *> tower_list;
	int counter;
	int no_waves;
public:
	Level();
	void add_tower(Tower* new_tower);//funkcja dodaje wie¿ê do listy
	void display_towers(RenderWindow * window);//funkcja wyœwietla wie¿a
	void display_monsters(RenderWindow * window, Player * player);//funkcja wyswietla i usuwa potwory
	bool generate_monsters();//funkcja generuje i dodaje potwory do listy
	void tower_firing();//funkcja realizuj¹ca strzelanie wie¿
	bool wave_manager();//funkcja do zarz¹dzania falami potworów
};