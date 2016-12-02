#ifndef MODEL_H
#define MODEL_H

#include "model/player.h"
#include "model/gameelement.h"
#include <set>
#include <queue>
#include <chrono>

class Model
{
private :
    /*!\brief Vitesse du jeu en début de partie.*/
    const float INITIAL_SPEED = 700 ;
    /*!\brief Hauteur du sol.*/
    const float GROUND_HEIGHT = 580;

    /*!\brief Délai entre l'apparition des obstacles.*/
    const milliseconds_duration SPAWN_OBSTACLE_DELAY{1000};
    /*!\brief Délai entre l'apparition des bonus.*/
    const milliseconds_duration SPAWN_BONUS_DELAY{7000};
    /*!\brief Délai entre l'apparition des pièces.*/
    const milliseconds_duration SPAWN_COIN_DELAY{2000};
    /*!\brief Délai au bout duquel il faut augmenter le score.*/
    const milliseconds_duration INCREASE_SCORE_DELAY{100};
    /*!\brief Délai au bout duquel il faut augmenter la vitesse.*/
    const milliseconds_duration INCREASE_SPEED_DELAY{500};

    /*!\brief Dimensions du Model*/
    std::pair<int,int> m_size;


    float /*!\brief Vitesse actuelle du Model.*/ m_speed,
          /*!\brief Distance en pixel parcourue depuis la création du Model.*/ m_distance_travelled;

    /*!\brief Temps auquel le prochain obstacle doit apparaître.*/
    Clock::time_point m_time_to_spawn_an_obstacle;
    /*!\brief Temps auquel le prochain bonus doit apparaître.*/
    Clock::time_point m_time_to_spawn_a_bonus;
    /*!\brief Temps auquel la prochaine pièce doit apparaître.*/
    Clock::time_point m_time_to_spawn_a_coin;
    /*!\brief Temps auquel le score sera augmenté.*/
    Clock::time_point m_time_to_increase_score;
    /*!\brief Temps auquel la vitesse du jeu sera augmentée.*/
    Clock::time_point m_time_to_increase_game_speed;

    /*!\brief Temps auquel le Model a été mis à jour pour la dernière fois.*/
    Clock::time_point m_last_update_time;

    /*!\brief Le Player du Model.*/
    Player *m_player;

    /*!\brief Tous les GameElement.*/
    std::set<GameElement *> m_elements;
    /*!\brief Les GameElement venant d'être ajoutés.*/
    std::set<GameElement *> m_newElements;
    /*!\brief Les GameElement venant d'être supprimés.*/
    std::set<GameElement *> m_oldElements;
    /*!\brief Le dernier GameElement ajouté.*/
    GameElement* m_lastElementAdded;

    /*!\brief Le Player a-t-il perdu ?*/
    bool m_gameOver;

    /*!\brief Ajoute un GameElement pointé par ge.*/
    void addGameElement(GameElement *ge);
    /*!\brief Enlève un GameElement pointé par ge*/
    void eraseGameElement(GameElement *ge);

    /*!\brief Fait apparaître un obstacle aléatoire.*/
    void spawnObstacle();
    /*!\brief Fait apparaître un bonus aléatoire.*/
    void spawnBonus();
    /*!\brief Fait apparaître une série de pièces de longueur aléatoire.*/
    void spawCoinSerie();

    /*!\brief Augmente le score du Player.*/
    void increasePlayerScore();
    /*!\brief Augmente la vitesse du Model.*/
    void increaseGameSpeed();

public :
    /*!\brief Largeur des bordures à gauche et à droite de l'écran.*/
    const float BORDER = 100;

    /*!
     * \brief Constructeur
     * \param w : largeur en pixel
     * \param h : hauteur en pixel
     */
    Model(int w, int h);
    ~Model();

    /*!\brief Méthode de mise à jour du Model*/
    void nextStep();

    /*\brief Bouge m_player à gauche.*/
    void movePlayerLeft();
    /*\brief Bouge m_player à drotie.*/
    void movePlayerRight();
    /*\brief Fait sauter m_player.*/
    void jumpPlayer(bool isJumping);
    /*\brief Arrêter tout mouvement en abscisse de m_player.*/
    void stopPlayer();

    std::pair<float, float> getPlayerPos() const;
    std::pair<float, float> getPlayerSize() const;
    int getPlayerHealth() const;
    int getPlayerScore() const;

    bool isPlayerMoving() const;
    bool isPlayerJumping() const;
    bool isPlayerOnTheGround() const;
    bool isPlayerFlying() const;
    /*!
     * \brief Donne la direction de m_player
     * \return true vers la gauche, false vers la droite.
     */
    bool playerDirection() const;

    std::set<GameElement *> getElements() const;
    std::set<GameElement *> getNewElements() const;
    std::set<GameElement *> getOldElements() const;

    float getSpeed() const;
    void setSpeed(float speed);
    bool getGameOver() const;
};

#endif // MODEL_H
