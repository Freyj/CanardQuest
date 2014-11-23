#include "EtatSurEau.hpp"
#include <iostream>

EtatSurEau::EtatSurEau(Canard* can): Etat(), canard_(can)
{
    std::cout << "Jesuis le constructeru de l'etat sur l'eau\n";
}

EtatSurEau::~EtatSurEau()
{
    delete canard_;
}
void EtatSurEau::onWater()
{
    std::cout << "Action impossible." << std::endl;
}//aucune modification

void EtatSurEau::offWater()
{
    std::cout << "Tu sors de l'eau." << std::endl;
    canard_->setEtat(canard_->getEtatAuSol());
}//modifie l'état sur l'eau en état au sol

void EtatSurEau::decollageSol()
{
    std::cout << "Action impossible." << std::endl;
}//aucune modification

void EtatSurEau::decollageEau()
{
    std::cout << "Tu t'envole !" << std::endl;
    canard_->setEtat(canard_->getEtatEnVol());
}//modifie létat sur l'eau en état en vol

void EtatSurEau::atterrissageSol()
{
    std::cout << "Action impossible." << std::endl;
}//aucune modification

void EtatSurEau::atterrissageEau()
{
    std::cout << "Action impossible." << std::endl;
}//aucune modification
