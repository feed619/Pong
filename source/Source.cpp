#include "Source.hpp"
#include <iostream>
Source::Source()
{

    window = new sf::RenderWindow(sf::VideoMode(this->width, this->height), "Game", sf::Style::Titlebar | sf::Style::Close);

    window->setFramerateLimit(this->fps);

    this->square = new Square(sf::Vector2f(200, 400 - 150 / 2), "image/square_black.png", 75, 20);
    this->side = new Button(sf::Vector2f(0, 0), "image/sides.png");
    this->ball = new Ball(sf::Vector2f(1300 / 2 - 20, 800 / 2 - 20), "image/ball_green.png", 20);

    this->font.loadFromFile("font/qwe.ttf");
    this->text = new sf::Text(this->string_Text, this->font);
    this->text->setCharacterSize(25);
    this->text->setStyle(sf::Text::Italic);
    this->text->setFillColor(sf::Color::Black);
    this->text->setPosition(sf::Vector2f(40 + 43, 54 + 38));
}
////////////////////////////////////////////////////////////////
Source::~Source()
{
    delete this->square;
    delete this->side;
    delete this->ball;
    delete this->text;
    delete this->window;
}

////////////////////////////////////////////////////////////////
void Source::update(sf::Event &event)
{
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window->close();
    }
    Source::updateMousePosition();
    Source::AnimationUpdate();

    Source::Contact_with_edge();
    // Source::Angle_Sq_Ball();
    // Source::Contact_with_ball();

    Source::MoveBall();
    Source::Ball_with_edge();

    float xb = cosf(this->angle_degrees * 3.14159265 / 180);
    float yb = sinf(this->angle_degrees * 3.14159265 / 180);
    // this->text->setString("a= " + std::to_string(this->angle_degrees * 3.14159265 / 180) + "x= " + std::to_string(xb) + "y= " + std::to_string(yb));
    // this->text->setString("a= " + std::to_string(this->angle_last_angle) + "x= " + std::to_string(xb) + "y= " + std::to_string(yb));

    // this->text->setString("a= " + std::to_string(this->ball->getCenterPosition().y) + "x= " + std::to_string(this->square->getCenterPosition().y - 75) + "y= " + std::to_string(this->angle_degrees));
    // this->text->setString("angle_degrees= " + std::to_string(this->angle_degrees) + "\nangle_degrees_full= " + std::to_string(this->angle_degrees_full) +
    //                       "\nangle_last_angle= " + std::to_string(this->angle_last_angle) +
    //                       "\nball_angle= " + std::to_string(this->ball->Angle));
    // if (this->ball->getPosition().x > 1200)
    // {
    //     // this->ball->setVector_poz(sf::Vector2f(1300 / 2 - 20 - 300, 400 / 2 - 20));
    //     this->ball->setVector_poz(sf::Vector2f(1300 / 2 - 20, 800 / 2 - 20));

    //     this->ball->velocity = 0;
    // }
    // this->text->setString(std::to_string(mou_poz.x) + ' ' + std::to_string(mou_poz.y));
    // if (this->spead_square > 0)

    // arr->setRotation(ro);
    // this->text->setString(std::to_string(this->angle_degrees));
    // this->text->setString(std::to_string(this->ball->getPosition().x) + ' ' + std::to_string(this->ball->getPosition().y));
}
////////////////////////////////////////////////////////////////
void Source::draw(sf::Event &event)
{
    this->window->clear();

    this->window->draw(interface.getSprite());
    this->window->draw(this->side->getSprite());
    this->window->draw(this->ball->getSprite());
    this->window->draw(this->square->getSprite());

    this->window->draw(*this->text);

    this->window->display();
}
////////////////////////////////////////////////////////////////
void Source::Angle_Sq_Ball()
{
    this->AY = this->square->getCenterPosition().y - this->ball->getCenterPosition().y;
    this->BX = this->square->getCenterPosition().x - this->ball->getCenterPosition().x;

    this->angle_of_direction_to_ball = atan2f(abs(this->AY), abs(this->BX));

    this->angle_degrees = this->angle_of_direction_to_ball * 180 / 3.14159265358979323846;

    if (this->BX >= 0)
    {
        if (this->AY >= 0)
        {
            this->angle_degrees_full = 90 + (90 - this->angle_degrees);
        }
        else
        {
            this->angle_degrees_full = this->angle_degrees + 180;
        }
    }
    else
    {
        if (this->AY >= 0)
        {
            this->angle_degrees_full = this->angle_degrees;
        }
        else
        {
            this->angle_degrees_full = 270 + (90 - this->angle_degrees);
        }
    }
}
////////////////////////////////////////////////////////////////
void Source::updateMousePosition()
{
    this->mou_poz.x = sf::Mouse::getPosition().x - this->window->getPosition().x;
    this->mou_poz.y = sf::Mouse::getPosition().y - this->window->getPosition().y - 26;
}
////////////////////////////////////////////////////////////////
void Source::AnimationUpdate()
{
    if (!this->active)
    {
        if (this->square->getSprite().getGlobalBounds().contains(mou_poz) and (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
        {
            this->active = true;
            this->window->setMouseCursorVisible(false);
        }
    }
    else
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            this->active = false;
            this->window->setMouseCursorVisible(true);
        }
    }
}

