#include "shield.h"

Shield::Shield(float x, float groundheight, float vitx)
    :GameElement{x,groundheight-SHIELD_HEIGHT,SHIELD_WIDTH,SHIELD_HEIGHT,vitx,0,ElementType::Shield_Type}
{

}

void Shield::affectPlayer(Player *p) const
{
    p->setVulnerable(false);
}
