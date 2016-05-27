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

	//States for buttons/events
	bool isAPressed = false;
	bool isAReleased = false;
	bool isEnterReleased = false;
	bool spaceKey = false;
	bool leftClick = false;
	bool rightClick = false;
	bool leftArrow = false;
	bool rightArrow = false;

	//Variables
	int numberOfClicks = 0;
	int mouseX = 0, mouseY = 0;

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

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			{
				isEnterReleased = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				spaceKey = true;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				spaceKey = false;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				rightArrow = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				leftArrow = true;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
			{
				rightArrow = false;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
			{
				leftArrow = false;
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				leftClick = true;
			}

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				rightClick = true;
			}

			if (event.type == sf::Event::MouseMoved)
			{
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
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

		if (leftArrow && rightArrow)
		{
			std::cout << "Right and Left are Down";
		}

		if (leftClick)
		{
			numberOfClicks++;

			std::cout << "Number of clcks is " << numberOfClicks << "\n";

			if (mouseX < 200)
			{
				play = false;
			}

			leftClick = false;
		}

		if (rightClick)
		{
			numberOfClicks--;

			std::cout << "Number of clcks is " << numberOfClicks << "\n";

			rightClick = false;
		}

		if (isEnterReleased)
		{
			std::cout << "Enter has been released";

			isEnterReleased = false;
		}

		//std::cout << "Mouse x: " << mouseX << " Mouse y: " << mouseY << "\n";

		//RENDERING
		window.clear();

		window.display();
	}

	//Clean Up
	window.close();

	return 0;
}