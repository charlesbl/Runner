#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>
/*!
 * \brief Clock et milliseconds_duration
 *
 *  Définition de type permet de simplifier la lecture et l'écriture des objets de gestion du temps.
 */
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::duration<int,std::milli> milliseconds_duration;

#endif // CLOCK_H
