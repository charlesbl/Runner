#include "animation.h"

Animation::Animation(std::vector<sf::IntRect> clips_rects, unsigned int nb_steps)
    :m_clips_rects{clips_rects}
    ,m_nb_steps{nb_steps}
{}

unsigned int Animation::getNbSteps() const
{
    return m_nb_steps;
}

unsigned int Animation::getNbClips() const
{
    return m_clips_rects.size();
}

sf::IntRect Animation::getClipRect(unsigned int i) const
{
    return m_clips_rects[i];
}
