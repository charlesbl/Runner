#include "playerview.h"
#include <iostream>
#include <stdlib.h>

PlayerView::PlayerView(sf::RenderWindow *window, Model *model)
    :View{window,model}
{

    m_lifeRectangle.setSize(sf::Vector2f {LIFE_MAX_WIDTH, 20});
    m_lifeRectangle.setOrigin(0,0);
    m_lifeRectangle.setPosition(window->getSize().x/2 - LIFE_MAX_WIDTH/2,20);
    m_lifeRectangle.setFillColor(sf::Color::Green);

    m_scoreText.setFont(m_font);
    m_scoreText.setString("");
    m_scoreText.setColor(sf::Color {200,200,200});
    m_scoreText.setPosition(0,0);

    //Chargementde la texture
    if(!m_playerTexture.loadFromFile(PLAYER_IMAGE)){
        std::cerr << "Unable to open file : " << PLAYER_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }

    //Création des animations
    std::vector<sf::IntRect> clips {{0,24,18,24},
                                    {18,24,18,24}};
    Animation walk{clips, 10};

    clips = {{0,0,18,24},
             {18,0,18,24},
             {36,0,18,24},
             {54,0,18,24}};
    Animation run{clips, 10};

    clips = {{0,48,18,24}};
    Animation jump{clips, 1};

    clips = {{0,72,24,18},{24,72,24,18}};
    Animation fly{clips, 10};

    m_animations_player.push_back(walk);
    m_animations_player.push_back(run);
    m_animations_player.push_back(jump);
    m_animations_player.push_back(fly);

    //Création du sprite
    m_playerSprite = new AnimatedGraphicElement{m_animations_player,
            m_playerTexture,
            sf::Vector2f {m_model->getPlayerPos().first, m_model->getPlayerPos().first},
            sf::Vector2f {m_model->getPlayerSize().first, m_model->getPlayerSize().second}};
}

PlayerView::~PlayerView()
{
    //Désallocations
    if(m_playerSprite != NULL)
        delete m_playerSprite;
}

void PlayerView::synchronize()
{

    //Mise à jour de la barre de vie
    m_lifeRectangle.setSize(sf::Vector2f {LIFE_MAX_WIDTH * ((float) m_model->getPlayerHealth())/((float) Player::MAX_HEALTH), 20});

    if(m_model->getPlayerHealth() <= 20)
        m_lifeRectangle.setFillColor(sf::Color::Red);
    else if(m_model->getPlayerHealth() <= 40)
        m_lifeRectangle.setFillColor(sf::Color::Yellow);
    else
        m_lifeRectangle.setFillColor(sf::Color::Green);


    m_scoreText.setString("Score: " + std::to_string(m_model->getPlayerScore()) );

    //Mise à jour de la position
    m_playerSprite->setPosition(m_model->getPlayerPos().first, m_model->getPlayerPos().second);
    m_playerSprite->resize(sf::Vector2f {m_model->getPlayerSize().first, m_model->getPlayerSize().second});

    if(m_model->isPlayerFlying())
        m_playerSprite->setCurrentAnimation(3);
    else if(m_model->isPlayerJumping())
        m_playerSprite->setCurrentAnimation(2);
    else if(!m_model->playerDirection())
        m_playerSprite->setCurrentAnimation(1);
    else
        m_playerSprite->setCurrentAnimation(0);

}

void PlayerView::draw() const
{
    sf::RectangleShape life;

    life.setSize(sf::Vector2f {LIFE_MAX_WIDTH, 20});
    life.setOrigin(0,0);
    life.setPosition(m_window->getSize().x/2 - LIFE_MAX_WIDTH/2,20);
    life.setOutlineColor(sf::Color::Black);
    life.setOutlineThickness(8);
    life.setFillColor(sf::Color::Transparent);

    m_window->draw(life);

    m_playerSprite->draw(m_window);

    m_window->draw(m_lifeRectangle);
    m_window->draw(m_scoreText);
}
