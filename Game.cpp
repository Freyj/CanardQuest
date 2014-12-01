/*! \mainpage Présentation
    
    CanardQuest est un jeu où vous êtes un canard tentant de survivre dans un monde hostile avec des prédateurs. Vous devez trouver de la nourriture pour survivre. Votre canard finit par évoluer et apprend à voler ainsi qu'à nager [oui, il ne sait pas nager à la naissance, c'est très réaliste, sources de wikipedia pour la vie d'un canard !]
*/

#include <iostream>
#include <cstdlib>
#include "Facade.hpp"

/** Main contenant la boucle de jeu et tout. v1.0*/

int main(void)
{
    //variables du jeu
    bool reprendre = true;
    int cpt;
    char diff;
    //std::string nomCanard ="";
    //choix de la difficulté (pour le moment sans intérêt)
    do 
    {       
        std::cout<<"Vous avez le choix entre un niveau de difficulté  basique ou basique.\nPrenez votre temps surtout pour choisir, tapez 0 "<<std::endl;
        std::cin >> diff;
    }while (diff != '0');

    Facade facade(0);

    while (reprendre)
    {
        //début du jeu, on initialise la variable de relance à faux et le compteur de tour à 0
        cpt = 0; //0 tour de jeu au début

        facade.debut();

        while(!facade.arret())
        {
            /* tour du canard:*/
            ++cpt; //nouveau tour, incrémentation du compteur
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