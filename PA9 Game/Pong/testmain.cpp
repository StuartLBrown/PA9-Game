#include "testmain.h"

void test(void)
{
	//starting sample code
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Texture texture;
	texture.loadFromFile("mario.png");
	sf::Sprite sprite(texture);
	//texture.loadFromFile("Assets/mario.png");
	sf::IntRect hitBox(100, 100, 100, 100);
	//Mario mario(texture, hitBox, 50.f, 50.f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		//window.draw(mario);
		window.draw(sprite);
		window.display();
	}

}