////////////////////////////////////////////////////////////////
void Source::Contact_with_edge()
{
    // this->text->setString(std::to_string(this->square->getSprite().getPosition().x) + ' ' + std::to_string(this->square->getSprite().getPosition().y));

    if (this->active)
    {
        if (mou_poz.x - 30 < 0)
        {
            if (mou_poz.y < 85)
            {
                this->square->setPosition(sf::Vector2f(10, 10));
            }
            else if (mou_poz.y > 715)
            {
                this->square->setPosition(sf::Vector2f(10, 640));
            }
            else
                this->square->setPosition(sf::Vector2f(10, mou_poz.y - 75));
        }
        else if (mou_poz.x > 1250)
        {

            if (mou_poz.y < 85)
            {
                this->square->setPosition(sf::Vector2f(1250, 10));
            }
            else if (mou_poz.y > 715)
            {
                this->square->setPosition(sf::Vector2f(1250, 640));
            }
            else
                this->square->setPosition(sf::Vector2f(1250, mou_poz.y - 75));
        }
        else if (mou_poz.y < 85)
        {
            this->square->setPosition(sf::Vector2f(mou_poz.x - 20, 10));
        }
        else if (mou_poz.y > 715)
        {
            this->square->setPosition(sf::Vector2f(mou_poz.x - 20, 640));
        }
        else
            this->square->setPosition(mou_poz - sf::Vector2f(20, 75));
    }

    // side->getSprite().getGlobalBounds(vector_buttons[0]->getSprite().getPosition())
}
////////////////////////////////////////////////////////////////
void Source::Contact_with_ball()
{
    Source::Angle_Sq_Ball();
    // if (this->square->getPosition().x <= this->ball->getPosition().x and this->ball->getPosition().x <= this->square->getPosition().x + 40)
    // {
    //     if (this->square->getPosition().y <= this->ball->getPosition().y and this->ball->getPosition().y <= this->square->getPosition().y + 150)
    //     {
    //         this->text->setString(std::to_string(this->angle_of_direction_to_ball));
    //         // this->text->setString(std::to_string(this->square->getPosition().x) + " " + std::to_string(this->ball->getPosition().x));
    //     }
    // }

    // this->text->setString(std::to_string(this->angle_degrees_full));

    // this->text->setString(std::to_string(this->BX) + " " + std::to_string(this->AY) + " " + std::to_string(this->angle_degrees));
    // this->text->setString(std::to_string(this->BX) + " " + std::to_string(this->AY));

    this->text->setString("ball_velocity= " + std::to_string(this->ball->velocity) + "\nangle_degrees_full= " + std::to_string(this->angle_degrees_full) +
                          "\nangle_last_angle= " + std::to_string(this->angle_last_angle) + "\nball_angle_full= " + std::to_string(this->ball->Angle_full));

    if (this->angle_degrees_full < 61.93 or this->angle_degrees_full > 298.07)
    {
        if ((this->ball->getCenterPosition().x - ball->getRadius() <= this->square->getCenterPosition().x + 20))
        {

            this->ball->setVector_poz(sf::Vector2f(this->square->getCenterPosition().x + 21,
                                                   this->ball->getPosition().y));
            this->ball->velocity = this->ball->velocity + 1.1 * this->spead_square;

            // this->ball->Angle = this->angle_degrees;
            // this->ball->Angle = this->angle_degrees_full;
            // this->ball->Angle = this->angle_last_angle * 0.4;

            this->ball->Angle_full = this->angle_last_angle_full;
            // this->text->setString("angle_degrees= " + std::to_string(this->angle_degrees) + "\nangle_degrees_full= " + std::to_string(this->angle_degrees_full) +
            //                       "\nangle_last_angle= " + std::to_string(this->angle_last_angle));
        }
    }
    else if (118.07 < this->angle_degrees_full < 241.93)
    // if (this->angle_degrees < 61.93)

    {
        if ((this->ball->getCenterPosition().x + 20 >= this->square->getCenterPosition().x - 20))
        {
            if ((this->ball->getCenterPosition().y >= this->square->getCenterPosition().y - 75) and (this->ball->getCenterPosition().y <= this->square->getCenterPosition().y + 75))
            {
                this->ball->setVector_poz(sf::Vector2f(this->ball->getCenterPosition().x - 21,
                                                       this->ball->getPosition().y));

                this->ball->velocity = this->ball->velocity + 1.1 * this->spead_square;

                // this->ball->Angle = this->angle_degrees;
                // this->ball->Angle = this->angle_degrees;

                this->ball->Angle_full = this->angle_last_angle_full;

                // this->ball->Angle = this->angle_degrees_full;
                // this->ball->Angle = this->angle_last_angle;
            }
        }
    }
}

