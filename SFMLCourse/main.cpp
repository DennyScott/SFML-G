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
	int rectXPosition = 0;


	//Images
	sf::Texture image1;
	if (image1.loadFromFile("Data/image2.png") == 0)
	{
		return 1;
	}

	//Render shapes
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(100, 100));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::White);
	rect.setTexture(&image1);

	sf::CircleShape circle;
	circle.setRadius(50);
	circle.setPosition(400, 300);
	circle.setFillColor(sf::Color::Blue);

	//Font
	sf::Font font;
	if (font.loadFromFile("Data/arial.ttf") == 0)
	{
		return 1;
	}

	//Text
	sf::Text title;
	title.setFont(font);
	title.setCharacterSize(30);
	title.setString("Hello World!");
	title.setPosition(300, 50);
	title.setColor(sf::Color::Magenta);

	//Sounds
	sf::SoundBuffer explosionBuffer;
	if (explosionBuffer.loadFromFile("Data/explosion1.wav") == 0)
	{
		return -1;
	}

	sf::Sound explosion;
	explosion.setBuffer(explosionBuffer);
	explosion.setVolume(60);

	//Music
	sf::Music music;
	if (music.openFromFile("Data/music.ogg") == 0)
	{
		return 1;
	}

	music.setVolume(5);
	music.setLoop(true);
	music.play();

	//Game loop
	while (play)
	{
		//EVENTS

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				explosion.play();
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

		std::cout << "Mouse x: " << mouseX << " Mouse y: " << mouseY << "\n";

		rectXPosition++;
		rect.setPosition(rectXPosition, rectXPosition);

		//RENDERING
		window.clear();

		window.draw(rect);
		window.draw(circle);
		window.draw(title);

		window.display();
	}

	//Clean Up
	window.close();

	return 0;
}