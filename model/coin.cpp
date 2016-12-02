#include "coin.h"

Coin::Coin(float x, float groundheight, float vitx)
    :GameElement{x,groundheight-COIN_HEIGHT,COIN_WIDTH,COIN_HEIGHT,vitx,0,ElementType::Coin_type}
{
}

void Coin::affectPlayer(Player *p) const
{
    p->addScore(SCORE_ADDED);
}
