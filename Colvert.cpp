#include <iostream>
#include "Colvert.hpp"
#include "EtatAuSol.hpp"
#include "EtatEnVol.hpp"
#include "EtatSurEau.hpp"


Colvert::Colvert(std::string nom) : Canard(nom)
{

}

Colvert::~Colvert()
{
}

/**
Fonction renvoyant un string représentant l'objet, pour tests.
*/
std::string Colvert::presentation()
{
	return "Tu es un fier colvert mais tu es seul à présent, tu dois donc te débrouiller pour survivre. La vie est un éternel combat pour la survie.";
}
