#ifndef FACADE_HPP
#define FACADE_HPP
#include "Colvert.hpp"
#include "Affichage.hpp"
#include "InputHandler.hpp"

#include "FactoryPredator.hpp"
#include "Bestiaire.hpp"


#include <iostream>
/** La classe Facade g�re l'impl�mentation du pattern Facade (quel nom de classe original !), et prend en attributs tout ce qui peut lui �tre utile (bestiaire, canard, affichage, carte et input handler). Elle s'occupe d'appeler les bonnes m�thodes lorsque le jeu le n�cessite.*/
class Facade
{
    private:
        Carte* cart = new Carte();
        Colvert* joueur;
        Affichage aff;
        InputHandler* commandes;

        FactoryPredator* fP_;
        Bestiaire* bestiaire;

    public:
        /** Constructeur de la fa�ade, qui initialise le Canard, l'aigle, l'affichage et l'input */
        Facade(int difficulte);
        virtual ~Facade();
        /** Proc�dure de d�marrage du jeu, qui demande le nom du canard, et accueille le joueur */
        void debut();
        /** Proc�dure g�rant le tour du canard (affiche la vue, demande l'action du joueur, et fait baisser la faim du canard) */
        void tourCanard();
        /** Proc�dure g�rant les actions des pr�dateurs (pour le moment que l'aigle) */
        void tourPredateurs();
        /** Proc�dure d�terminant l'�volution du canard en fonction du tour envoy� en param�tre */
        void evolutions(int tour);
        /** Proc�dure g�rant la fin du jeu par des tests (si les conditions de victoire ou de d�faites sont atteintes) */
        void fin(int tour);
        /** Fonction renvoyant un bool�en pour l'arr�t du jeu */
        bool arret();
        /** Fonction renvoyant un bool�en pour recommencer une partie */
        bool recommencer();
        /** Proc�dure r�initialisant le jeu */
        void initialiser();     
        void initBestiaire(int type);
};
#endif // FACADE_HPP