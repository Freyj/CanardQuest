#include "Canard.hpp"
#include <iostream>

Canard::Canard(std::string nom):Creature(nom, 101),faim(5)
{
}

Canard::~Canard()
{
}


void Canard::manger()
{
    faim += 5;
}

int Canard::getFaim()
{
	return faim;
}

void Canard::setFaim(int n)
{
	faim = n;
}

void Canard::statut()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    if (getFaim()>1)
    {
    	std::cout << "Tu as encore " << getFaim() << " tours avant de mourir de faim.\n" << std::endl;
    }
    else
    {
    	std::cout << "C'est ton dernier tour avant de mourir de faim !\n" << std::endl;
    }
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    if(this->voler())
    {
        std::cout << "Mais ! Tu as des ailes ! Tu pouvais voler depuis tout ce temps ?" << std::endl;
        std::cout << "Et tes pattes ! Elles sont palmés, tu sais donc nager !" << std::endl;
        std::cout << "Pourquoi ne pas l'avoir dit plus tot ?" << std::endl;
    }
}

std::string Canard::presentation()
{
    return "Juste un mot, PRESENTATION .";
}

/**
Méthode qui fait cancaner le canard
*/
bool Canard::cancaner()
{
    return compCan->cancaner();
}

/**
Méthode qui va chercher dans le comportement du Canard
pour déterminer la nage
*/
bool Canard::nager()
{
	return compNage->nager();
}

/**
Méthode qui va chercher dans le comportement du Canard
pour déterminer le vol
*/
bool Canard::voler()
{
	return compVol->voler();
}

CompetenceVol* Canard::getCompVol()
{
	return compVol;
}

void Canard::setCompVol(CompetenceVol* c)
{
    delete compVol;
	compVol = c;
}

CompetenceCancan* Canard::getCompCan()
{
	return compCan;
}

void Canard::setCompCan(CompetenceCancan* c)
{
    delete compCan;
	compCan = c;
}

CompetenceNage* Canard::getCompNage()
{
	return compNage;
}

void Canard::setCompNage(CompetenceNage* c)
{
    delete compNage;
	compNage = c;
}


Etat* Canard::getEtatAuSol()
{
    return etatAuSol_;
}
Etat* Canard::getEtatEnVol()
{
    return etatEnVol_;
}

Etat* Canard::getEtatSrEau()
{
    return etatSrEau_;
}

Etat* Canard::getEtat()
{
	return etat_;
}

void Canard::setEtat(Etat* e)
{
    delete etat_;
    etat_ = e;
}

bool Canard::estVivant()
{
	return (etatCourant != this->getEtatVivant() || faim == 0)? false:true;
}

void Canard::vol_Sol()
{
    etat_->atterrissageSol();
}

void Canard::vol_Eau()
{
    etat_->atterrissageEau();
}

void Canard::eau_Vol()
{
        etat_->decollageEau();
}

void Canard::eau_Sol()
{
    etat_->offWater();
}

void Canard::sol_Eau()
{
    if(this->nager())
    {
        etat_->onWater();
    }
}

void Canard::sol_Vol()
{
    if(this->voler())
    {
        etat_->decollageSol();
    }
}

