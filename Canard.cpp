#include "Canard.hpp"
#include <iostream>

Canard::Canard(std::string nom):Creature(nom, 101),faim(5)//milieu de la carte == 128
{
    this->compVol = new CompetenceVolDisable();
    this->compCan = new CompetenceCancanDisable();
    this->compNage = new CompetenceNageDisable();
    this->etatAuSol_ = new EtatAuSol(this);
    this->etatEnVol_ = new EtatEnVol(this);
    this->etatSrEau_ = new EtatSurEau(this);
    this->etat_ = etatAuSol_;
}

Canard::~Canard()
{
    compNage = NULL;
    compCan = NULL;
    compVol = NULL;
    etatAuSol_ = NULL;
    etatEnVol_ = NULL;
    etatSrEau_ = NULL;
    delete compNage;
    delete compCan;
    delete compVol;
    delete etatAuSol_;
    delete etatEnVol_;
    delete etatSrEau_;
    delete etat_;
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
    if (getFaim()>1)
    {
    	std::cout << "Tu as encore " << getFaim() << " tours avant de mourir de faim.\n" << std::endl;
    }
    else
    {
    	std::cout << "C'est ton dernier tour avant de mourir de faim !\n" << std::endl;
    }
}

std::string Canard::presentation()
{
    return "Juste un mot, PRESENTATION .";
}

bool Canard::cancaner()
{
    return compCan->cancaner();
}


bool Canard::nager()
{
	return compNage->nager();
}


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
    etat_ = NULL;
    delete etat_;
    etat_ = e;
}

void Canard::afficherEtat()
{
    std::cout<<"Je suis dans l'état: ";
    etat_->aff();
}

bool Canard::estVivant()
{
	return (etatCourant != this->getEtatVivant() || faim == 0)? false:true;
}

void Canard::choix()
{
    etat_->choix();
}

bool Canard::autorisation(int x)
{
    return etat_->autorisation(x);
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