#ifndef _BALL_
#define _BALL_
pr
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include <stack>
#include <map>

class Ball
{
private:
	// position of the button
	sf::Vector2f vec_poz;
	sf::Vector2f center_position;

	// size of the button
	sf::Vector2u vector_size_button;
	float Radius;
	double Square;

	// sf atributes
	sf::Image image_shell;
	sf::Texture texture_shell;
	sf::Sprite sprite_shell;

public:
	// bool value
	bool Enabled = true;
	bool TextPut = false;
	bool BTN_ACTIVE = false;
	bool BTN_WAIT = true;
	float velocity = 0;
	float Angle = 0;
	float Angle_full = 0;
	;
	float weight;
	float rotation = 0;
	float acceleration = 0;
	// Constructor and destructor
	Ball(sf::Vector2f vector_poz, const std::string &image, const float radius);
	~Ball() = default;

	// getters
	sf::Image getImage() { return this->image_shell; }
	sf::Texture getTexture() { return this->texture_shell; }
	sf::Sprite getSprite() { return this->sprite_shell; }

	sf::Vector2f getPosition() { return this->vec_poz; }
	sf::Vector2f getCenterPosition() { return this->center_position; }

	sf::Vector2u getSize() { return this->vector_size_button; }
	float getRadius() { return this->Radius; }
	double getSquare() { return this->Square; }

	// setters
	void setTexture(const std::string &texture);
	void setTexture(const sf::Image &image) { this->texture_shell.loadFromImage(image); }
	void setVector_poz(sf::Vector2f vector);
	void Move();
};

#endif