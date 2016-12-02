#include "button.h"
#include <iostream>

Button::Button(sf::Texture &image, sf::Vector2f pos, sf::Vector2f size, sf::Text text)
    :m_focused{false}
    ,m_clicked{false}
    ,m_size{size}
    ,m_sprite{image,pos,size}
    ,m_text{text}
    ,m_textureRect{0,0,0,0}
    ,m_textureRectWhenFocused{0,0,0,0}
{
    m_text.setCharacterSize(100);
    sf::FloatRect bb = m_text.getGlobalBounds();
    m_text.scale((size.x-60) /bb.width, (size.y - 100)/bb.height);
    m_text.setColor(sf::Color {200,200,200});

    bb = m_text.getGlobalBounds();
    float x = pos.x + 10 + (size.x - bb.width)/2;
    float y = pos.y + (size.y - bb.height)/3;

    m_text.setPosition(x,y);

}

void Button::draw(sf::RenderWindow *window)
{
    if(m_focused && m_sprite.getTextureRect() != m_textureRectWhenFocused)
        m_sprite.setTextureRect(m_textureRectWhenFocused);

    else if(!m_focused && m_sprite.getTextureRect() != m_textureRect)
        m_sprite.setTextureRect(m_textureRect);

    window->draw(m_sprite);

    window->draw(m_text);

}

void Button::setTextureRect(const sf::IntRect r)
{
    m_textureRect = r;
    if(m_textureRectWhenFocused == sf::IntRect {0,0,0,0})
        m_textureRectWhenFocused = r;
}

void Button::setTextureRectWhenFocused(const sf::IntRect r)
{
    m_textureRectWhenFocused = r;
    if(m_textureRect == sf::IntRect {0,0,0,0})
        m_textureRect = r;
}

bool Button::isFocused() const
{
    return m_focused;
}

void Button::setFocused(bool focused)
{
    m_focused = focused;
}
bool Button::isClicked() const
{
    return m_clicked;
}

void Button::setClicked(bool clicked)
{
    m_clicked = clicked;
}

sf::IntRect Button::getGlobalBounds() const
{
    return (sf::IntRect) m_sprite.getGlobalBounds();
}
