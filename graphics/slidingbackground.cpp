#include "slidingbackground.h"



SlidingBackground::SlidingBackground(sf::Texture &image, sf::Vector2f size, float speed)
    :m_left{image, sf::Vector2f {0,0}, size}
    ,m_right{image, sf::Vector2f {size.x, 0}, size}
    ,m_size{size}
    ,m_speed{speed}
    ,m_last_update_time{Clock::now()}
{}

void SlidingBackground::draw(sf::RenderWindow * window)
{
    if(m_left.getPosition().x <= -m_size.x){
        m_left.setPosition(0,0);
        m_right.setPosition(m_size.x,0);
    }

    //Temps depuis la dernière mis à jour de la position
    Clock::duration elapsed_time{Clock::now() - m_last_update_time};

    //Calcul de la distance à parcourir en fonction de la vitesse
    float dx = m_speed*(elapsed_time.count())/1000000000;

    //Modification de la position
    m_left.setPosition(m_left.getPosition().x - dx, m_left.getPosition().y);
    m_right.setPosition(m_right.getPosition().x - dx, m_right.getPosition().y);

    m_last_update_time = Clock::now();

    window->draw(m_left);
    window->draw(m_right);
}

void SlidingBackground::setSpeed(float speed)
{
    m_speed = speed;
}

