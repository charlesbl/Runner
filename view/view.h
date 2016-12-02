#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include "model/model.h"

class View
{
protected:
    sf::RenderWindow* m_window;
    Model * m_model;

    sf::Font m_font;

    const std::string FONT_PATH = "Fonts/font.TTF";
public:
    View(sf::RenderWindow *window, Model *model);
    virtual void synchronize() = 0;
};

#endif // VIEW_H
