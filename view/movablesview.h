#ifndef MOVABLESVIEW_H
#define MOVABLESVIEW_H

#include "graphics/animatedgraphicelement.h"
#include "model/model.h"
#include "view/view.h"
#include <SFML/Audio.hpp>

class MovablesView : public View
{
private:

    sf::Texture m_stand_texture;
    std::vector<Animation> m_stand_animation;

    sf::Texture m_car_texture;
    std::vector<Animation> m_car_animation;

    sf::Texture m_bird_texture;
    std::vector<Animation> m_trafficlight_animation;

    sf::Texture m_healer_texture;
    std::vector<Animation> m_healer_animation;

    sf::Texture m_coin_texture;
    std::vector<Animation> m_coin_animation;

    sf::Texture m_shield_texture;
    std::vector<Animation> m_shield_animation;

    sf::Texture m_wings_texture;
    std::vector<Animation> m_wings_animation;

    /*!\brief Map faisant la correspondance entre les MovableElement du Model et des AnimatedGraphicElement*/
    std::map<const MovableElement *, AnimatedGraphicElement> m_elementsToSprites;

    sf::SoundBuffer m_explosion;
    sf::SoundBuffer m_coin;
    sf::Sound m_sound;

    const std::string STAND_IMAGE = "Images/stand.png";
    const std::string CAR_IMAGE = "Images/car.png";
    const std::string TRAFFICLIGHT_IMAGE = "Images/traffic_light.png";
    const std::string HEALER_IMAGE = "Images/healer.png";
    const std::string COIN_IMAGE = "Images/coin.png";
    const std::string SHIELD_IMAGE = "Images/shield.png";
    const std::string WINGS_IMAGE = "Images/wings.png";
    const std::string EXPLOSION = "sound/Big_Explosion_Cut_Off.ogg";
    const std::string COIN = "sound/coin.ogg";

public:

    MovablesView(sf::RenderWindow *window, Model *model);

    void synchronize() override;

    //Ne peut pas être const à cause des itérateurs
    void draw();
};

#endif // MOVABLESVIEW_H
