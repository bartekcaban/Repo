#include <iostream>
#include <SFML\Graphics.hpp>
#include "Menu.h"
using namespace sf;

Menu::Menu()
{
	//³adowanie obrazów do spritów i ustawianie ich pozycji
	texture.loadFromFile("Board/menu.png");
	sprite.setTexture(texture);
	pause_texture.loadFromFile("Board/pause.png");
	pause_sprite.setTexture(pause_texture);
	sprite.setPosition(1350, 0);
	pause_sprite.setPosition(1365, 20);
	tower1_texture.loadFromFile("Tower/tower1.png");
	tower1_sprite.setTexture(tower1_texture);
	tower1_sprite.setPosition(1360, 120);
	tower2_texture.loadFromFile("Tower/tower2.png");
	tower2_sprite.setTexture(tower2_texture);
	tower2_sprite.setPosition(1360, 280);
	coins_texture.loadFromFile("Board/coins.png");
	coins_sprite.setTexture(coins_texture);
	coins_sprite.setPosition(1370, 600);
	hp_texture.loadFromFile("Board/hp.png");
	hp_sprite.setTexture(hp_texture);
	hp_sprite.setPosition(1370, 700);

}

void Menu::display(RenderWindow * window)
{
	window->draw(sprite);
	window->draw(pause_sprite);
	window->draw(tower1_sprite);
	window->draw(tower2_sprite);
	window->draw(coins_sprite);
	window->draw(hp_sprite);
}

bool Menu::tower1_click(Vector2i pos)
{
	if (tower1_sprite.getGlobalBounds().contains(pos.x, pos.y))
		return true;
	else
		return false;
}

bool Menu::tower2_click(Vector2i pos)
{
	if (tower2_sprite.getGlobalBounds().contains(pos.x, pos.y))
		return true;
	else
		return false;
}

bool Menu::pause_click(Vector2i pos)
{
	if (pause_sprite.getGlobalBounds().contains(pos.x, pos.y))
		return true;
	else
		return false;
}