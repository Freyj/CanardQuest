#include <iostream>
#include <cstdlib>
#include "Colvert.hpp"
#include "Affichage.hpp"
#include "InputHandler.hpp"
#include "Aigle.hpp"

/**
Main contenant la boucle de jeu et tout.
*/

int main(void)
{

//    std::system("clear");

    //variables du jeu
	bool reprendre = true;
	int cpt;
	std::string nomCanard ="";
	//on fait la carte une fois pour toutes (et on lance l'aff)
	Carte* cart =  new Carte();
	Affichage aff(cart);
	while (reprendre)
	{
        //début du jeu, on initialise la variable de relance à faux et le compteur de tour à 0
        cpt = 0; //0 tour de jeu au début
        reprendre = false;
        //on crée les prédateurs [pour l'instant un seul]
        Aigle aigle;
        //on blablate pour alpaguer le joueur
        aff.debut();
        //on récupère son nom
        std::cin >> nomCanard;
        //on crée son canard
        Colvert joueur(nomCanard);
        InputHandler* commandes = new InputHandler(&joueur, cart);
        //on l'accueille poliment quand même
        aff.etoiles();
        std::cout << "Bienvenue, " << joueur.getNom() << ".\n" << std::endl;
        std::cout << joueur.presentation() << std::endl;
        while(!commandes->getArret())
        {

//            std::system("clear");

/* tour du canard:*/

            ++cpt;                                  //nouveau tour, incréme,tation du compteur
            aff.vue(joueur.getPos());               //on affiche la position du canard
            commandes->choix();                     //on demande au joueurs d'entrer ses instructions
            joueur.setFaim(joueur.getFaim()-1);     //à la fin de son tour, le canard consomme un point de faim

/*fin du tour du canard*/

/* tour des prédateurs:*/

            //va tuer le canard si le prédateur est sur la meme case que lui
            aigle.tuer(joueur);

/*fin du tour des prédateurs*/

/* le joueur est il mort ? */

            //Si le joueur à perdu inutile de reafficher la carte les commandes etc
            if(joueur.estVivant() == false)//si faim == 0 alors estVivant passe à false
            {
                aff.gameOver();
                commandes->setArret(true);
            }/* a faire dès qu'une modification peut entrainer la mort du canard */
            else
            {
                joueur.statut();    //on affiche le statut du joueur
            }

/* Condition d'évolution: */


            if(cpt == 10)
            {
                CompetenceVol* compVol = new CompetenceVolEnable;
                CompetenceNage* compNage = new CompetenceNageEnable;
                joueur.setCompVol(compVol);
                joueur.setCompNage(compNage);
            }
            if(cpt == 25)
            {
                CompetenceCancan* cancan = new CompetenceCancanEnable;
                joueur.setCompCan(cancan);
                std::cout << "Cancanne un peu pour voir ? Ah, c'est très bien, si tu le fais régulièrement" << std::endl;
                std::cout <<"peut etre qu'un autre canard te rejoindras et que tu finiras ta vie heureux."<< std::endl;
            }
            //Par défaut, si on survit 50 tours, on gagne [vu qu'il n'y a pas encore de "vraie" victoire]
            if (cpt > 50)
            {
                aff.victoire();
                commandes->setArret(true);
            }
        }

		//à la fin du "jeu", on lui demande si il veut relancer une partie
 		reprendre = aff.relancer();
	}

	return 0;

}
