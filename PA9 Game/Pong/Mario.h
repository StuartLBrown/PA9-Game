#pragma once
#include <SFML/Graphics.hpp>

class Mario : public sf::Sprite {
public:
	Mario(const sf::Texture texture, const sf::IntRect &Size, float speed, float jumpHeight);
private:
};