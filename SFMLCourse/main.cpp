//Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

//Global Variables, functions and classes

int main()
{
	//Creation
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
	window.setFramerateLimit(60);

	//Stop events from being repeatedly sent on key down
	window.setKeyRepeatEnabled(false);

	bool play = true;
	sf::Event event;

	//Font
	sf::Font font;
	if (font.loadFromFile("Data/arial.ttf") == 0)
	{
		return 1;
	}

	//States
	bool rButton = false;
	bool leftButton = false, rightButton = false, upButton = false, downButton = false;

	//Variables
	int rectRotation = 0;
	int xVelocity = 0, yVelocity = 0;

	//Shapes
	sf::RectangleShape shape1;
	shape1.setSize(sf::Vector2f(50, 50));
	shape1.setPosition(400, 300);

	//Game loop
	while (play)
	{
		//EVENTS

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				//Stop the game
				play = false;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
			{
				rButton = true;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R)
			{
				rButton = false;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
					leftButton = true;
				if (event.key.code == sf::Keyboard::Right)
					rightButton = true;
				if (event.key.code == sf::Keyboard::Up)
					upButton = true;
				if (event.key.code == sf::Keyboard::Down)
					downButton = true;
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
					leftButton = false;
				if (event.key.code == sf::Keyboard::Right)
					rightButton = false;
				if (event.key.code == sf::Keyboard::Up)
					upButton = false;
				if (event.key.code == sf::Keyboard::Down)
					downButton = false;
			}
		}


		//LOGIC
		if (rButton)
		{
			rectRotation++;
			shape1.setRotation(rectRotation);
		}

		//Velocity
		//Xaxis
		if (rightButton)
			xVelocity = 5;

		if (leftButton)
			xVelocity = -5;

		if (leftButton && rightButton)
			xVelocity = 0;
		
		if (!leftButton && !rightButton)
			xVelocity = 0;

		//YAxis
		if (upButton)
			yVelocity = -5;
		
		if (downButton)
			yVelocity = 5;

		if (upButton && downButton)
			yVelocity = 0;

		if (!upButton && !downButton)
			yVelocity = 0;

		//Move
		shape1.move(xVelocity, yVelocity);

		//Collision

		//RENDERING
		window.clear();

		window.draw(shape1);

		window.display();
	}

	//Clean Up
	window.close();

	return 0;
}