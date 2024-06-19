
#include "source/Source.cpp"
void speed_of_ball(Source *source)
{
    while (source->window->isOpen())
    {
        source->last_position = source->square->getCenterPosition();
        std::this_thread::sleep_for(std::chrono::milliseconds(30));

        source->spead_square = abs(sqrt(pow(source->last_position.x, 2) +
                                        pow(source->last_position.y, 2)) -
                                   sqrt(pow(source->square->getCenterPosition().x, 2) +
                                        pow(source->square->getCenterPosition().y, 2)));

        float AY = source->last_position.y - source->square->getCenterPosition().y;
        float BX = source->last_position.x - source->square->getCenterPosition().x;

        source->angle_last_angle = atan2f(abs(AY), abs(BX)) * 180 / 3.14159265358979323846;

        if (BX >= 0)
        {
            if (AY >= 0)
            {
                source->angle_last_angle_full = 90 + (90 - 0.5 * source->angle_last_angle);
                // source->angle_last_angle_full = 0.3 * source->angle_last_angle + 180;
            }
            else
            {
                source->angle_last_angle_full = 0.5 * source->angle_last_angle + 180;
                // source->angle_last_angle_full = 90 + (90 - source->angle_last_angle);
            }
        }
        else
        {
            if (AY >= 0)
            {
                source->angle_last_angle_full = 0.5 * source->angle_last_angle;
                // source->angle_last_angle_full = 270 + (90 - 0.3 * source->angle_last_angle);
            }
            else
            {
                source->angle_last_angle_full = 270 + (90 - 0.5 * source->angle_last_angle);
                // source->angle_last_angle_full = 0.3 * source->angle_last_angle;
            }
        }
        // source_->Contact_with_ball();
    }
}

void Contact_with_ball(Source *source)
{
    while (source->window->isOpen())
    {
        source->Contact_with_ball();
    }
}

int main()
{
    Source source;
    std::thread tr(speed_of_ball, &source);
    std::thread tr2(Contact_with_ball, &source);

    source.start();

    // while (source.window->isOpen())
    // {
    //     sf::Event event;
    //     source.update(event);
    //     source.draw(event);
    // }
    tr.join();
    tr2.join();

    return 0;
}