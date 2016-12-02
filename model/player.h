#ifndef PLAYER_H
#define PLAYER_H
#include "movableelement.h"
#include "utils/clock.h"

const float PLAYER_WIDTH = 72;
const float PLAYER_HEIGHT = 96;

/*!
 * \class Player
 * \brief Classe représentant le joueur.
 */
class Player : public MovableElement
{
private:
    /*!\brief Vitesse maximale du joueur en abscisse.*/
    const float VELOCITY_MAX = 9;
    /*!\brief Vitesse de saut du joueur en abscisse.*/
    const float JUMP_MAX_VELOCITY = 20;
    /*!\brief Hauteur maximale de saut du joueur en abscisse.*/
    const float JUMP_MAX_HEIGHT = 400;


    bool /*!\brief Player au sol ?*/ m_ontheground,
         /*!\brief Player vulnerable ?*/ m_vulnerable,
         /*!\brief Player en train de sauter ?*/ m_jumping,
         /*!\brief Player en train de voler ?*/ m_flying,
         /*!\brief Player se dirige vers la gauche ?*/ m_going_left,
         /*!\brief Player se dirige vers la droite ?*/ m_going_right;

    int /*!\brief Niveau de santé actuel.*/ m_health,
        /*!\brief Score actuel.*/m_score;

    float m_current_floor_level;

    Clock::time_point m_shield_start_time;
    Clock::time_point m_wings_start_time;

public:
    /*!\brief Niveau de santé maximum.*/
    static const int MAX_HEALTH = 100;

    /*!
     * \brief Constructeur
     * \param x : Position en abscisse.
     * \param groundheight : Hauteur du sol afin de positionner le joueur en ordonnée.
     */
    Player(float x, float groundheight);
    ~Player() override;

    void update() override;

    bool ontheground() const;
    bool jumping() const;
    void setJumping(bool jumping);
    bool flying() const;
    void setFlying(bool flying);
    int health() const;
    void addHealth(int health_amount);
    int score() const;
    void addScore(int score_amount);
    bool going_left() const;
    void setGoing_left(bool going_left);
    bool going_right() const;
    void setGoing_right(bool going_right);
    bool vulnerable() const;
    void setVulnerable(bool vulnerable);
};

#endif // PLAYER_H
