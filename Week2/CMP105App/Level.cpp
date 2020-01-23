#include "Level.h"


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	oldmousepos.x = 0;
	oldmousepos.y = 0;
	oldmouseposdown.x = 0;
	oldmouseposdown.y = 0;
	oldmouseposup.x = 0;
	oldmouseposup.y = 0;
	
	// Circle
	circle.setRadius(25);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading text from file\n";
	}
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	drag = false;
	rclick = false;
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
		//std::cout << "Mouse: " << input->getMouseX() << ", " << input->getMouseY() << "\n";
	}

	if (input->isMouseLDown() && drag == false)
	{
		oldmouseposdown.x = input->getMouseX();
		oldmouseposdown.y = input->getMouseY();
		drag = true;
	}
	
	if (!input->isMouseLDown() && drag == true)
	{
		oldmouseposup.x = input->getMouseX();
		oldmouseposup.y = input->getMouseY();
		drag = false;
	}

	distance.x = oldmouseposup.x - oldmouseposdown.x;
	distance.y = oldmouseposup.y - oldmouseposdown.y;
	std::cout << distance.x << ", " << distance.y << "\n";

	if (input->isMouseRDown())
	{
		rclick = true;
	}

}

// Update game objects
void Level::update()
{
	oldmousepos.x = input->getMouseX();
	oldmousepos.y = input->getMouseY();
	
	//std::string mouse = "Mouse: " + std::to_string(input->getMouseX()) + ", " + std::to_string(input->getMouseY());
	//text.setString(mouse);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	
	if (rclick == true)
	{
		circle.setPosition(input->getMouseX(), input->getMouseY());
		rclick = false;
	}
	window->draw(circle);
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