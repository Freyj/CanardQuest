#include "EtatAuSol.hpp"
#include <iostream>

EtatAuSol::EtatAuSol(Canard* can): Etat(), canard_(can)
{
    std::cout << "Jesuis le constructeru de l'etat au sol\n";
}

EtatAuSol::~EtatAuSol()
{
    delete canard_;
}

void EtatAuSol::onWater()
{
    std::cout << "Tu va sur l'eau." << std::endl;
    canard_->setEtat(canard_->getEtatSrEau());
}//modifie l'�tat au sol en �tat sur l'eau

void EtatAuSol::offWater()
{
    std::cout << "Action impossible." << std::endl;

}//aucune modification
void EtatAuSol::decollageSol()
{
    std::cout << "Tu t'envole !" << std::endl;
    canard_->setEtat(canard_->getEtatEnVol());
}//modifie l�tat au sol en �tat en vol

void EtatAuSol::decollageEau()
{
    std::cout << "Action impossible." << std::endl;
}//aucune modification

void EtatAuSol::atterrissageSol()
{
    std::cout << "Action impossible." << std::endl;
}//aucune modification

void EtatAuSol::atterrissageEau()
{
    std::cout << "Action impossible." << std::endl;
}//aucune modification
