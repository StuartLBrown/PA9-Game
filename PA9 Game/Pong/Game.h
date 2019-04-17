#include "Character.h"
#pragma once
#include <time.h>
#include <list>
#include <iostream>
using std::cout;
class Game {
private:
	//temporary until we decide on what a player object will be named and more flushed out
	//Character player;
	//probably will need a map of some kind as well, not sure what we are going to with that yet

public:
	Game();
	void populate(std::list<sf::RectangleShape>& objects, float x, float y);
};

Game::Game() {
	//starting sample code

	//starting the application in fullscreen
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML works!");

	//needs to be replaced with a character object
	sf::RectangleShape temp(Vector2f(20, 20));
	temp.setFillColor(sf::Color::Red);
	temp.setOrigin(10, 10);
	temp.setPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	//temporary for testing of camera mvmt
	std::list<sf::RectangleShape> objects;
	populate(objects, rand()%window.getSize().x, rand() % window.getSize().y);
	populate(objects, rand() % window.getSize().x, rand() % window.getSize().y);
	populate(objects, rand() % window.getSize().x, rand() % window.getSize().y);
	populate(objects, rand() % window.getSize().x, rand() % window.getSize().y);
	populate(objects, rand() % window.getSize().x, rand() % window.getSize().y);
	populate(objects, rand() % window.getSize().x, rand() % window.getSize().y);

	//the "camera" - use setCenter(vector) to set the position of the camera
	sf::View camera(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//handling player movement and restricting bounds to size of window and for left the left edge of the current screen
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && temp.getPosition().y >= 0) {
			temp.move(0, -.25);
			camera.setCenter(camera.getCenter().x,temp.getPosition().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && temp.getPosition().y <= window.getSize().y) {
			temp.move(0, .25);
			camera.setCenter(camera.getCenter().x,temp.getPosition().y);
		}
		//not setting the camera if left is pushed to emulate orginal super mario bros. camera (can't go left past the edge of the screen)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&camera.getCenter().x-temp.getPosition().x<=camera.getSize().x/2-50)
			temp.move(-.25, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			temp.move(.25, 0);
			//only setting the camera once the middle of the screen has been reached
			if(temp.getPosition().x>=camera.getCenter().x)
				camera.setCenter(temp.getPosition());
		}

		window.clear();

		window.setView(camera);

		//going through the list
		for (std::list<sf::RectangleShape>::const_iterator it = objects.begin(); it != objects.end(); ++it){
			window.draw(*it);
		}

		window.draw(temp);
		window.display();
	}

}

//could potentially be used to add objects to the window on the fly, or just setting up the entire game
void Game::populate(std::list<sf::RectangleShape>& objects, float x, float y)
{
	sf::RectangleShape s(sf::Vector2f(20, 20));
	s.setPosition(x, y);
	s.setFillColor(sf::Color::Green);
	objects.push_back(s);
}

//information function, should only be used for testing purposes
void printVector(Vector2f &v) { cout << "X Position: " << v.x << " | Y Position: " << v.y << std::endl; }