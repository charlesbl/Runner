#include "graphicelement.h"
#include <iostream>

GraphicElement::GraphicElement(sf::Texture &image, sf::Vector2f pos, sf::Vector2f size)
    :Sprite::Sprite{image},m_size{size}
{
    setPosition(pos);
    resize(size);
}

void GraphicElement::draw(sf::RenderWindow *window)
{
    window->draw(*this);
}

void GraphicElement::resize(sf::Vector2f newsize)
{
    m_size = newsize;

    sf::FloatRect bb = getGlobalBounds();
    float width_factor = newsize.x / bb.width;
    float height_factor = newsize.y / bb.height;
    scale(width_factor, height_factor);
}

void GraphicElement::setTextureRect(const sf::IntRect &r)
{
    sf::Sprite::setTextureRect(r);
    resize(m_size);
}

