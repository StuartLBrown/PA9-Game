#pragma once
#include <SFML/Graphics.hpp>
#include "testmain.h"

int main()
{
	///*
	//starting sample code
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Texture texture;
	texture.loadFromFile("mario.png");
	sf::Sprite sprite(texture);
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
		window.display();
	}
	//*/
	//test();
	
	return 0;
	
}