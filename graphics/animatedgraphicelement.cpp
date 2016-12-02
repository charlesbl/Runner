#include "animatedgraphicelement.h"
#include <iostream>

AnimatedGraphicElement::AnimatedGraphicElement(std::vector<Animation> animations, sf::Texture &image, sf::Vector2f pos, sf::Vector2f size)
    : GraphicElement::GraphicElement{image, pos, size}
    ,m_animations{animations}
    ,m_current_animation{0}
    ,m_current_animation_step{0}
    ,m_current_animation_rect{0}
    ,m_runAnimation{true}
{
    setTextureRect(m_animations[m_current_animation].getClipRect(m_current_animation_step));
}

void AnimatedGraphicElement::draw(sf::RenderWindow *window)
{
    if(m_runAnimation){
        m_current_animation_step++;
        if(m_current_animation_step > m_animations.at(m_current_animation).getNbSteps()){
            m_current_animation_rect++;
            if(m_current_animation_rect >= m_animations.at(m_current_animation).getNbClips())
                m_current_animation_rect = 0;
            setTextureRect(m_animations.at(m_current_animation).getClipRect(m_current_animation_rect));
            m_current_animation_step = 0;
        }
    }
    window->draw(*this);
}

void AnimatedGraphicElement::setCurrentAnimation(unsigned int i)
{
    m_current_animation = i;
}

void AnimatedGraphicElement::setRunAnimation(bool runAnimation)
{
    m_runAnimation = runAnimation;
}
