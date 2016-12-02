#include "gameview.h"
#include <iostream>
#include <fstream>

GameView::GameView(sf::RenderWindow* window, Model * model)
    :View{window,model}
    ,m_playerView{window, model}
    ,m_movablesView{window,model}
{
    //Chargement des textures
    if(!m_backgroundTexture1.loadFromFile(FIRST_BACKGROUND_IMAGE)){
        std::cerr << "Unable to open file : " << FIRST_BACKGROUND_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }
    if(!m_backgroundTexture2.loadFromFile(SECOND_BACKGROUND_IMAGE)){
        std::cerr << "Unable to open file : " << SECOND_BACKGROUND_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }

    m_pressEnterText.setFont(m_font);
    m_pressEnterText.setString("Press Enter");
    m_pressEnterText.setColor(sf::Color {255,0,0});
    m_pressEnterText.setCharacterSize(30);
    sf::FloatRect bb = m_pressEnterText.getGlobalBounds();
    m_pressEnterText.setPosition(m_window->getSize().x/2 - bb.width/2, m_window->getSize().y/2 - bb.height/2 + 70);

    m_gameOverText.setFont(m_font);
    m_gameOverText.setString("Game Over");
    m_gameOverText.setColor(sf::Color {255,0,0});
    m_gameOverText.setCharacterSize(100);
    bb = m_gameOverText.getGlobalBounds();
    m_gameOverText.setPosition(m_window->getSize().x/2 - bb.width/2, m_window->getSize().y/2 - bb.height/2 - 30);

    m_finishScoreText.setFont(m_font);
    m_finishScoreText.setString("Your score: 0");
    m_finishScoreText.setColor(sf::Color {255,0,0});
    m_finishScoreText.setCharacterSize(30);
    bb = m_finishScoreText.getGlobalBounds();
    m_finishScoreText.setPosition(m_window->getSize().x/2 - bb.width/2, m_window->getSize().y/2 - bb.height/2 + 110);

    //Backgrounds
    m_background1 = new SlidingBackground{m_backgroundTexture1,
            (sf::Vector2f) m_window->getSize(),
            model->getSpeed()*3/4};

    m_background2 = new SlidingBackground{m_backgroundTexture2,
            sf::Vector2f {(float) m_window->getSize().x *2, (float) m_window->getSize().y},
            model->getSpeed()};

    if (!m_music.openFromFile(MUSIC))
        std::cerr << MUSIC << " not loaded" << std::endl;


    m_music.play();
    m_music.setLoop(true);


    synchronize();
}

GameView::~GameView()
{
    //Désallocations
    if(m_background1 != NULL)
        delete m_background1;

    if(m_background2 != NULL)
        delete m_background2;

}

void GameView::draw()
{
    m_window->clear(sf::Color {25,25,32});

    //Affichage des backgrounds
    m_background1->draw(m_window);
    m_background2->draw(m_window);

    if(m_model->getGameOver()){
        //Affichage GameOver
        m_window->draw(m_gameOverText);
        m_window->draw(m_pressEnterText);
        m_finishScoreText.setString("Your Score: " + std::to_string(m_model->getPlayerScore()));
        m_window->draw(m_finishScoreText);
    }else{
        //Affichage des sprites des éléments
        m_movablesView.draw();

        //Affichage du joueur
        m_playerView.draw();
    }

    m_window->display();
}

bool GameView::treatEvents()
{
    //Boucle d'événements
    bool result = false;
    if(m_window->isOpen())
    {
        result = true;

        sf::Event event;
        while (m_window->pollEvent(event)) {

            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                result = false;
            }
        }

        //Gestion des contrôles du joueur
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            m_model->movePlayerRight();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            m_model->movePlayerLeft();
        }

        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            m_model->stopPlayer();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            m_model->jumpPlayer(true);
        }
        else{
            m_model->jumpPlayer(false);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && m_model->getGameOver()){
            result = false;
        }

    }
    return result;
}

void GameView::synchronize()
{
    if(m_model->getGameOver()){
        m_background1->setSpeed(0);
        m_background2->setSpeed(0);
    }

    //Synchronisation du joueur avec son sprite
    m_playerView.synchronize();

    //Synchronisation des movables avec leurs sprites
    m_movablesView.synchronize();


    m_background1->setSpeed(m_model->getSpeed()*3/4);
    m_background2->setSpeed(m_model->getSpeed());
}
































