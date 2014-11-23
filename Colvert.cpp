#include <iostream>
#include "Colvert.hpp"


Colvert::Colvert(std::string nom) : Canard(nom)
{
    this->compVol = new CompetenceVolDisable();
    this->compCan = new CompetenceCancanDisable();
	this->compNage = new CompetenceNageDisable();
	this->etatAuSol_ = new EtatAuSol(this);
	this->etatEnVol_ = new EtatEnVol(this);
    this->etatSrEau_ = new EtatSurEau(this);
	this->etat_ = new EtatAuSol(this);
}

Colvert::~Colvert()
{
	delete compNage;
    delete compCan;
    delete compVol;
    delete etatAuSol_;
    delete etatEnVol_;
    delete etatSrEau_;
    delete etat_;
}

/**
Fonction renvoyant un string représentant l'objet, pour tests.
*/
std::string Colvert::presentation()
{
	return "Tu es un fier Colvert mais tu es seul à présent, tu dois donc te débrouiller pour survivre. Qui sait ? Des renfort arriverons peut etre ? Mouhahaha !";
}
