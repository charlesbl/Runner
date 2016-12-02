#include "model.h"
#include "iostream"
#include <time.h>

#include "model/healer.h"
#include "model/coin.h"
#include "model/stand.h"
#include "model/car.h"
#include "model/trafficlight.h"
#include "model/shield.h"
#include "model/wings.h"

void Model::addGameElement(GameElement *ge)
{
    auto it = m_elements.find(m_lastElementAdded);

    if(it != m_elements.end())
    {
        if(ge->collision(*it)){
            ge->setX((*it)->getPos().first + (*it)->getSize().first + 20);
        }
    }

    m_newElements.insert(ge);
    m_elements.insert(ge);
    m_lastElementAdded = ge;
}

void Model::eraseGameElement(GameElement *ge)
{
    m_oldElements.insert(ge);
    m_elements.erase(m_elements.find(ge));
}

void Model::spawnObstacle()
{
    m_time_to_spawn_an_obstacle += SPAWN_OBSTACLE_DELAY;

    switch (rand()%4) {
    case 0:
        addGameElement(new Stand{(float) m_size.first, GROUND_HEIGHT, -m_speed});
        break;
    case 1:
        addGameElement(new Car{(float) m_size.first, GROUND_HEIGHT, -m_speed});
        break;
    case 2:
        addGameElement(new TrafficLight{(float) m_size.first, rand()%200 + 150.f, -m_speed});
        break;
    }
}

void Model::spawnBonus()
{

    m_time_to_spawn_a_bonus += SPAWN_BONUS_DELAY;

    switch (rand()%4) {
    case 0:
        addGameElement(new Wings{(float) m_size.first, rand()%200 + 150.f, -m_speed});
        break;
    case 1:
        addGameElement(new Healer{(float) m_size.first, rand()%200 + 150.f, -m_speed});
        break;
    case 2:
        addGameElement(new Shield{(float) m_size.first, rand()%200 + 150.f, -m_speed});
        break;
    }
}

void Model::spawCoinSerie()
{

    m_time_to_spawn_a_coin += SPAWN_COIN_DELAY;

    addGameElement(new Coin{(float) m_size.first, GROUND_HEIGHT - 300, -m_speed});
    if(rand()%2 == 0){
        addGameElement(new Coin{(float) m_size.first + Coin::COIN_WIDTH, GROUND_HEIGHT - 300, -m_speed});
        if(rand()%2 == 0){
            addGameElement(new Coin{(float) m_size.first + 2*Coin::COIN_WIDTH, GROUND_HEIGHT - 300, -m_speed});
            if(rand()%2 == 0){
                addGameElement(new Coin{(float) m_size.first + 3*Coin::COIN_WIDTH, GROUND_HEIGHT - 300, -m_speed});
            }
        }
    }
}

void Model::increasePlayerScore()
{
    m_time_to_increase_score += INCREASE_SCORE_DELAY;
    m_player->addScore(1);

}

void Model::increaseGameSpeed()
{
    m_time_to_increase_game_speed += INCREASE_SPEED_DELAY;
    m_speed += 3;
}

Model::Model(int w, int h)
    :m_size{w,h}
    ,m_speed{INITIAL_SPEED}
    ,m_distance_travelled{0}
    ,m_time_to_spawn_an_obstacle{Clock::now() + SPAWN_OBSTACLE_DELAY}
    ,m_time_to_spawn_a_bonus{Clock::now() + SPAWN_BONUS_DELAY}
    ,m_time_to_spawn_a_coin{Clock::now() + SPAWN_COIN_DELAY}
    ,m_time_to_increase_score{Clock::now() + INCREASE_SCORE_DELAY}
    ,m_time_to_increase_game_speed{Clock::now() + INCREASE_SPEED_DELAY}
    ,m_last_update_time{Clock::now()}
    ,m_gameOver{false}
{

    m_player = new Player{250,GROUND_HEIGHT};
    
    srand(time(NULL));

}

Model::~Model()
{
    if(m_player != NULL)
        delete m_player;

    for(auto it : m_elements)
        delete it;

    m_elements.clear();

}

void Model::nextStep()
{
    //Clear
    m_newElements.clear();

    for(GameElement * ge : m_oldElements)
        delete ge;

    m_oldElements.clear();

    if(!m_gameOver){

        if(m_player->health() <= 0)
            m_gameOver = true;

        //Player
        m_player->update();

        //Elements
        std::set<GameElement*> geDelete;
        for (GameElement* ge : m_elements){
            if(m_player->collision(ge)){
                ge->affectPlayer(m_player);
                geDelete.insert(ge);
            }
            else if(ge->getPos().first < -ge->getSize().first){
                geDelete.insert(ge);
            }
            else{
                ge->update();
            }
        }
        for(GameElement* ge : geDelete){
            eraseGameElement(ge);
        }

        if(Clock::now() > m_time_to_increase_score)
            increasePlayerScore();
        if(Clock::now() > m_time_to_increase_game_speed)
            increaseGameSpeed();
        if(Clock::now() > m_time_to_spawn_an_obstacle)
            spawnObstacle();
        if(Clock::now() > m_time_to_spawn_a_bonus)
            spawnBonus();
        if(Clock::now() > m_time_to_spawn_a_coin)
            spawCoinSerie();


        Clock::duration elapsed_time{Clock::now() - m_last_update_time};
        m_distance_travelled += m_speed*(elapsed_time.count())/1000000000;

        m_last_update_time = Clock::now();
    }
}

void Model::movePlayerLeft()
{
    if(m_player->getPos().first > BORDER){
    m_player->setGoing_right(false);
    m_player->setGoing_left(true);
    }
    else
        stopPlayer();
}

void Model::movePlayerRight()
{
    if(m_player->getPos().first < m_size.first - BORDER - m_player->getSize().first)
    {
      m_player->setGoing_left(false);
      m_player->setGoing_right(true);
    }
    else
        stopPlayer();
}

void Model::jumpPlayer(bool isJumping)
{
    m_player->setJumping(isJumping);
}

void Model::stopPlayer()
{
    m_player->setGoing_left(false);
    m_player->setGoing_right(false);
}


std::pair<float, float> Model::getPlayerPos() const
{
    return m_player->getPos();
}

std::pair<float, float> Model::getPlayerSize() const
{
    return m_player->getSize();
}

int Model::getPlayerHealth() const
{
    return m_player->health();
}

int Model::getPlayerScore() const
{
    return m_player->score();
}

bool Model::isPlayerJumping() const
{
    return m_player->jumping();
}

bool Model::isPlayerOnTheGround() const
{
    return m_player->ontheground();
}

bool Model::isPlayerFlying() const
{
    return m_player->flying();
}

bool Model::playerDirection() const
{
    return m_player->getVelocity().first < 0;
}

std::set<GameElement *> Model::getNewElements() const
{
    return m_newElements;
}

std::set<GameElement *> Model::getOldElements() const
{
    return m_oldElements;
}

float Model::getSpeed() const
{
    return m_speed;
}

void Model::setSpeed(float speed)
{
    m_speed = speed;
}

bool Model::getGameOver() const
{
    return m_gameOver;
}
