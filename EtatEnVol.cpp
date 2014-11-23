#include "EtatEnVol.hpp"
#include <iostream>

EtatEnVol::EtatEnVol(Canard* can) : Etat(), canard_(can)
{
    std::cout << "Jesuis le constructeru de l'etat en vol\n";
}

EtatEnVol::~EtatEnVol()
{
    delete canard_;
}


void EtatEnVol::onWater()
{
    std::cout << "Action impossible." << std::endl;
}//ne modifie pas l'état

void EtatEnVol::offWater()
{
    std::cout << "Action impossible." << std::endl;

}//ne modifie pas l'état

void EtatEnVol::decollageSol()
{
    std::cout << "Action impossible." << std::endl;
}//ne modifie pas l'état

void EtatEnVol::decollageEau()
{
    std::cout << "Action impossible." << std::endl;
}//ne modifie pas l'état

void EtatEnVol::atterrissageSol()
{
    std::cout << "Tu atterris sur le sol." << std::endl;
    canard_->setEtat(canard_->getEtatAuSol());
}//change l'état en vol à etat au sol

void EtatEnVol::atterrissageEau()
{
    std::cout << "Tu atterris sur de l'eau." << std::endl;
    canard_->setEtat(canard_->getEtatSrEau());
}//change l'état en vol à etat sur l'eau
