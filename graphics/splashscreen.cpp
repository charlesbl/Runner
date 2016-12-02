#include "splashscreen.h"
#include "iostream"

Splashscreen::Splashscreen(sf::Vector2f size)
{
    if(!m_splashscreenT.loadFromFile(SPLASHSCREEN)){
        std::cerr << "Unable to open file : " << SPLASHSCREEN << std::endl;
        exit(EXIT_FAILURE);
    }
    m_splashscreen = new GraphicElement{m_splashscreenT, sf::Vector2f{0, 0}, size};
}

Splashscreen::~Splashscreen()
{
    delete m_splashscreen;
}

bool Splashscreen::draw(sf::RenderWindow *m_window)
{
    m_window->clear(sf::Color::Black);
    m_splashscreen->setColor(sf::Color{255, 255, 255, (m_clock.getElapsedTime().asMilliseconds() * 1.f / TIME) * 255});
    m_splashscreen->draw(m_window);
    m_window->display();
    return (m_clock.getElapsedTime().asMilliseconds() <= TIME);
}
