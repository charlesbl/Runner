#ifndef TRUCK_H
#define TRUCK_H

#include "model/gameelement.h"

/*!
 * \class Stand
 * \brief Classe représentant l'obstacle de type échoppe
 */
class Stand : public GameElement
{
private:

public:
    static constexpr float STAND_WIDTH = 168;
    static constexpr float STAND_HEIGHT = 216;
    static const int STAND_DAMAGE_AMOUNT = 40;

    Stand(float x, float groundheight, float vitx);
    void affectPlayer(Player *p) const override;
};

#endif // TRUCK_H
