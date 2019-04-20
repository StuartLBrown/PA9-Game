#include "SFML\Graphics.hpp"
#pragma once
#include <time.h>
#include <list>
#include <iostream>
#include "Mario.h"
#include <chrono>


using sf::Vector2f;
using std::cout;

void printVector(const Vector2f &v);
class Game {
private:
	//temporary until we decide on what a player object will be named and more flushed out
	//Character player;
	//probably will need a map of some kind as well, not sure what we are going to with that yet

	//const floor height, defines the height in pixels that the floor will be from the bottom of the screen
	const int FLOOR_HEIGHT = 200;

public:
	Game();
	void populate(std::list<sf::RectangleShape>& objects, float x, float y);
};

Game::Game() {
	//starting sample code

	//starting the application in fullscreen
	sf::RenderWindow window(sf::VideoMode(1000,1000), "SFML works!");

	std::chrono::time_point<std::chrono::system_clock> time, time2;
	time = std::chrono::system_clock::now();
	sf::Texture texture;
	int animationNum = 0;
	texture.loadFromFile("mario.png");
	Mario *mario = new Mario(texture);

	sf::Texture *t = new sf::Texture();
	t->loadFromFile("background.png");
	sf::RectangleShape background(Vector2f(3000, 1000));
	background.setTexture(t);
	background.setPosition(Vector2f(0, 0));

	//the "camera" - use setCenter(vector) to set the position of the camera
	sf::View camera(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::D) {
					animationNum = 4;
					mario->setVelocityX(1);
				}
				if (event.key.code == sf::Keyboard::A&&camera.getCenter().x - mario->getPosition().x <= camera.getSize().x / 2) {
					animationNum = 5;
					mario->setVelocityX(-1);
				}
				if (event.key.code == sf::Keyboard::Space&&mario->getPosition().y >= 0) {
					mario->setVelocityY(-8);
					animationNum = 10;
					if (mario->getPosition().y == 500)
					{
						mario->setVelocityY(-3);
						mario->setAccelerationY(1);
					}
				}
				break;
			case sf::Event::KeyReleased:
				if (animationNum == 4) {
					mario->setVelocityX(0);
					animationNum = 0;
				}
				if (animationNum == 5) {
					mario->setVelocityX(0);
					animationNum = 1;
				}
				break;
			}
		}

		if (mario->getVelocityX() > 0) {
			if (mario->getPosition().x >= camera.getCenter().x)
				camera.setCenter(mario->getPosition());
		}
		if (mario->getVelocityY() > 0) {
			camera.setCenter(camera.getCenter().x, mario->getPosition().y);
			if (mario->getPosition().y >= window.getSize().y) {
				mario->setVelocityY(-8);
			}
		}
		if (mario->getVelocityY() < 0) {
			camera.setCenter(camera.getCenter().x, mario->getPosition().y);
			if (mario->getPosition().y <= FLOOR_HEIGHT) {
				mario->setVelocityY(0);
				mario->move(Vector2f(0, FLOOR_HEIGHT - mario->getPosition().y));
			}
		}
		mario->move(mario->getVelocityX(), mario->getVelocityY());
		time2 = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = time2 - time;
		int timer = (int)(elapsed_seconds.count() * 100);
		printVector(mario->getPosition());
		if (timer % 15 == 0)
			mario->Animate(animationNum);
		if (timer % 45 == 0){
			if (mario->getPosition().y < 500)
				mario->adjustVelocity();
		}
		if (mario->getPosition().y > 500){
			mario->setPosition(mario->getPosition().x, 500);
			mario->setAccelerationY(0);
			mario->setVelocityY(0);
			animationNum = 1;
		}
		window.clear();

		window.setView(camera);

		window.draw(background);
		window.draw(*mario);

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
void printVector(const Vector2f &v) { cout << "X Position: " << v.x << " | Y Position: " << v.y << std::endl; }