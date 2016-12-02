#include "menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow* window)
    :m_window{window}
{
    //Chargement des textures
    if(!m_background.loadFromFile(BACKGROUND_MENU_IMAGE)){
        std::cerr << "Unable to open file : " << BACKGROUND_MENU_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }
    m_backgroundSprite = new GraphicElement{m_background,
                sf::Vector2f {0,0},
                (sf::Vector2f) m_window->getSize()};

    if(!m_button_texture.loadFromFile(BUTTON_IMAGE)){
        std::cerr << "Unable to open file : " << BUTTON_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }

    if(!m_font.loadFromFile(FONT_PATH)){
        std::cerr << "Unable to open file : " << FONT_PATH << std::endl;
        exit(EXIT_FAILURE);
    }

    //Création des boutons
    sf::Text text;
    text.setFont(m_font);

    text.setString("Play");

    m_playBtn = new Button{m_button_texture,sf::Vector2f{50,50},sf::Vector2f{300,150},text};

    text.setString("Quit");
    m_exitBtn = new Button{m_button_texture,sf::Vector2f{50,200},sf::Vector2f{300,150},text};

    m_playBtn->setTextureRect({0,0,32,16});
    m_playBtn->setTextureRectWhenFocused({32,0,32,16});

    m_exitBtn->setTextureRect({0,0,32,16});
    m_exitBtn->setTextureRectWhenFocused({32,0,32,16});

    //Initialisation de l'affichage des boutons
    m_textBestScore.setFont(m_font);
    m_textBestScore.setString(getStringScores());
    m_textBestScore.setCharacterSize(22);
    m_textBestScore.setColor(sf::Color {230,230,230});
    m_textBestScore.setPosition(600,10);
}

Menu::~Menu()
{
    if(m_backgroundSprite != NULL)
        delete m_backgroundSprite;

    delete m_playBtn;
    delete m_exitBtn;
}

bool Menu::update()
{

    bool result = false;
    if(m_window->isOpen())
    {
        result = true;

        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {

                m_window->close();
                result = false;
            }

            sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);

            m_playBtn->setFocused(m_playBtn->getGlobalBounds().contains(mousePos));
            m_playBtn->setClicked(m_playBtn->isFocused() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));

            m_exitBtn->setFocused(m_exitBtn->getGlobalBounds().contains(mousePos));
            m_exitBtn->setClicked(m_exitBtn->isFocused() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));
        }
    }

    return result;
}

void Menu::draw() const
{
    m_window->clear(sf::Color::White);
    m_backgroundSprite->draw(m_window);

    m_playBtn->draw(m_window);
    m_exitBtn->draw(m_window);

    m_window->draw(m_textBestScore);
    m_window->display();
}

Button *Menu::playBtn() const
{
    return m_playBtn;
}

Button *Menu::exitBtn() const
{
    return m_exitBtn;
}
