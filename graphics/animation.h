#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <SFML/Graphics.hpp>

/*!
 * \class Animation
 * \brief Classe permettant de représenter une animation au travers d'un enchaînement de rectangle de lecture de sprites.
 */
class Animation
{
private:
    /*!\brief Rectangles de lecture*/
    std::vector<sf::IntRect> m_clips_rects;
    unsigned int m_nb_steps,
                 m_current_step;
public:
    Animation(std::vector<sf::IntRect> clips_rects, unsigned int nb_steps);

    unsigned int getNbSteps() const;
    unsigned int getNbClips() const;
    sf::IntRect getClipRect(unsigned int i) const;
};

#endif // ANIMATION_H
