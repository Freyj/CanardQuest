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
        void onWater();         //ne modifie pas l'état
        void offWater();        //ne modifie pas l'état
        void decollageSol();    //ne modifie pas l'état
        void decollageEau();    //ne modifie pas l'état
        void atterrissageSol(); //change l'état en vol à etat au sol
        void atterrissageEau(); //change l'état en vol à etat sur l'eau
    protected:
};

#endif // ETATENVOL_HPP
