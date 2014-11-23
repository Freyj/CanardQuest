#ifndef ETATAUSOL_H
#define ETATAUSOL_H

#include "Canard.hpp"
#include "Etat.hpp"

class EtatAuSol : public Etat
{
    private:
        Canard* canard_;
    public:
        EtatAuSol(Canard* can);
        virtual ~EtatAuSol();
        Canard* getCanard_() { return canard_; }
        void setCanard_(Canard* val) { canard_ = val; }
        void onWater();         //modifie l'état au sol en état sur l'eau
        void offWater();        //aucune modification
        void decollageSol();    //modifie létat au sol en état en vol
        void decollageEau();    //aucune modification
        void atterrissageSol(); //aucune modification
        void atterrissageEau(); //aucune modification
    protected:
};

#endif // ETATAUSOL_H
