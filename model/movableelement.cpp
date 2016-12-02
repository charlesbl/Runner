#include "movableelement.h"
#include <iostream>

MovableElement::MovableElement(float x, float y, float width, float height)
    :m_pos{x,y}
    ,m_size{width,height}
    ,m_velocity{0,0}
    ,m_last_update_time{Clock::now()}
{}

MovableElement::~MovableElement()
{

}

bool MovableElement::collision(const MovableElement *me) const
{

    return !(m_pos.first + m_size.first <= me->m_pos.first
             || m_pos.first >= me->m_pos.first + me->m_size.first
             || m_pos.second + m_size.second<= me->m_pos.second
             || m_pos.second >= me->m_pos.second + me->m_size.second);
}

void MovableElement::setX(int x)
{
    m_pos.first = x;
}
void MovableElement::setY(int y)
{
    m_pos.second = y;
}
std::pair<float, float> MovableElement::getPos() const
{
    return m_pos;
}

void MovableElement::setWidth(int width)
{
    m_size.first = width;
}
void MovableElement::setHeight(int height)
{
    m_size.second = height;
}

std::pair<float, float> MovableElement::getSize() const
{
    return m_size;
}

void MovableElement::setDx(int dx)
{
    m_velocity.first = dx;
}
void MovableElement::setDy(int dy)
{
    m_velocity.second = dy;
}
std::pair<float, float> MovableElement::getVelocity() const
{
    return m_velocity;
}


