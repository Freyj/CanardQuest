#include "EtatEnVol.hpp"
#include <iostream>

EtatEnVol::EtatEnVol(Canard* can) : Etat(), canard_(can)
{

}

EtatEnVol::~EtatEnVol()
{
    delete canard_;
}

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

void EtatEnVol::choix()
{
    std::cout << "a : pour atterrir\n";
}

bool EtatEnVol::autorisation(int )
{
    return true;
}