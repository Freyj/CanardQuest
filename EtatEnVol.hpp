#ifndef ETATENVOL_HPP
#define ETATENVOL_HPP

#include "Etat.hpp"
#include "Canard.hpp"

class EtatEnVol : public Etat
{
    private:
        Canard* canard_;
    public:
        EtatEnVol(Canard* can);
        virtual ~EtatEnVol();
        Canard* getCanard() { return canard_; }
        void setCanard(Canard* val) { canard_ = val; }
        void onWater();         //ne modifie pas l'�tat
        void offWater();        //ne modifie pas l'�tat
        void decollageSol();    //ne modifie pas l'�tat
        void decollageEau();    //ne modifie pas l'�tat
        void atterrissageSol(); //change l'�tat en vol � etat au sol
        void atterrissageEau(); //change l'�tat en vol � etat sur l'eau
    protected:
};

#endif // ETATENVOL_HPP
