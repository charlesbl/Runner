#include "player.h"
#include <math.h>
#include <iostream>

#include "model/wings.h"
#include "model/shield.h"

Player::Player(float x, float groundheight)
    :MovableElement::MovableElement{x,groundheight-PLAYER_HEIGHT,PLAYER_WIDTH,PLAYER_HEIGHT}
    ,m_ontheground{false}
    ,m_vulnerable{true}
    ,m_jumping{false}
    ,m_flying{false}
    ,m_health{MAX_HEALTH}
    ,m_score{0}
    ,m_current_floor_level{groundheight}
{}

Player::~Player()
{

}

void Player::update()
{
    if(!m_going_left && !m_going_right)
        m_velocity.first = 0;

    if(m_going_left && -m_velocity.first < VELOCITY_MAX)
        m_velocity.first--;
    if(m_going_right && m_velocity.first < VELOCITY_MAX)
        m_velocity.first++;


    if(m_flying)
    {

        if(m_jumping)
            m_velocity.second =-6;
        else
            m_velocity.second =6;

        if(Clock::now() >= m_wings_start_time + WINGS_DURATION)
            m_flying = false;
    }
    else
    {
      //Si le joueur n'est pas ausol et que soit il ne monte plus ou que sa position a atteint la hauteur de saut maximale
      //Il n'est plus considéré comme en train de sauter
        if(!m_ontheground && (m_velocity.second > 0 || m_pos.second <= m_current_floor_level - JUMP_MAX_HEIGHT))
            m_jumping = false;

      //Si il est en phase de saut et qu'il est au sol (cela veut dire qu'il est au début du saut)
      //Alors sa vitesse en y est négative (pour le faire aller vers le haut)
        if(m_jumping && m_ontheground)
            m_velocity.second = -3;

      //Si il est en phase de saut et qu'il n'a pas atteint la limite de vitesse en y
      //On peut décrémenter sa vitesse (le repère étant inversé il ira plus vite)
        if(m_jumping && -m_velocity.second < JUMP_MAX_VELOCITY)
            m_velocity.second-=3;

      //Si il atteint la hauteur de saut maximale
      //Sa vitesse en y devient positif (il va donc chuter)
        if(m_pos.second <= m_current_floor_level - JUMP_MAX_HEIGHT)
            m_velocity.second+=3;

      //Si il n'est plus en phase de saut et qu'il n'est pas au sol
      //On incrémente sa vitesse en y afin de le faire chuter plus vite
        if(!m_jumping && !m_ontheground)
            m_velocity.second+=3;

    }

    m_ontheground = m_pos.second + m_size.second >= m_current_floor_level;

    m_pos.first += m_velocity.first;
    m_pos.second += m_velocity.second;

    if(m_pos.second + m_size.second > m_current_floor_level)
        m_pos.second = m_current_floor_level - m_size.second;

    if(!m_vulnerable)
        m_size = std::pair<float,float> {PLAYER_WIDTH*3,PLAYER_HEIGHT*3};
    else if(m_flying)
        m_size = std::pair<float,float> {PLAYER_HEIGHT,PLAYER_WIDTH};
    else
        m_size = std::pair<float,float> {PLAYER_WIDTH,PLAYER_HEIGHT};

    if(!m_vulnerable && Clock::now() >= m_shield_start_time + SHIELD_DURATION)
            m_vulnerable = true;

}

bool Player::ontheground() const
{
    return m_ontheground;
}

bool Player::jumping() const
{
    return m_jumping;
}

void Player::setJumping(bool jumping)
{
    m_jumping = jumping;
}

bool Player::flying() const
{
    return m_flying;
}

void Player::setFlying(bool flying)
{
    if(flying)
        m_wings_start_time = Clock::now();

    m_flying = flying;
}

int Player::health() const
{
    return m_health;
}

void Player::addHealth(int health_amount)
{
    if(m_vulnerable || health_amount > 0)
        m_health += health_amount;
}

int Player::score() const
{
    return m_score;
}

void Player::addScore(int score_amount)
{
    m_score += score_amount;
}

bool Player::going_left() const
{
    return m_going_left;
}

void Player::setGoing_left(bool going_left)
{
    m_going_left = going_left;
}

bool Player::going_right() const
{
    return m_going_right;
}

void Player::setGoing_right(bool going_right)
{
    m_going_right = going_right;
}


bool Player::vulnerable() const
{
    return m_vulnerable;
}

void Player::setVulnerable(bool vulnerable)
{
    if(!vulnerable)
        m_shield_start_time = Clock::now();

    m_vulnerable = vulnerable;
}
