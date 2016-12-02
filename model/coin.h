#ifndef COIN_H
#define COIN_H

#include "model/gameelement.h"

/*!
 * \class Coin
 * \brief Classe représentant le bonus de type Piece.
 *
 * Ce bonus permettra au joueur d'augmenter son score.
 */
class Coin : public GameElement
{
private:

public:
    static constexpr int COIN_WIDTH = 85;
    static constexpr int COIN_HEIGHT = 85;
    static const int SCORE_ADDED = 10;

    Coin(float x, float groundheight, float vitx);
    void affectPlayer(Player *p) const override;
};

#endif // COIN_H
