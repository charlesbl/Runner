#ifndef CAR_H
#define CAR_H

#include "model/gameelement.h"

/*!
 * \class Car
 * \brief Classe représentant l'obstacle de type voiture.
 */
class Car : public GameElement
{
private:

public:
    static constexpr float CAR_WIDTH = 200;
    static constexpr float CAR_HEIGHT = 100;
    static const int CAR_DAMAGE_AMOUNT = 30;

    Car(float x, float groundheight, float vitx);
    void affectPlayer(Player *p) const override;
};

#endif // CAR_H
