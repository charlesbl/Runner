#ifndef BIRD_H
#define BIRD_H

#include "model/gameelement.h"

/*!
 * \class TrafficLight
 * \brief Classe représentant l'obstacle de type feux tricolores
 */
class TrafficLight : public GameElement
{
public:
    static constexpr float TRAFFICLIGHT_WIDTH = 54;
    static constexpr float TRAFFICLIGHT_HEIGHT = 600;
    static const int TRAFFICLIGHT_DAMAGE_AMOUNT = 20;

    TrafficLight(float x, float altitude, float vitx);
    void affectPlayer(Player *p) const override;
};

#endif // BIRD_H
