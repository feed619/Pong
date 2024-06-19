#ifndef _SQUARE_
#define _SQUARE_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include <stack>
#include <map>

class Square
{
private:
	;
	// position of the button
	sf::Vector2f vec_poz;
	sf::Vector2f center_position;
	// size of the button
	sf::Vector2u vector_size_button;

	// sf atributes
	sf::Image image_shell;
	sf::Texture texture_shell;
	sf::Sprite sprite_shell;

	sf::Image image_shadow;
	sf::Texture texture_shadow;
	sf::Sprite sprite_shadow;

	sf::Image image_click;
	sf::Texture texture_click;
	sf::Sprite sprite_click;

public:
	sf::Text *text;
	// bool value
	bool Enabled = true;
	bool TextPut = false;
	bool BTN_ACTIVE = false;
	bool BTN_WAIT = true;
	uint16_t Max_radius;
	uint16_t Min_radius;
	float velocity = 0;
	float weight;
	float rotation = 0;

	// Constructor and destructor
	Square(sf::Vector2f vector_poz, const std::string &image, uint16_t Max, uint16_t Min);
	~Square() = default;

	// getters
	sf::Image getImage() { return this->image_shell; }
	sf::Texture getTexture() { return this->texture_shell; }
	sf::Sprite getSprite() { return this->sprite_shell; }

	sf::Vector2f getPosition() { return this->vec_poz; }
	sf::Vector2f getCenterPosition() { return this->center_position; }
	sf::Vector2u getSize() { return this->vector_size_button; }

	// setters

	void setTexture(const sf::Image &image) { this->texture_shell.loadFromImage(image); }
	void setPosition(sf::Vector2f vector)
	{
		this->sprite_shell.setPosition(vector);
		this->vec_poz = vector;
		this->center_position = this->vec_poz + sf::Vector2f(this->Min_radius, this->Max_radius);
	}
};

#endif