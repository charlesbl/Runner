#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "model/model.h"
#include "graphics/animatedgraphicelement.h"
#include "view/view.h"

class PlayerView : public View
{
private:

    sf::Texture m_playerTexture;
    std::vector<Animation> m_animations_player;
    AnimatedGraphicElement *m_playerSprite;


    sf::RectangleShape m_lifeRectangle;
    sf::Text m_scoreText;

    const std::string PLAYER_IMAGE = "Images/player.png";
    const float LIFE_MAX_WIDTH = 300;
public:

    PlayerView(sf::RenderWindow *window, Model *model);
    ~PlayerView();

    void synchronize() override;
    void draw() const;
};

#endif // PLAYERVIEW_H
