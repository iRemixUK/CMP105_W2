#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here
	sf::Vector2i oldmousepos;
	sf::Vector2i oldmouseposdown;
	sf::Vector2i oldmouseposup;
	sf::Vector2i distance;

	sf::CircleShape circle;
	sf::Font font;
	sf::Text text;
	sf::Event event;
	bool drag;
	bool rclick;
};