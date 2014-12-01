#ifndef FACTORYPREDATOR_HPP
#define FACTORYPREDATOR_HPP

#include <vector>
#include "Predateur.hpp"
#include "Aigle.hpp"
#include "Renard.hpp"
#include "Brochet.hpp"
/** La classe abstraite FactoryPredator permet l'implémentation du pattern d'Abstract Factory,en décidant de quel prédateur sera sur la carte pour chaque type de prédateur*/
class FactoryPredator
{
    public:
        /**Constructeur*/
        FactoryPredator();
        /**Destructeur*/
        virtual ~FactoryPredator();
        /**\brief Crée un prédateur aérien.
        \return un pointeur vers un PredateurVol */
        virtual PredateurVol* creerCeleste(){return new Aigle();}
        /**\brief Crée un prédateur aquatique.
         \return un pointeur vers un PredateurEau */
        virtual PredateurEau* creerAqua(){return new Brochet(0);}
        /**\brief Crée un prédateur terrestre.
        \return un pointeur vers un PredateurSol */
        virtual PredateurSol* creerTerre(){return new Renard(0);}
};

/** La classe PredateursBasique est l'implémentation concrète de FactoryPredator, elle détermine comme prédateurs terrestres des Renards, aquatiques des Brochets et aériens des Aigles.*/
class PredateursBasique : public FactoryPredator
{
    public:
        /**Constructeur*/
        PredateursBasique();
        /**Destructeur*/
        virtual ~PredateursBasique();
        /**\brief Crée un prédateur aérien.
        \return un pointeur vers un PredateurVol */
        PredateurVol* creerCeleste();
        /**\brief Crée un prédateur terrestre.
        \return un pointeur vers un PredateurSol */
        PredateurSol* creerTerre();
        /**\brief Crée un prédateur aquatique.
         \return un pointeur vers un PredateurEau */
        PredateurEau* creerAqua();
};

#endif // FACTORYPREDATOR_HPP
