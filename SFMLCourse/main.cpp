//Libraries
#include <SFML/Graphics.hpp>
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

	bool isAPressed = false;
	bool isAReleased = false;

	bool spaceKey = false;

	//Game loop
	while (play)
	{
		//EVENTS

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				isAPressed = true;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A)
			{
				isAReleased = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				spaceKey = true;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				spaceKey = false;
			}

			if (event.type == sf::Event::Closed)
			{
				//Stop the game
				play = false;
			}
		}
		
		//LOGIC
		if (isAPressed)
		{
			std::cout << "The A key has been pressed\n";

			isAPressed = false;
		}

		if (isAReleased)
		{
			std::cout << "The A key has been released\n";

			isAReleased = false;
		}

		if (spaceKey)
		{
			std::cout << "SPACE\n";
		}

		if (spaceKey == false)
		{
			std::cout << "NOT SPACE\n";
		}

		//RENDERING
		window.clear();

		window.display();
	}

	//Clean Up
	window.close();

	return 0;
}