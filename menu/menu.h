#ifndef MENU_H
#define MENU_H

#include "button.h"
#include "utils/score.h"
#include <vector>
#include <map>
#include <string>

/*!
 * \class Menu
 * \brief Classe représentant le menu principal
 */
class Menu
{
private:
    sf::RenderWindow *m_window;
    sf::Texture m_background;

    GraphicElement *m_backgroundSprite;

    sf::Texture m_button_texture;

    Button* m_playBtn;
    Button* m_exitBtn;

    sf::Font m_font;

    sf::Text m_textBestScore;

public:
    const std::string BACKGROUND_MENU_IMAGE = "Images/background_menu.png";
    const std::string BUTTON_IMAGE = "Images/buttons.png";
    const std::string FONT_PATH = "Fonts/font.TTF";

    Menu(sf::RenderWindow* window);
    ~Menu();

    bool update();
    void draw() const;

    void setButtonCliked(std::string buttonName, bool isCliked);
    Button *playBtn() const;
    Button *exitBtn() const;
};

#endif // MENU_H
