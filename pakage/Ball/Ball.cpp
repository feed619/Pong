#include "Ball.hpp"

Ball::Ball(sf::Vector2f vector_poz, const std::string &image, const float radius)
{

    this->Radius = radius;

    this->vec_poz = vector_poz;
    this->center_position = vector_poz + sf::Vector2f(radius, radius);
    this->image_shell.loadFromFile(image);
    this->vector_size_button = image_shell.getSize();
    this->texture_shell.loadFromImage(this->image_shell);
    this->sprite_shell.setTexture(this->texture_shell);

    this->sprite_shell.setPosition(vector_poz);

    this->Square = this->Radius * this->Radius * 3.1415926535;
}

void Ball::setTexture(const std::string &texture)
{
    sf::Image im;
    im.loadFromFile(texture);
    this->texture_shell.loadFromImage(im);
    this->sprite_shell.setTexture(this->texture_shell);
}
void Ball::setVector_poz(sf::Vector2f vector)
{
    this->vec_poz = vector;
    this->sprite_shell.setPosition(vector);
    this->center_position = this->vec_poz+ sf::Vector2f(this->Radius, this->Radius);
}
