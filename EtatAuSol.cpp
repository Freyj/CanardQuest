#include "EtatAuSol.hpp"
#include "Canard.hpp"
#include <iostream>

EtatAuSol::EtatAuSol(Canard* can): Etat(), canard_(can)
{

}

EtatAuSol::~EtatAuSol()
{
    delete canard_;
}

void EtatAuSol::onWater()
{
    std::cout << "Tu va sur l'eau." << std::endl;
    canard_->setEtat(canard_->getEtatSrEau());
}//modifie l'état au sol en état sur l'eau

void EtatAuSol::decollageSol()
{
    std::cout << "Tu t'envole !" << std::endl;
    canard_->setEtat(canard_->getEtatEnVol());
}//modifie létat au sol en état en vol

void EtatAuSol::choix()
{
    std::cout << "v : pour voler\n";
}

bool EtatAuSol::autorisation(int x)
{
    if(x==2 || x==5)
    {
        return false;
    }
    else if (x==1)
    {
        onWater();
        return true;
    }
    else
    {
        return true;
    }
}
