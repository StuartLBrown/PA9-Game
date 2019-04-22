#include "testmain.h"

void test(void)
{
	std::chrono::time_point<std::chrono::system_clock> time, time2;
	time = std::chrono::system_clock::now();
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::Texture texture;
	int animationNum = 0;
	texture.loadFromFile("mario.png");
	Mario *mario = new Mario(texture);
	//sf::Rect<int> ground;
	//sf::Sprite sfk()
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
				if (event.key.code == sf::Keyboard::Space)// && (animationNum == 4 || animationNum == 10))
				{
					animationNum = 10;
					if (mario->getPosition().y == 500)
					{
						mario->setVelocityY(-3);
						mario->setAccelerationY(1);
					}
				}
				if (event.key.code == sf::Keyboard::Space)// && (animationNum == 5 || animationNum == 11))
				{
					animationNum = 11;
					if (mario->getPosition().y == 500)
					{
						mario->setVelocityY(-3);
						mario->setAccelerationY(1);
					}
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
		{
			mario->Animate(animationNum);		
		}
		if (timer % 45 == 0)
		{
			if (mario->getPosition().y < 500)
			{
				mario->adjustVelocity();
				//mario->setPosition(mario->getPosition().x, 500);
			}
		}
		if (mario->getPosition().y > 500)
		{
			mario->setPosition(mario->getPosition().x, 500);
			mario->setAccelerationY(0);
			mario->setVelocityY(0);
			animationNum = 1;
		}
		window.draw(*mario);
		window.display();
	}


}