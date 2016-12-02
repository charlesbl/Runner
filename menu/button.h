#ifndef BUTTON_H
#define BUTTON_H

#include "graphics/graphicelement.h"
#include <string>

/*!
 * \class Button
 * \brief Classe représentant un bouton, util pour la création de menus.
 */
class Button
{
private:
    bool /*!\brief La souris est-elle sur le bouton ?*/ m_focused
         /*!\brief L'utilisateur a-t-il cliqué sur le bouton ?*/,m_clicked;

    /*!\brief Dimensions.*/
    sf::Vector2f m_size;
    /*!\brief Sprite du bouton.*/
    GraphicElement m_sprite;
    /*!\brief Texte du bouton.*/
    sf::Text m_text;

    /*!\brief Rectangle de lecture par défaut de m_sprite.*/
    sf::IntRect m_textureRect;
    /*!\brief Rectangle de lecture lorsque le bouton a le focus de la souris.*/
    sf::IntRect m_textureRectWhenFocused;

public:
    /*!
     * \brief Constructeur
     * \param image : texture contenant les images du bouton
     * \param pos : Position
     * \param size : Taille
     * \param text : Texte
     */
    Button(sf::Texture &image, sf::Vector2f pos, sf::Vector2f size, sf::Text text);

    /*!
     * \brief Affichage
     * \param window : Fenetre sur laquelle dessiner
     */
    void draw(sf::RenderWindow *window);

    void setTextureRect(const sf::IntRect r);
    void setTextureRectWhenFocused(const sf::IntRect r);

    bool isFocused() const;
    void setFocused(bool focused);
    bool isClicked() const;
    void setClicked(bool clicked);

    sf::IntRect getGlobalBounds() const;
};

#endif // BUTTON_H
