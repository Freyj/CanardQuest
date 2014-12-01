#ifndef ETATENVOL_HPP
#define ETATENVOL_HPP

#include "Etat.hpp"
#include "Canard.hpp"
/**La classe EtatEnVol est une implémentation concrète de la classe Etat représentant l'état du canard en vol.*/
class EtatEnVol : public Etat
{
    private:
        /**Pointeur vers Canard*/
        Canard* canard_;
    public:
        /**Constructeur de base*/
        EtatEnVol();
        /**Constructeur avec un canard en paramètre
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
            \param un pointeur vers Canard
        */
        void setCanard(Canard* val) { canard_ = val; }
        /** \brief Air->Sol.
            modifie l'état dans l'eau en vol au sol
        */
        void atterrissageSol();
        void atterrissageEau(); //change l'état en vol à etat sur l'eau

        void choix();
        bool autorisation(int  );

        virtual void aff(){std::cout<<"en Vol"<<std::endl;}

    protected:
};

#endif // ETATENVOL_HPP
