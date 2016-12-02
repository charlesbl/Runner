#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <SFML/Graphics.hpp>
#include <string>
#include "graphicelement.h"

const std::string SPLASHSCREEN = "Images/splashscreen.png";
const int TIME = 2000;

class Splashscreen
{
private:
    sf::Texture m_splashscreenT;
    GraphicElement *m_splashscreen;
    sf::Clock m_clock;
public:
    Splashscreen(sf::Vector2f size);
    ~Splashscreen();
    bool draw(sf::RenderWindow *m_window);
};

#endif // SPLASHSCREEN_H
