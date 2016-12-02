#ifndef SHIELD_H
#define SHIELD_H

#include "model/gameelement.h"

const milliseconds_duration SHIELD_DURATION{5000};

/*!
 * \class Shield
 * \brief Classe représentant le bonus de type bouclier.
 *
 * Ce bonus permettra au joueur d'être invulnérable.
 */
class Shield : public GameElement
{
public:
    static constexpr int SHIELD_WIDTH = 85;
    static constexpr int SHIELD_HEIGHT = 85;


    Shield(float x, float groundheight, float vitx);
    void affectPlayer(Player *p) const override;
};

#endif // SHIELD_H
