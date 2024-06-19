#ifndef _START_CALC_
#define _START_CALC_

#include "../pakage/init.hpp"
#include "../pakage/interface/Interface.cpp"
#include "../pakage/button/Button.cpp"
#include "../pakage/Ball/Ball.cpp"
#include "../pakage/Square/Square.cpp"

class Source
{
private:
    Interface interface;
    // sf::RenderWindow *window;
    sf::Vector2f mou_poz;

    int width = 1300;
    int height = 800;
    int fps = 60;

    float dX = 0;
    float dY = 0;
    float angle_of_direction_to_ball;
    float angle_degrees;
    float angle_degrees_full;
    float AY;
    float BX;

    sf::Font font;
    sf::Text *text;

    // Ball *ball;
    Button *side;

    std::string string_Text = "0";

    bool active = false;
    bool CLICK = false;
    bool Pressclick = false;

    void updateMousePosition();
    void AnimationUpdate();
    void Contact_with_edge();
    void Contact();
    void MoveBall();

    void FunctionOfButton(const int &index);

public:
    bool a = true;
    sf::RenderWindow *window;
    sf::Vector2f last_position;
    float spead_square = 0;
    float angle_last_angle = 0;
    float angle_last_angle_full = 0;

    Square *square;
    Ball *ball;

    void Contact_with_ball();
    void Angle_Sq_Ball();
    void Ball_with_edge();

    Source();
    ~Source();

    void update(sf::Event &event);
    void draw(sf::Event &event);

    int getWidth() { return this->width; }
    int getHeight() { return this->height; }
    sf::Vector2f getMousePosition() { return this->mou_poz; }
    void start();
};

#endif