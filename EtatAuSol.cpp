#include "EtatAuSol.hpp"
#include "Canard.hpp"
#include <iostream>

EtatAuSol::EtatAuSol():Etat(){}

EtatAuSol::EtatAuSol(Canard* can): Etat(), canard_(can)
{

}

EtatAuSol::~EtatAuSol()
{
}

void EtatAuSol::onWater()
{
    std::cout << "Tu va sur l'eau." << std::endl;
    std::cout<<"ahahah"<<std::endl;
    canard_->setEtat(canard_->getEtatSrEau());
    std::cout<<"ahahah"<<std::endl;
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
    else
    {
        return true;
    }
}
