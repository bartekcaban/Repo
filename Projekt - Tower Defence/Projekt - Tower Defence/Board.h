#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Tower.h"
#include "Tower1.h"
#include "Tower2.h"
#include "Player.h"
using namespace sf;

enum Tower_type
{
	tower1,
	tower2
};

class Board
{
	Texture texture;
	Sprite sprite;
	Texture route_texture;
	Sprite route_sprite;
	//miejsca na wie¿e
	Texture place_texture;
	Sprite place[25];
	Tower_type tower_type;//zapisuje, któr¹ wie¿e nale¿y postawiæ
	bool occupied_places[25];//tablica, dziêki której nie bêd¹ pokazywane zajête miejsca
public:
	Board();
	void display(RenderWindow * window);
	void display_places(RenderWindow * window);
	bool place_click(Vector2i pos);
	Tower * set_tower(Vector2i pos, Player * player); 
	void change_tower_type(bool type);
};
