#ifndef ETATAUSOL_H
#define ETATAUSOL_H

#include "Canard.hpp"
#include "Etat.hpp"
/**La classe EtatAuSol est une implémentation concrète de la classe Etat représentant l'état du canard au sol.*/
class EtatAuSol : public Etat
{
    private:
        /**Pointeur vers Canard*/
        Canard* canard_;
    public:
        /**Constructeur de base*/
        EtatAuSol();
        /**Constructeur avec un canard en paramètre
            \param can pointeur vers Canard
        */
        EtatAuSol(Canard* can);
        /**Destructeur*/
        virtual ~EtatAuSol();
        /**\brief Getter du canard.
            Renvoie le canard
            \return un pointeur vers Canard
        */
        Canard* getCanard_() { return canard_; }
        /**\brief Setter du canard.
            Affecte  le canard
            \param un pointeur vers Canard
        */
        void setCanard_(Canard* val) { canard_ = val; }
        /** \brief Sol->Eau.
            modifie l'état au sol en état sur l'eau
        */
        void onWater();
        /** \brief Sol->Air.
            modifie l'état au sol en état en vol
        */
        void decollageSol();    
        /**Pour modifier l'affichage des actions possibles en mettant voler */
        void choix();
        /**Vérifie que le déplacement est possible en fonction des obstacles
            \param int position
            \return un booléen vrai si on peut passer
        */
        bool autorisation(int x);
        /**\brief Fonction de test.
            Affiche l'état
        */
        virtual void aff(){std::cout<<"au Sol"<<std::endl;}
};

#endif // ETATAUSOL_H
