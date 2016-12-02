#ifndef MOVABLEELEMENT_H
#define MOVABLEELEMENT_H

#include <utility>
#include "utils/clock.h"

/*!
 * \class MovableElement
 * \brief Classe permettant de représenter tous les objets qui se déplace sur l'écran.
 */
class MovableElement
{
protected:
    std::pair<float,float> /*!\brief Position en pixel.*/ m_pos,
        /*!\brief Taille en pixel.*/ m_size,
        /*!\brief Vitesse en pixel/seconde.*/ m_velocity;

    /*!\brief Dernière fois que la position de l'élément a été mis à jour.*/
    Clock::time_point m_last_update_time;

public:
    /*!
     * \brief Constructeur
     * \param x : position en abscisse
     * \param y : position en ordonnée
     * \param width : largeur
     * \param height : hauteur
     */
    MovableElement(float x, float y, float width, float height);
    virtual~MovableElement();

    /*!
     * \brief Mise à jour du MovableElement
     */
    virtual void update() = 0;

    /*!
     * \brief Test de collision
     * \param me : MovableElement avec lequel tester la collision.
     * \return true si il y a collision, false sinon.
     */
    bool collision(const MovableElement *me) const;

    void setX(int x);
    void setY(int y);
    std::pair<float, float> getPos() const;

    void setWidth(int width);
    void setHeight(int height);
    std::pair<float, float> getSize() const;

    void setDx(int dx);
    void setDy(int dy);
    std::pair<float, float> getVelocity() const;

};

#endif // MOVABLEELEMENT_H
