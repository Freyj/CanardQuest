#ifndef ETAT_HPP
#define ETAT_HPP

#include <iostream>


class Canard;
/**La classe abstraite Etat permet l'impl�mentation du pattern State, elle d�termine l'�tat du canard (au sol, en l'air, dans l'eau). */
class Etat
{
    public:
        /**Constructeur*/
        Etat() {}
        /**Destructeur virtuel*/
        virtual ~Etat() {}
        /**Pour entrer dans l'eau depuis le sol*/
        virtual void onWater(){std::cout << "Action impossible." << std::endl;}
        /**Pour sortir de l'eau vers le sol*/
        virtual void offWater(){std::cout << "Action impossible." << std::endl;}
        /**Pour d�coller depuis le sol*/
        virtual void decollageSol(){std::cout << "Action impossible." << std::endl;}
        /**Pour d�coller depuis l'eau*/
        virtual void decollageEau(){std::cout << "Action impossible." << std::endl;}
        /**Pour atterrir au sol*/
        virtual void atterrissageSol(){std::cout << "Action impossible." << std::endl;}
        /**Pour atterir sur l'eau*/
        virtual void atterrissageEau(){std::cout << "Action impossible." << std::endl;}
        /**Pour modifier l'affichage des actions possibles en fonction des �tats */
        virtual void choix(){}
        /**V�rifie que le d�placement est possible en fonction des obstacles
            \return un bool�en vrai si on peut passer
        */
        virtual bool autorisation(int){return true;}
        /**\brief Fonction de test.
            Affiche l'�tat
        */
        virtual void aff(){std::cout<<"par d�faut"<<std::endl;}
};

#endif // ETAT_HPP
