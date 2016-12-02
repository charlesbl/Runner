#ifndef GAMEELEMENT_H
#define GAMEELEMENT_H

#include "model/movableelement.h"
#include "model/player.h"
/*!
 * \enum ElementType
 * \brief Enumération des différents types de GameElement.
 *
 * Cela permet la synchronisation avec les éléments de la vue sans faire de dynamic_cast.
 */
enum ElementType{Stand_type, Car_type, TrafficLight_type, Healer_type, Coin_type, Shield_Type, Wings_Type};

/*!
 * \class GameElement
 * \brief Classe représentant tous les obstacles, bonus ou autre objet qui pourront interagir avec le joueur.
 */
class GameElement : public MovableElement
{

private:
    ElementType m_type;/*!\brief Type de l'élément*/

public:

    /*!
     * \brief Constructeur
     * \param x : position en abscisse
     * \param y : position en ordonnée
     * \param width : largeur
     * \param height : hauteur
     * \param vitx : vitesse en abscisse
     * \param vity : vitesse en ordonnée
     * \param type : type de l'élément
     */
    GameElement(float x, float y, float width, float height, float vitx, float vity, ElementType type);
    virtual ~GameElement();

    void update() override;

    /*!
     * \brief Action à affectuer sur le joueur
     * \param p : pointeur vers l'instance de Player à affecter
     *
     * Définit l'action à effectuer sur le Player pointé par p.
     */
    virtual void affectPlayer(Player *p) const = 0;

    /*!
     * \brief Retourne l' ElementType du GameElement.
     */
    ElementType getType() const;

};

#endif // GAMEELEMENT_H
