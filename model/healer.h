#ifndef HEALER_H
#define HEALER_H

#include "model/gameelement.h"

/*!
 * \class Healer
 * \brief Classe représentant le bonus régénérant la vie du joueur.
 *
 * Ce bonus permettra au joueur de regagner de la vie.
 */
class Healer : public GameElement
{
private:

public:
    static constexpr int HEALER_WIDTH = 85;
    static constexpr int HEALER_HEIGHT = 85;
    static constexpr int HEALTH_RESTORED = 50;

    Healer(float x, float groundheight, float vitx);
    void affectPlayer(Player *p) const override;
};

#endif // HEALER_H
