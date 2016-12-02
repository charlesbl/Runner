#include "model/trafficlight.h"

TrafficLight::TrafficLight(float x, float altitude, float vitx)
    :GameElement{ x, altitude-TRAFFICLIGHT_HEIGHT, TRAFFICLIGHT_WIDTH,TRAFFICLIGHT_HEIGHT, vitx,0, ElementType::TrafficLight_type }
{
}

void TrafficLight::affectPlayer(Player *p) const
{
    p->addHealth(-TRAFFICLIGHT_DAMAGE_AMOUNT);
}
