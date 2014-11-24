#include "EtatSurEau.hpp"
#include <iostream>

EtatSurEau::EtatSurEau(Canard* can): Etat(), canard_(can)
{

}

EtatSurEau::~EtatSurEau()
{
    delete canard_;
}

void EtatSurEau::offWater()
{
    std::cout << "Tu sors de l'eau." << std::endl;
    canard_->setEtat(canard_->getEtatAuSol());
}//modifie l'état sur l'eau en état au sol

void EtatSurEau::decollageEau()
{
    std::cout << "Tu t'envole !" << std::endl;
    canard_->setEtat(canard_->getEtatEnVol());
}//modifie létat sur l'eau en état en vol

void EtatSurEau::choix()
{
    std::cout << "v : pour voler\n";
}

bool EtatSurEau::autorisation(int x)
{
    if(x==5)
    {
        return false;
    }
    else if (x==3 || x==4 || x==6)
    {
        offWater();
        return true;
    }
    else
    {
        return true;
    }
}
