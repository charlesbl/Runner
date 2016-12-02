#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "view/view.h"
#include "view/playerview.h"
#include "view/movablesview.h"
#include "graphics/slidingbackground.h"
#include "SFML/Audio.hpp"

/*!
 * \class GameView
 * \brief Classe permettant l'affichage du Model
 */
class GameView : public View
{
private:    

    /*!\brief On délègue la gestion de l'affichage du Player à une PlayerView*/
    PlayerView m_playerView;
    /*!\brief On délègue la gestion de l'affichage des autres MovableElement à une MovablesView*/
    MovablesView m_movablesView;

    /*!\brief Text de l'écran de fin de jeu*/
    sf::Text m_gameOverText;
    sf::Text m_pressEnterText;
    sf::Text m_finishScoreText;

    sf::Texture m_backgroundTexture1;
    SlidingBackground *m_background1;
    sf::Texture m_backgroundTexture2;
    SlidingBackground *m_background2;

    sf::Music m_music;

    const std::string FIRST_BACKGROUND_IMAGE = "Images/city_2.png";
    const std::string SECOND_BACKGROUND_IMAGE = "Images/city_1.png";
    const std::string GAMEOVER_IMAGE = "Images/test.png";

    const std::string MUSIC = "sound/Late_Night_Snack.ogg";

public:
    GameView(sf::RenderWindow* window, Model * model);
    ~GameView();
    void draw();
    bool treatEvents();
    void synchronize();

};

#endif // GAMEVIEW_H
