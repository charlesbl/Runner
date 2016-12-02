#include "gameelement.h"
#include <iostream>

GameElement::GameElement(float x, float y, float width, float height, float vitx, float vity, ElementType type)
    :MovableElement(x,y,width,height)
    ,m_type{type}
{
    m_velocity = std::pair<float,float> {vitx,vity};
}

GameElement::~GameElement()
{

}

void GameElement::update()
{
    //Temps depuis la dernière mis à jour de la position
    Clock::duration elapsed_time{Clock::now() - m_last_update_time};

    //Calcul de la distance à parcourir en fonction de la vitesse
    float dx = m_velocity.first*(elapsed_time.count())/1000000000;
    float dy = m_velocity.second*(elapsed_time.count())/1000000000;

    //Modification de la position
    m_pos.first += dx;
    m_pos.second += dy;

    m_last_update_time = Clock::now();
}

ElementType GameElement::getType() const
{
    return m_type;
}
