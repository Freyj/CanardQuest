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
        void offWater();        //modifie l'état sur l'eau en état au sol
        void decollageEau();    //modifie létat sur l'eau en état en vol

        void choix();
        bool autorisation(int x);

        virtual void aff(){std::cout<<"sur Eau"<<std::endl;}

    protected:
};

#endif // ETATSUREAU_HPP
