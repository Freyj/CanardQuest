#include "EtatSurEau.hpp"
#include <iostream>


EtatSurEau::EtatSurEau():Etat(){}

EtatSurEau::EtatSurEau(Canard* can): Etat(), canard_(can)
{

}

EtatSurEau::~EtatSurEau()
{
}

void EtatSurEau::offWater()
{
    std::cout << "Tu sors de l'eau." << std::endl;
    canard_->setEtat(canard_->getEtatAuSol());
}//modifie l'�tat sur l'eau en �tat au sol

void EtatSurEau::decollageEau()
{
    std::cout << "Tu t'envole !" << std::endl;
    canard_->setEtat(canard_->getEtatEnVol());
}//modifie l�tat sur l'eau en �tat en vol

void EtatSurEau::choix()
{
    std::cout << "v : pour voler\n";
}

bool EtatSurEau::autorisation(int x)
{
    if(x==5 || x==2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
