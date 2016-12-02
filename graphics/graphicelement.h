#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H
#include <SFML/Graphics.hpp>

/*!
 * \class GraphicElement.
 * \brief Permet de représenter des sprites à l'écran.
 */
class GraphicElement : public sf::Sprite
{
protected:
    sf::Vector2f m_size;
public:

    GraphicElement(sf::Texture &image, sf::Vector2f pos, sf::Vector2f size);
    virtual void draw(sf::RenderWindow* window);
    void resize(sf::Vector2f newsize);
    void setTextureRect(const sf::IntRect &r);
};

#endif // GRAPHICELEMENT_H
