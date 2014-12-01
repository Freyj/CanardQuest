#ifndef ETATENVOL_HPP
#define ETATENVOL_HPP

#include "Etat.hpp"
#include "Canard.hpp"
/**La classe EtatEnVol est une impl�mentation concr�te de la classe Etat repr�sentant l'�tat du canard en vol.*/
class EtatEnVol : public Etat
{
    private:
        /**Pointeur vers Canard*/
        Canard* canard_;
    public:
        /**Constructeur de base*/
        EtatEnVol();
        /**Constructeur avec un canard en param�tre
            \param can pointeur vers Canard
        */
        EtatEnVol(Canard* can);
        /**Destructeur*/
        virtual ~EtatEnVol();
        /**\brief Getter du canard.
            Renvoie le canard
            \return un pointeur vers Canard
        */
        Canard* getCanard() { return canard_; }
        /**\brief Setter du canard.
            Affecte  le canard
            \param val un pointeur vers Canard
        */
        void setCanard(Canard* val) { canard_ = val; }
        /** \brief Air->Sol.
            modifie l'�tat dans l'eau en vol au sol
        */
        void atterrissageSol();
        /** \brief Air->Sol.
            modifie l'�tat dans l'eau en �tat en vol
        */
        void atterrissageEau();

        /**Pour modifier l'affichage des actions possibles en mettant atterrir */
        void choix();
        /**V�rifie que le d�placement est possible en fonction des obstacles
            \param x int de position
            \return un bool�en vrai si on peut passer
        */
        bool autorisation(int x);
        /**\brief Fonction de test.
            Affiche l'�tat
        */
        virtual void aff(){std::cout<<"en Vol"<<std::endl;}
};

#endif // ETATENVOL_HPP
