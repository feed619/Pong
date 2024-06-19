#ifndef _BUTTON_
#define _BUTTON_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include <stack>
#include <map>

class Button
{
private:
	;
	// position of the button
	sf::Vector2f vec_poz;
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
	// Constructor and destructor
	Button(sf::Vector2f vector_poz, const std::string &image);
	~Button() = default;

	// getters
	sf::Image getImage() { return this->image_shell; }
	sf::Texture getTexture() { return this->texture_shell; }
	sf::Sprite getSprite() { return this->sprite_shell; }

	sf::Vector2f getPosition() { return this->vec_poz; }
	sf::Vector2u getSize() { return this->vector_size_button; }

	// setters

	void setTexture(const sf::Image &image) { this->texture_shell.loadFromImage(image); }
	void setPosition(sf::Vector2f vector)
	{
		this->sprite_shell.setPosition(vector);
		this->vec_poz = vector;
	}
};

#endif