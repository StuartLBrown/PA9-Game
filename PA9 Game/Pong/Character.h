#include <SFML\Graphics.hpp>
//base class for all the characters that will be in the game, including the enemies and player
//https://sonarlearning.co.uk/questions.php?question-topic=630 - sample code for working with collisions
using sf::Vector2f;
class Character abstract : public sf::RectangleShape {
private:
	sf::Sprite sprite;
	//collission box for the object, is for right now just the size of the sprite
	sf::FloatRect boundingBox;
public:
	Character(Vector2f pos, Vector2f size, sf::Sprite sprite) : sf::RectangleShape(size) {
		this->setPosition(pos);
		this->sprite = sprite;
		boundingBox = sprite.getGlobalBounds();
	}

	//update should update the character's position and draw the necessary animation 
	virtual void update() = 0;

	sf::FloatRect getBoundingBox() { return boundingBox; }
};