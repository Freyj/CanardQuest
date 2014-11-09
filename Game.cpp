#include <iostream>
#include "affichage.hpp"
#include "Caneton.hpp"
#include "InputHandler.hpp"

/**
Main contenant la boucle de jeu et tout.
*/

int main(void)
{
	//variables du jeu
	bool reprendre = true;
	std::string nomCanard ="";
	//on fait la carte une fois pour toutes (et on lance l'aff)
	Carte* cart =  new Carte();
	Affichage aff(cart);
	//tests pour voir si la carte recevait bien les bons chiffres
	//std::cout << cart->getTab(0) << std::endl;
	//std::cout << cart->getTab(17) << std::endl;
	//std::cout << cart->getOccupation(10) << std::endl;
	//tant qu'on veut pas finir de jouer
	while (reprendre)
	{
			//début du jeu, on initialise la variable de relance à faux
			reprendre = false;
			//on blablate pour alpaguer le joueur
			aff.debut();
			//on récupère son nom
			std::cin >> nomCanard;
			//on crée son canard
			Caneton joueur(nomCanard);
			InputHandler* commandes = new InputHandler(&joueur, cart);
			//on l'accueille poliment quand même
			aff.etoiles();
			std::cout << "Bienvenue, " << joueur.getNom() << ".\n" << std::endl;
			std::cout << joueur.presentation() << std::endl;
			while(!commandes->getArret())
			{
				aff.vue(joueur.getPos());
				commandes->userInput();
				joueur.statut();
				

				//pour test
				//commandes->getCanard()->presentation();
				if(joueur.getFaim() == 0 || joueur.estMort()){
					aff.gameOver();
                    commandes->setArret(true);
				}
				joueur.setFaim(joueur.getFaim()-1);
			}


			//joueur.deplacement(2);
			//aff.vue(joueur.getPos());
		//à la fin du "jeu", on lui demande si il veut relancer une partie
	 	if(aff.relancer())
	 	{
	 		reprendre = true;
	 	}
	 	else
	 	{
	 		reprendre = false;
	 	}
	}

	return 0;

}
