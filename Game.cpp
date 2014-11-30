#include <iostream>
#include <cstdlib>
#include "Facade.hpp"
/**
Main contenant la boucle de jeu et tout.
*/

int main(void)
{
    //variables du jeu
	bool reprendre = true;
	int cpt;
	int diff;
	std::string nomCanard ="";
	do
    {
        std::cout<<"Vous avez le choix entre un niveau de difficultee basique ou basique.\nPrenez votre temps surtout, tapez 0 "<<std::endl;
        std::cin >> diff;
    }while(diff != 0);
	Facade facade(nomCanard, diff);
	while (reprendre)
	{
        //début du jeu, on initialise la variable de relance à faux et le compteur de tour à 0
        cpt = 0; //0 tour de jeu au début
        facade.debut(nomCanard);
        while(!facade.arret())
        {
/* tour du canard:*/
            ++cpt;                  //nouveau tour, incréme,tation du compteur
            facade.tourCanard();
/* tour des prédateurs:*/
            facade.tourPredateurs();
/* le joueur est il mort ? */
            facade.fin(cpt);
/* Conditions d'évolution: */
            facade.evolutions(cpt);
        }
/*à la fin du "jeu", on lui demande si il veut relancer une partie, si oui on réinitialise les variables, si non on arrete*/
        if(facade.recommencer())
        {
            facade.initialiser();
        }
        else
        {
            reprendre = false;
        }
	}
	return 0;

}
