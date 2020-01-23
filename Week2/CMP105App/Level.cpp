#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	oldmousepos.x = 0;
	oldmousepos.y = 0;
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	// if W is pressed output to console
	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "J, K and L were pressed";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	
	if (oldmousepos.x != input->getMouseX() || oldmousepos.y != input->getMouseY())
	{
		std::cout << "Mouse: " << input->getMouseX() << ", " << input->getMouseY() << "\n";
	}
}

// Update game objects
void Level::update()
{
	oldmousepos.x = input->getMouseX();
	oldmousepos.y = input->getMouseY();

	std::string mouse = "Mouse: " + std::to_string(input->getMouseX()) + ", " + std::to_string(input->getMouseY());
	
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading text from file\n";
	}
	text.setFont(font);
	text.setString(mouse);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}