#include <iostream>
#include "CompetenceVolDisable.hpp"
#include "CompetenceCancanDisable.hpp"
#include "CompetenceNageDisable.hpp"
#include "Colvert.hpp"


Colvert::Colvert(std::string nom) : Canard(nom)
{
    this->compVol = new CompetenceVolDisable();
    this->compCan = new CompetenceCancanDisable();
	this->compNage = new CompetenceNageDisable();
}

Colvert::~Colvert()
{
	delete compNage;
    delete compCan;
    delete compVol;
}

/**
Fonction renvoyant un string repr�sentant l'objet, pour tests.
*/
std::string Colvert::presentation()
{
	return "Tu es un fier Colvert mais tu es seul � pr�sent, tu dois donc te d�brouiller pour survivre. Qui sait ? Des renfort arriverons peut etre ? Mouhahaha !";
}
