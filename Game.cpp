#include <iostream>
#include "Canard.hpp"
#include "affichage.hpp"
#include "Caneton.hpp"


int main(void)
{
	//variables du jeu
	bool reprendre = true;
	std::string nomCanard =""; 	
	//on fait la carte une fois pour toutes (et on lance l'aff)
	Carte* cart = new Carte();
	Affichage aff(cart);

	while (reprendre)
	{
			//début du jeu, on initialise la variable de relance à faux
			reprendre = false;
			//on blablate pour intéresser le joueur
			aff.debut();
			//on récupère son nom
			std::cin >> nomCanard;
			//on crée son canard
			Caneton joueur(nomCanard);
			//on l'accueille poliment quand même
			std::cout << "Bienvenue, " << joueur.getNom() << "." << std::endl;
			std::cout << joueur.presentation() << std::endl;

		//à la fin du "jeu", on lui demande si il veut relancer une partie
	 	if(aff.relancer())
	 	{
	 		reprendre = true;
	 	}
	}



	
	return 0;

}