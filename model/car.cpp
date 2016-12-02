#include "car.h"

Car::Car(float x, float groundheight, float vitx)
    :GameElement{ x, groundheight-CAR_HEIGHT, CAR_WIDTH, CAR_HEIGHT, vitx, 0, ElementType::Car_type }
{

}

void Car::affectPlayer(Player *p) const
{
    p->addHealth(-CAR_DAMAGE_AMOUNT);
}
