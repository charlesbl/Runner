#include "healer.h"

Healer::Healer(float x, float groundheight, float vitx)
    :GameElement{ x, groundheight-HEALER_HEIGHT, HEALER_WIDTH, HEALER_HEIGHT, vitx, 0, ElementType::Healer_type}
{
}

void Healer::affectPlayer(Player *p) const
{
    if(Player::MAX_HEALTH - p->health() > HEALTH_RESTORED)
        p->addHealth(HEALTH_RESTORED);
    else
        p->addHealth(Player::MAX_HEALTH - p->health());
}
