#ifndef ETATENVOL_HPP
#define ETATENVOL_HPP

#include "Etat.hpp"
#include "Canard.hpp"

class EtatEnVol : public Etat
{
    private:
        Canard* canard_;
    public:
        EtatEnVol();
        EtatEnVol(Canard* can);
        virtual ~EtatEnVol();
        Canard* getCanard() { return canard_; }
        void setCanard(Canard* val) { canard_ = val; }
        void atterrissageSol(); //change l'état en vol à etat au sol
        void atterrissageEau(); //change l'état en vol à etat sur l'eau

        void choix();
        bool autorisation(int x);

        virtual void aff(){std::cout<<"en Vol"<<std::endl;}

    protected:
};

#endif // ETATENVOL_HPP
