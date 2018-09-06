#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
using namespace sf;

class Menu
{
	Texture texture;
	Sprite sprite;
	Texture pause_texture;
	Sprite pause_sprite;
	Texture tower1_texture;
	Sprite tower1_sprite;
	Texture tower2_texture;
	Sprite tower2_sprite;
	Texture hp_texture;
	Sprite hp_sprite;
	Texture coins_texture;
	Sprite coins_sprite;
public:
	Menu();
	void display(RenderWindow * window);
	bool pause_click(Vector2i pos);
	bool tower1_click(Vector2i pos);
	bool tower2_click(Vector2i pos);
};
