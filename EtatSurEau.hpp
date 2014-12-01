#ifndef ETATSUREAU_HPP
#define ETATSUREAU_HPP

#include "Etat.hpp"
#include "Canard.hpp"
/**La classe EtatSurEau est une impl�mentation concr�te de la classe Etat repr�sentant l'�tat du canard sur l'eau.*/
class EtatSurEau : public Etat
{
    private:
        /**Pointeur vers Canard*/
        Canard* canard_;
    public:
        /**Constructeur de base*/
        EtatSurEau();
        /**Constructeur avec un canard en param�tre
            \param can pointeur vers Canard
        */
        EtatSurEau(Canard* can);
        /**Destructeur*/
        virtual ~EtatSurEau();
        /**\brief Getter du canard.
            Renvoie le canard
            \return un pointeur vers Canard
        */
        Canard* getCanard_() { return canard_; }
        /**\brief Setter du canard.
            Affecte  le canard
            \param val un pointeur vers Canard
        */
        void setCanard_(Canard* val) { canard_ = val; }
        /** \brief Eau->Sol.
            modifie l'�tat dans l'eau en �tat au sol
        */
        void offWater();  
        /** \brief Eau->Air.
            modifie l'�tat dans l'eau en �tat en vol
        */
        void decollageEau(); 

        /**Pour modifier l'affichage des actions possibles en mettant voler */
        void choix();
        /**V�rifie que le d�placement est possible en fonction des obstacles
            \param x  int de position
            \return un bool�en vrai si on peut passer
        */
        bool autorisation(int x);
        /**\brief Fonction de test.
            Affiche l'�tat
        */
        virtual void aff(){std::cout<<"sur Eau"<<std::endl;}

};

#endif // ETATSUREAU_HPP
