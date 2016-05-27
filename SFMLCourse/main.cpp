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

	//Game loop
	while (play)
	{
		//EVENTS
		sf::Event event;
		while (window.pollEvent(event))
		{

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