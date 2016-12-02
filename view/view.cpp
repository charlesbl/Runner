#include "view.h"
#include <iostream>

View::View(sf::RenderWindow *window, Model *model)
    :m_window{window}
    ,m_model{model}
{
    if(!m_font.loadFromFile(FONT_PATH)){
        std::cerr << "Unable to open file : " << FONT_PATH << std::endl;
        exit(EXIT_FAILURE);
    }
}
