#ifndef ANIMATEDGRAPHICELEMENT_H
#define ANIMATEDGRAPHICELEMENT_H

#include "graphicelement.h"
#include <vector>
#include "animation.h"

/*!
 * \class AnimatedGraphicElement
 * \brief Classe permettant l'affichage de sprites animés
 */
class AnimatedGraphicElement : public GraphicElement
{
protected:

    /*!\brief Animations */
    std::vector<Animation> m_animations;

    /*!\brief Animation courante à utiliser pour l'affichage*/
    unsigned int m_current_animation,
    /*!\brief Etape de l'animation courante*/
    m_current_animation_step,
    /*!\brief Rectangle de lecture de l'animation courante*/
    m_current_animation_rect;

    /*!\brief L'animation est-elle activée ?*/
    bool m_runAnimation;

public:
    /*!
     * \brief Constructeur
     * \param animations : vector contenant les animations
     * \param image : Texture à utiliser
     * \param pos : Position
     * \param size : Taille
     */
    AnimatedGraphicElement(std::vector<Animation> animations, sf::Texture &image, sf::Vector2f pos, sf::Vector2f size);

    /*!
     * \brief Affichage
     * \param window : Fenêtre sur laquelle dessiner.
     */
    void draw(sf::RenderWindow *window) override;

    void setCurrentAnimation(unsigned int i);
    void setRunAnimation(bool runAnimation);

};

#endif // ANIMATEDGRAPHICELEMENT_H
