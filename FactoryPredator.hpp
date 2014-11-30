#ifndef FACTORYPREDATOR_HPP
#define FACTORYPREDATOR_HPP

#include <vector>
#include "Predateur.hpp"
#include "Aigle.hpp"
#include "Renard.hpp"
#include "Brochet.hpp"

class FactoryPredator
{
    public:
        FactoryPredator();
        virtual ~FactoryPredator();
        virtual PredateurVol* creerCeleste(){return new Aigle();}
        virtual PredateurEau* creerAqua(){return new Brochet(0);}
        virtual PredateurSol* creerTerre(){return new Renard(0);}
};

class PredateursBasique : public FactoryPredator
{
    public:
        PredateursBasique();
        virtual ~PredateursBasique();
        PredateurVol* creerCeleste();
        PredateurSol* creerTerre();
        PredateurEau* creerAqua();
};

#endif // FACTORYPREDATOR_HPP
