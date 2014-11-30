#ifndef FACADE_HPP
#define FACADE_HPP


#include "Colvert.hpp"
#include "Affichage.hpp"
#include "InputHandler.hpp"
#include "FactoryPredator.hpp"
#include "Bestiaire.hpp"
#include <iostream>

class Facade
{
    private:
        Carte* cart = new Carte();
        Colvert joueur;
        Affichage aff;
        InputHandler* commandes;
        FactoryPredator* fP_;
        Bestiaire* bestiaire;

    public:
        Facade(std::string nomCanard, int difficulte);
        virtual ~Facade();

        void debut(std::string nomCanard);
        void tourCanard();
        void tourPredateurs();//à modifier pour l'adapter aux nouveaux predateurs
        void evolutions(int tour);
        void fin(int tour);
        bool arret();
        bool recommencer();
        void initialiser();
        void initBestiaire(int type);

    protected:
};

#endif // FACADE_HPP
