#include "wings.h"

Wings::Wings(float x, float groundheight, float vitx)
    :GameElement{ x, groundheight-WINGS_HEIGHT, WINGS_WIDTH, WINGS_HEIGHT, vitx, 0, ElementType::Wings_Type}
{

}

void Wings::affectPlayer(Player *p) const
{
    p->setFlying(true);
}
