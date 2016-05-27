//Libraries
#include <SFML/Graphics.hpp>
#include <iostream>

//Global Variables, functions and classes

int main()
{
	//Creation
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");
	window.setFramerateLimit(60);

	bool play = true;
	sf::Event event;

	//Game loop
	while (play)
	{
		//EVENTS

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				std::cout << "The A key has been pressed\n";
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A)
			{
				std::cout << "The A key has been released\n";
			}

			if (event.type == sf::Event::Closed)
			{
				play = false;
			}
		}
		
		//LOGIC


		//RENDERING
		window.clear();

		window.display();
	}

	//Clean Up
	window.close();

	return 0;
}