////////////////////////////////////////////////////////////////

void Source::MoveBall()
{
    if (this->ball->velocity > 0)
    {
        float xb = cosf(this->ball->Angle_full * 3.14159265 / 180);
        float yb = sinf(this->ball->Angle_full * 3.14159265 / 180);
        this->text->setString("Angle_full = " + std::to_string(xb) + ' ' + "\nAngle_ball_full = " + std::to_string(yb));

        this->ball->setVector_poz(sf::Vector2f(this->ball->getPosition().x + xb * this->ball->velocity, this->ball->getPosition().y - yb * this->ball->velocity));

        // if ((this->ball->Angle_full < 90) || ((this->ball->Angle_full > 270) && (this->ball->Angle_full < 360)))
        // {

        //     // this->ball->setVector_poz(sf::Vector2f(this->ball->getPosition().x - xb * this->ball->velocity, this->ball->getPosition().y - yb * this->ball->velocity));

        //     this->ball->setVector_poz(sf::Vector2f(this->ball->getPosition().x + xb * this->ball->velocity, this->ball->getPosition().y + yb * this->ball->velocity));
        //     // this->ball->setVector_poz(sf::Vector2f(this->ball->getPosition().x + xb, this->ball->getPosition().y + yb));
        // }
        // else if (this->ball->Angle_full >= 90 and this->ball->Angle_full < 270)
        // {
        //     // this->ball->setVector_poz(sf::Vector2f(this->ball->getPosition().x + xb * this->ball->velocity, this->ball->getPosition().y + yb * this->ball->velocity));
        //     // this->text->setString("xb = " + std::to_string(xb) + ' ' + "yb = " + std::to_string(yb));
        //     // this->ball->setVector_poz(sf::Vector2f(this->ball->getPosition().x - 0.6 * this->ball->velocity, this->ball->getPosition().y - 0.2 * this->ball->velocity));

        //     this->ball->setVector_poz(sf::Vector2f(this->ball->getPosition().x + xb * this->ball->velocity, this->ball->getPosition().y + yb * this->ball->velocity));
        // }

        this->ball->velocity -= 0.2;
        if (this->ball->velocity < 0.3)
        {
            this->ball->velocity = 0;
            this->ball->Angle_full = 0;
        }
        // if (this->ball->getPosition().x > 1200)
        // {
        //     // this->ball->setVector_poz(sf::Vector2f(1300 / 2 - 20 - 300, 400 / 2 - 20));
        //     this->ball->setVector_poz(sf::Vector2f(50, 50));
        //     this->ball->velocity = 0;
        // }
    }
}
////////////////////////////////////////////////////////////////
void Source::Ball_with_edge()
{
    if (this->ball->getCenterPosition().x + 20 >= 1300)
    {
        if (this->ball->Angle_full > 270)

            this->ball->Angle_full = this->ball->Angle_full - 180;
        else
            this->ball->Angle_full = this->ball->Angle_full + 180;
    }
    else if (this->ball->getCenterPosition().x - 20 <= 0)
    {
        if ((this->ball->Angle_full > 90) and (this->ball->Angle_full < 180))
            this->ball->Angle_full = this->ball->Angle_full + 180;
        else
            this->ball->Angle_full = this->ball->Angle_full - 180;
    }
    if (this->ball->getPosition().y > 800)
    {
        this->ball->Angle_full += 180;
    }
    else if (this->ball->getPosition().y < 0)
    {
    }
    // std::this_thread::sleep_for(std::chrono::microseconds(2000));
    // this->ball->velocity = 2;
}
////////////////////////////////////////////////////////////////

void Source::FunctionOfButton(const int &index)
{
    switch (index)
    {
    case 0:
    {

        break;
    }
    case 1:
    {

        break;
    }
    case 2:
    {

        break;
    }
    case 3:
    {

        break;
    }
    case 4:
    {

        break;
    }
    case 5:
    {

        break;
    }
    case 6:
    {

        break;
    }
    case 7:
    {
        break;
    }
    case 8:
    {

        break;
    }
    }
}
////////////////////////////////////////////////////////////////
void Source::start()
{

    while (this->window->isOpen())
    {
        sf::Event event;
        update(event);
        Source::draw(event);
    }
}
////////////////////////////////////////////////////////////////