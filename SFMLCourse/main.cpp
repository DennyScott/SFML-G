//Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

//Global Variables, functions and classes

int main()
{

	const int WINDOWX = 800, WINDOWY = 600;
	//Creation
	sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "SFML Game");
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

	sf::Text score;
	score.setFont(font);
	score.setCharacterSize(30);
	score.setColor(sf::Color::Red);
	score.setPosition(WINDOWX/2 - 50, 10);
	score.setString("0 : 0");

	//Images
	sf::Texture texPad;
	sf::Texture texBall;
	sf::Texture texBackground;

	if (!texPad.loadFromFile("Data/pad.png"))
	{
		return -1;
	}

	if (!texBall.loadFromFile("Data/ball.png"))
	{
		return -1;
	}

	if (!texBackground.loadFromFile("Data/Background.png"))
	{
		return -1;
	}

	//Sounds
	sf::SoundBuffer bufHit;

	sf::Sound hit;
	hit.setBuffer(bufHit);

	if (!bufHit.loadFromFile("Data/hit.wav"))
	{
		return -1;
	}

	//States
	bool upKey = false;
	bool downKey = false;

	//Variables
	int yVelocityPad1 = 0;
	int xVelocityPad1 = 0;

	int yVelocityPad2 = 0;
	int xVelocityPad2 = 0;

	int xVelocityBall = -4;
	int yVelocityBall = -4;

	int pad1Score = 0;
	int pad2Score = 0;

	//Shapes
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(WINDOWX, WINDOWY));
	background.setPosition(0, 0);
	background.setTexture(&texBackground);

	sf::RectangleShape pad1;
	pad1.setSize(sf::Vector2f(50, 100));
	pad1.setPosition(50, 200);
	pad1.setTexture(&texPad);

	sf::RectangleShape pad2;
	pad2.setSize(sf::Vector2f(50, 100));
	pad2.setPosition(700, 200);
	pad2.setTexture(&texPad);

	sf::RectangleShape ball;
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(WINDOWX/2, WINDOWY/2);
	ball.setTexture(&texBall);

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

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Down)
					downKey = true;
				
				if (event.key.code == sf::Keyboard::Up)
					upKey = true;
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Down)
					downKey = false;

				if (event.key.code == sf::Keyboard::Up)
					upKey = false;
			}
		}


		//LOGIC
		if (upKey)
			yVelocityPad1 = -5;
		if (downKey)
			yVelocityPad1 = 5;
		if (downKey && upKey)
			yVelocityPad1 = 0;
		if (!downKey && !upKey)
			yVelocityPad1 = 0;



		//Movement
		pad1.move(0, yVelocityPad1);

		if (pad1.getPosition().y < 0)
			pad1.setPosition(sf::Vector2f(pad1.getPosition().x, 0));

		if (pad1.getPosition().y > WINDOWY - pad1.getSize().y)
			pad1.setPosition(sf::Vector2f(pad1.getPosition().x, WINDOWY - pad1.getSize().y));

		////PAD2
		if (ball.getPosition().y > pad2.getPosition().y)
		{
			yVelocityPad2 = 2;
		}

		if (ball.getPosition().y < pad2.getPosition().y)
		{
			yVelocityPad2 = -2;
		}

		pad2.move(0, yVelocityPad2);

		//Ball Logic
		ball.move(xVelocityBall, yVelocityBall);

		if (ball.getPosition().y < 0)
			yVelocityBall = -yVelocityBall;

		if (ball.getPosition().y > WINDOWY - ball.getSize().y)
			yVelocityBall = -yVelocityBall;

		if (ball.getGlobalBounds().intersects(pad1.getGlobalBounds()))
		{
			xVelocityBall = -xVelocityBall;
			hit.play();
		}

		if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()))
		{
			xVelocityBall = -xVelocityBall;
			hit.play();
		}

		if (ball.getPosition().x < -50)
		{
			pad2Score++;
			ball.setPosition(300, 200);
		}

		if (ball.getPosition().x > 800)
		{
			pad1Score++;
			ball.setPosition(300, 200);
		}

		//RENDERING
		window.clear();

		window.draw(background);
		window.draw(pad1);
		window.draw(pad2);

		window.draw(ball);

		//Score
		std::stringstream text;
		text << pad1Score << " : " << pad2Score;
		score.setString(text.str());
		window.draw(score);

		window.display();
	}

	//Clean Up
	window.close();

	return 0;
}