#ifndef FACADE_HPP
#define FACADE_HPP
#include "Colvert.hpp"
#include "Affichage.hpp"
#include "InputHandler.hpp"

#include "FactoryPredator.hpp"
#include "Bestiaire.hpp"


#include <iostream>
/** La classe Facade gère l'implémentation du pattern Facade (quel nom de classe original !), et prend en attributs tout ce qui peut lui être utile (bestiaire, canard, affichage, carte et input handler). Elle s'occupe d'appeler les bonnes méthodes lorsque le jeu le nécessite.*/
class Facade
{
    private:
        /**Pointeur vers Carte */
        Carte* cart = new Carte();
        /**Pointeur vers Colvert*/
        Colvert* joueur;
        /**Affichage*/
        Affichage aff;
        /**Pointeur vers InputHandler*/
        InputHandler* commandes;

        /**Pointeur vers FactoryPredator*/
        FactoryPredator* fP_;
        /**Pointeur vers Bestiaire*/
        Bestiaire* bestiaire;

    public:
        /** \brief Constructeur.
        Constructeur de la façade, qui initialise le Canard, l'aigle, l'affichage et l'input
        \param difficulte l'int pour la difficulté */
        Facade(int difficulte);
        virtual ~Facade();
        /** Procédure de démarrage du jeu, qui demande le nom du canard, et accueille le joueur */
        void debut();
        /** Procédure gérant le tour du canard (affiche la vue, demande l'action du joueur, et fait baisser la faim du canard) */
        void tourCanard();
        /** Procédure gérant les actions des prédateurs (pour le moment que l'aigle) */
        void tourPredateurs();
        /** Procédure déterminant l'évolution du canard en fonction du tour envoyé en paramètre
        \param tour : int du tour */
        void evolutions(int tour);
        /** Procédure gérant la fin du jeu par des tests (si les conditions de victoire ou de défaites sont atteintes) 
        \param tour : int du tour*/
        void fin(int tour);
        /** Fonction renvoyant un booléen pour l'arrêt du jeu */
        bool arret();
        /** Fonction renvoyant un booléen pour recommencer une partie */
        bool recommencer();
        /** Procédure réinitialisant le jeu */
        void initialiser();     
        /** Procédure initialisant le bestiaire 
            \param type : int représentant le type de bestiaire*/
        void initBestiaire(int type);
};
#endif // FACADE_HPP