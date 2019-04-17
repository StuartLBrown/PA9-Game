//http://xoxlabs.com/x/unity/2D_Mario_Clone/2D%20Mario%20Clone/Assets/2D%20Mario%20Assets/Textures/
// This example will use SFML libraries to implement
// the game of Pong

// History: 4/12 - Designed a Paddle class. Have yet to 
//                 instantiate one of these.
//          4/10 - Designed and implemented a Ball class that's
//                 derived from a sf::CircleShape.
//          4/8 - Started from the SFML tutorial code that draws
//                a circle in the window.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include "Mario.h"

int main()
{
	std::chrono::time_point<std::chrono::system_clock> time, time2;
	time = std::chrono::system_clock::now();
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::Texture texture;
	int animationNum = 0;
	texture.loadFromFile("mario.png");
	Mario *mario = new Mario(texture);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::D)
				{
					animationNum = 4;
					mario->setVelocityX(8);
				}
				if (event.key.code == sf::Keyboard::A)
				{
					animationNum = 5;
					mario->setVelocityX(-8);
				}
				if (event.key.code == sf::Keyboard::Space && (animationNum == 4 || animationNum == 10))
				{
					animationNum = 10;
					mario->setVelocityY(-8);
				}
				if (event.key.code == sf::Keyboard::Space && (animationNum == 5 || animationNum == 11))
				{
					animationNum = 11;
					mario->setVelocityY(-8);
				}
				break;
			case sf::Event::KeyReleased:
				if (animationNum == 4)
				{
					mario->setVelocityX(0);
					animationNum = 0;
				}
				if (animationNum == 5)
				{
					mario->setVelocityX(0);
					animationNum = 1;
				}
				break;
			}
		}
		mario->move(mario->getVelocityX(), mario->getVelocityY());

		window.clear();
		time2 = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = time2 - time;
		int timer = (int)(elapsed_seconds.count() * 100);
		std::cout << elapsed_seconds.count() << std::endl;
		if (timer % 15 == 0)
			mario->Animate(animationNum);
		window.draw(*mario);
		window.display();
	}

	return 0;
}