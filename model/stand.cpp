#include "model/stand.h"

Stand::Stand(float x, float groundheight, float vitx)
    :GameElement{ x, groundheight-STAND_HEIGHT, STAND_WIDTH,STAND_HEIGHT, vitx,0, ElementType::Stand_type }
{
}

void Stand::affectPlayer(Player *p) const
{
    p->addHealth(-STAND_DAMAGE_AMOUNT);
}
