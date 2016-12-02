#include "movablesview.h"
#include <iostream>

MovablesView::MovablesView(sf::RenderWindow *window, Model *model)
    :View{window,model}
{
    //Chargement des textures
    if(!m_stand_texture.loadFromFile(STAND_IMAGE)){
        std::cerr << "Unable to open file : " << STAND_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }
    if(!m_car_texture.loadFromFile(CAR_IMAGE)){
        std::cerr << "Unable to open file : " << CAR_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }
    if(!m_bird_texture.loadFromFile(TRAFFICLIGHT_IMAGE)){
        std::cerr << "Unable to open file : " << TRAFFICLIGHT_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }
    if(!m_healer_texture.loadFromFile(HEALER_IMAGE)){
        std::cerr << "Unable to open file : " << HEALER_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }
    if(!m_coin_texture.loadFromFile(COIN_IMAGE)){
        std::cerr << "Unable to open file : " << COIN_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }
    if(!m_shield_texture.loadFromFile(SHIELD_IMAGE)){
        std::cerr << "Unable to open file : " << SHIELD_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }
    if(!m_wings_texture.loadFromFile(WINGS_IMAGE)){
        std::cerr << "Unable to open file : " << WINGS_IMAGE << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<sf::IntRect> clips;


    clips = {{0,0,42,54},{42,0,42,54}};
    Animation truckAni{clips, 10};
    m_stand_animation.push_back(truckAni);

    clips = {{0,0,36,18},{36,0,36,18}};
    Animation carAni{clips, 10};
    m_car_animation.push_back(carAni);

    clips = {{0,0,18,200},{18,0,18,200},{36,0,18,200}};
    Animation trafficLightAni{clips, 10};
    m_trafficlight_animation.push_back(trafficLightAni);

    clips = {{0,0,16,16},{16,0,16,16},{32,0,16,16},{48,0,16,16},
             {64,0,16,16},{80,0,16,16},{96,0,16,16},{112,0,16,16},
             {128,0,16,16},{144,0,16,16},{160,0,16,16},{176,0,16,16},
             {192,0,16,16},{208,0,16,16},{224,0,16,16},{240,0,16,16}};
    Animation healerAni{clips, 1};
    m_healer_animation.push_back(healerAni);

    clips = {{0,0,16,16},{16,0,16,16},{32,0,16,16},{48,0,16,16},{64,0,16,16},
             {80,0,16,16},{96,0,16,16},{112,0,16,16},{128,0,16,16}};
    Animation coinAni{clips, 2};
    m_coin_animation.push_back(coinAni);

    clips = {{0,0,16,16}};
    Animation shieldAni{clips, 2};
    m_shield_animation.push_back(shieldAni);

    clips = {{0,0,32,16},{32,0,32,16}};
    Animation wingsAni{clips, 20};
    m_wings_animation.push_back(wingsAni);

    if (!m_explosion.loadFromFile(EXPLOSION))
        std::cerr << EXPLOSION << " not loaded" << std::endl;

    if (!m_coin.loadFromFile(COIN))
        std::cerr << COIN << " not loaded" << std::endl;

}


void MovablesView::synchronize()
{
    //Ajout des nouveaux éléments à afficher
    for(auto it: m_model->getNewElements()){
        sf::Vector2f size{it->getSize().first, it->getSize().second};
        sf::Vector2f pos {it->getPos().first, it->getPos().second};

        switch(it->getType()){
        case ElementType::Stand_type:
            m_elementsToSprites.insert(std::pair<const MovableElement *, AnimatedGraphicElement> {it, AnimatedGraphicElement {m_stand_animation, m_stand_texture, pos, size}});
            break;

        case ElementType::Car_type:
            m_elementsToSprites.insert(std::pair<const MovableElement *, AnimatedGraphicElement> {it, AnimatedGraphicElement {m_car_animation, m_car_texture, pos, size}});
            break;

        case ElementType::TrafficLight_type:
            m_elementsToSprites.insert(std::pair<const MovableElement *, AnimatedGraphicElement> {it, AnimatedGraphicElement {m_trafficlight_animation, m_bird_texture, pos, size}});
            break;

        case ElementType::Healer_type:
            m_elementsToSprites.insert(std::pair<const MovableElement *, AnimatedGraphicElement> {it, AnimatedGraphicElement {m_healer_animation, m_healer_texture, pos, size}});
            break;

        case ElementType::Coin_type:
            m_elementsToSprites.insert(std::pair<const MovableElement *, AnimatedGraphicElement> {it, AnimatedGraphicElement {m_coin_animation, m_coin_texture, pos, size}});
            break;

        case ElementType::Shield_Type:
            m_elementsToSprites.insert(std::pair<const MovableElement *, AnimatedGraphicElement> {it, AnimatedGraphicElement {m_shield_animation, m_shield_texture, pos, size}});
            break;
        case ElementType::Wings_Type:
            m_elementsToSprites.insert(std::pair<const MovableElement *, AnimatedGraphicElement> {it, AnimatedGraphicElement {m_wings_animation, m_wings_texture, pos, size}});
            break;
        }
    }
    //Suppression des sprites qui ne font plus parti du model
    for(auto it: m_model->getOldElements()){
        if(it->getPos().first > 0){
            if(it->getType() == ElementType::Car_type || it->getType() == ElementType::TrafficLight_type || it->getType() == ElementType::Stand_type)
                m_sound.setBuffer(m_explosion);
            if(it->getType() == ElementType::Coin_type)
                m_sound.setBuffer(m_coin);
            m_sound.play();
        }
        m_elementsToSprites.erase(it);
    }

    //Mis a jour des sprites des éléments
    for(auto it = m_elementsToSprites.begin(); it != m_elementsToSprites.end(); it++)
        it->second.setPosition(it->first->getPos().first, it->first->getPos().second);
}

void MovablesView::draw()
{
    for(auto it = m_elementsToSprites.begin() ; it != m_elementsToSprites.end(); it++)
        it->second.draw(m_window);
}
