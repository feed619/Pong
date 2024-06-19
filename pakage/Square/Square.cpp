#include "Square.hpp"

Square::Square(sf::Vector2f vector_poz, const std::string &image, uint16_t Max, uint16_t Min)
{

    this->vec_poz = vector_poz;
    this->Max_radius = Max;
    this->Min_radius = Min;

    this->center_position = vector_poz + sf::Vector2f(Min, Max);
    this->image_shell.loadFromFile(image);

    this->vector_size_button = image_shell.getSize();

    this->texture_shell.loadFromImage(this->image_shell);

    this->sprite_shell.setTexture(this->texture_shell);

    this->sprite_shell.setPosition(vector_poz);
}
