#ifndef WINGS_H
#define WINGS_H

#include "model/gameelement.h"

const milliseconds_duration WINGS_DURATION{5000};

/*!
 * \class Wings
 * \brief Classe représentant le bonus de type ailes.
 *
 *  Ce bonus permettra au joueur de voler.
 */
class Wings : public GameElement
{
public:

    static constexpr int WINGS_WIDTH = 170;
    static constexpr int WINGS_HEIGHT = 85;

    Wings(float x, float groundheight, float vitx);
    void affectPlayer(Player *p) const override;
};

#endif // WINGS_H
