#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Grass : public sf::Sprite {
public:
	Grass(const sf::Texture &texture);
	~Grass();
private:
	sf::Rect<float> boundaries;
	sf::Texture texture;
};
