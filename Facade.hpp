#ifndef FACADE_HPP
#define FACADE_HPP


#include "Colvert.hpp"
#include "Affichage.hpp"
#include "InputHandler.hpp"
#include "Aigle.hpp"
#include <iostream>

class Facade
{
    private:
        Carte* cart = new Carte();
        Colvert joueur;
        Aigle aigle;
        Affichage aff;
        InputHandler* commandes;

    public:
        Facade(std::string nomCanard);
        virtual ~Facade();

        void debut(std::string nomCanard);
        void tourCanard();
        void tourPredateurs();
        void evolutions(int tour);
        void fin(int tour);
        bool arret();
        bool recommencer();
        void initialiser();

    protected:
};

#endif // FACADE_HPP
