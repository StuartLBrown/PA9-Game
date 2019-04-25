#include "SFML\Graphics.hpp"
#pragma once
#include <time.h>
#include <list>
#include <iostream>
#include "Mario.h"
#include <chrono>
#include <math.h>


using sf::Vector2f;
using std::cout;
using sf::Texture;
using sf::RectangleShape;
bool checkCollissionMouse(Vector2f &mPosition, RectangleShape &btn);
void printVector(const Vector2f &v);
class Game {
private:
	//temporary until we decide on what a player object will be named and more flushed out
	//Character player;
	//probably will need a map of some kind as well, not sure what we are going to with that yet

	//const floor height, defines the height in pixels that the floor will be from the bottom of the screen
	const int FLOOR_HEIGHT = 200;
	bool inMenu = true;
	bool inHelp = false;

public:
	Game();
	void populate(std::list<sf::RectangleShape>& objects, float x, float y);
};

Game::Game() {
	//starting sample code

	//starting the application in fullscreen
	sf::RenderWindow window(sf::VideoMode(1000,1000), "Mario");

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
	sf::RectangleShape background2(Vector2f(3000, 1000));
	background2.setTexture(t);
	background2.setPosition(Vector2f(0, -1000));
	sf::RectangleShape background3(Vector2f(3000, 1000));
	background3.setTexture(t);
	background3.setPosition(Vector2f(3000, 0));
	sf::RectangleShape background4(Vector2f(3000, 1000));
	background4.setTexture(t);
	background4.setPosition(Vector2f(3000, -1000));

	sf::Texture *menuT = new sf::Texture();
	sf::Texture *startT = new sf::Texture();
	sf::Texture *helpT = new sf::Texture();
	sf::Texture *exitT = new sf::Texture();
	sf::Texture *helpMT = new sf::Texture();
	sf::Texture *backT = new sf::Texture();

	menuT->loadFromFile("blankStart.png");
	startT->loadFromFile("startbtn.png");
	helpT->loadFromFile("helpbtn.png");
	exitT->loadFromFile("exitbtn.png");
	helpMT->loadFromFile("helpScrn.png");
	backT->loadFromFile("backbtn.png");

	sf::RectangleShape menu(Vector2f(window.getSize().x,window.getSize().y));
	menu.setTexture(menuT);
	menu.setPosition(Vector2f(0, 0));
	sf::RectangleShape startBtn(Vector2f(startT->getSize().x, startT->getSize().y));
	startBtn.setTexture(startT);
	startBtn.setPosition(Vector2f(340, 340));
	sf::RectangleShape helpBtn(Vector2f(helpT->getSize().x, helpT->getSize().y));
	helpBtn.setTexture(helpT);
	helpBtn.setPosition(Vector2f(200, 561));
	sf::RectangleShape exitBtn(Vector2f(exitT->getSize().x, exitT->getSize().y));
	exitBtn.setTexture(exitT);
	exitBtn.setPosition(Vector2f(370, 770));
	sf::RectangleShape helpMenu(Vector2f(helpMT->getSize().x,helpMT->getSize().y));
	helpMenu.setTexture(helpMT);
	helpMenu.setPosition(Vector2f(0, 0));
	sf::RectangleShape backBtn(Vector2f(backT->getSize().x, backT->getSize().y));
	backBtn.setTexture(backT);
	backBtn.setPosition(Vector2f(800, 900));

	//end pole
	Texture *endT = new Texture();
	endT->loadFromFile("endPole.png");
	RectangleShape endPole((Vector2f)endT->getSize());
	endPole.setPosition(Vector2f(5200, window.getSize().y-endPole.getSize().y-FLOOR_HEIGHT/2-142));
	endPole.setTexture(endT);

	// Ground/floor shape initialization and customization
	sf::RectangleShape floor(Vector2f(6000, FLOOR_HEIGHT));
	floor.setFillColor(sf::Color(30, 255, 30, 255));
	floor.setOutlineColor(sf::Color::Black);
	floor.setOutlineThickness(-3);
	floor.setPosition(Vector2f(0, 955 - FLOOR_HEIGHT)); // this Y position is just what worked, idk why it 

	//the "camera" - use setCenter(vector) to set the position of the camera
	sf::View camera(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

	while (window.isOpen())
	{
		if (inMenu) {
			window.clear();
			window.draw(menu);
			window.draw(startBtn);
			window.draw(exitBtn);
			window.draw(helpBtn);
			window.display();
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				Vector2f mPosition = (Vector2f)sf::Mouse::getPosition(window);
				if (checkCollissionMouse(mPosition, startBtn))
					inMenu = false;
				else if (checkCollissionMouse(mPosition, exitBtn))
					window.close();
				else if (checkCollissionMouse(mPosition, helpBtn)) {
					inMenu = false;
					inHelp = true;
				}
			}
		}
		else if (inHelp) {
			window.clear();
			window.draw(helpMenu);
			window.draw(backBtn);
			window.display();
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				Vector2f mPosition = (Vector2f)sf::Mouse::getPosition(window);
				if (checkCollissionMouse(mPosition, backBtn)) {
					inHelp = false;
					inMenu = true;
				}
			}
		}
		else {
			sf::Event event;
			while (window.pollEvent(event)) {
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::D) {
						if (mario->getVelocityY() == 0)
							animationNum = 4;
						mario->setVelocityX(.5);
						mario->setAccelerationX(0);
					}
					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					if (event.key.code == sf::Keyboard::A) {
						if (camera.getCenter().x - mario->getPosition().x <= camera.getSize().x / 2 + 50) {
							if (mario->getVelocityY() == 0)
								animationNum = 5;
							mario->setVelocityX(-.5);
							mario->setAccelerationX(0);
							//cout << "Moving left" << std::endl;
						}
					}
					if (event.key.code == sf::Keyboard::Space&&mario->getPosition().y >= 0 && mario->getPosition().y == 500) {
						mario->setVelocityY(-.5);
						animationNum = 10;
						if (mario->getPosition().y == 500)
						{
							mario->setVelocityY(-2);
							mario->setAccelerationY(.5);
						}
					}
					break;
				case sf::Event::KeyReleased:
					if (animationNum == 4) {
						animationNum = 0;
					}
					if (animationNum == 5) {
						animationNum = 1;
					}
					mario->setAccelerationX(mario->getVelocityX() / 7.5*-1);
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
			if (std::round(mario->getVelocityX() * 10) != 0)
				mario->setVelocityX(mario->getVelocityX() + mario->getAccelerationX());
			if (mario->getVelocityX() <= .1&&mario->getVelocityX() >= -.1) {
				mario->setVelocityX(0);
				mario->setAccelerationX(0);
			}
			if (mario->getVelocityX() >= 0)
				mario->move(mario->getVelocityX(), mario->getVelocityY());
			else {
				if (mario->getVelocityX() < 0 && camera.getCenter().x - mario->getPosition().x <= camera.getSize().x / 2 + 50)
					mario->move(mario->getVelocityX(), mario->getVelocityY());
			}
			time2 = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = time2 - time;
			int timer = (int)(elapsed_seconds.count() * 100);
			if (timer % 15 == 0)
				mario->Animate(animationNum);
			if (timer % 45 == 0) {
				if (mario->getPosition().y < 500)
					mario->adjustVelocity();
			}
			if (mario->getPosition().y > 500) {
				mario->setPosition(mario->getPosition().x, 500);
				mario->setAccelerationY(0);
				mario->setVelocityY(0);
				animationNum = 1;
			}
			window.clear();

			window.setView(camera);

			window.draw(background);
			window.draw(background2);
			window.draw(background3);
			window.draw(background4);
			window.draw(endPole);
			window.draw(*mario);
			window.draw(floor);

			window.display();
		}
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

bool checkCollissionMouse(Vector2f &mPosition, RectangleShape &btn) {
	float x = mPosition.x, y = mPosition.y;
	if (x >= btn.getPosition().x&&x <= btn.getPosition().x + btn.getSize().x&&y >= btn.getPosition().y&&y <= btn.getPosition().y + btn.getSize().y)
		return true;
	return false;
}

//information function, should only be used for testing purposes
void printVector(const Vector2f &v) { cout << "X Position: " << v.x << " | Y Position: " << v.y << std::endl; }