#ifndef ETATSUREAU_HPP
#define ETATSUREAU_HPP

#include "Etat.hpp"
#include "Canard.hpp"

class EtatSurEau : public Etat
{
    private:
        Canard* canard_;
    public:
        EtatSurEau(Canard* can);
        virtual ~EtatSurEau();
        Canard* getCanard_() { return canard_; }
        void setCanard_(Canard* val) { canard_ = val; }
        void onWater();         //aucune modification
        void offWater();        //modifie l'�tat sur l'eau en �tat au sol
        void decollageSol();    //aucune modification
        void decollageEau();    //modifie l�tat sur l'eau en �tat en vol
        void atterrissageSol(); //aucune modification
        void atterrissageEau(); //aucune modification
    protected:
};

#endif // ETATSUREAU_HPP
