#ifndef SLIDINGBACKGROUND_H
#define SLIDINGBACKGROUND_H

#include "graphics/graphicelement.h"
#include "utils/clock.h"

/*!\class SlidingBackground
 * \brief Classe représentant un fond d'écran défilant
 */
class SlidingBackground
{
private:
    GraphicElement m_left,
                   m_right;

    sf::Vector2f m_size;
    float m_speed;

    Clock::time_point m_last_update_time;

public:
    SlidingBackground(sf::Texture & image, sf::Vector2f size, float speed);
    void draw(sf::RenderWindow * window);
    void setSpeed(float speed);
};

#endif // SLIDINGBACKGROUND_H
