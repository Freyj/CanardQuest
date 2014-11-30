#include "Predateur.hpp"
#include <iostream>
#include <string>

/**
Constructeur de prédateurSol qui prend un string pour modifier le nom
de la créature et un int pour initialiser sa position.
*/
PredateurSol::PredateurSol(std::string nom, int pos): Creature(nom, pos)
{
    this->etatPred_ = new EtatAuSol();
}
PredateurSol::~PredateurSol()
{
    delete etatPred_;
    etatPred_ = NULL;
}

/**
Fonction renvoyant un string représentant l'objet, pour tests.
*/
std::string PredateurSol::presentation()
{
	return "Je suis un prédateur terrestre, j'attaque mes proies quand elles sont au sol. Grrr.";
}

/**
Constructeur de prédateurVol qui prend un string pour modifier le nom
de la créature et un int pour initialiser sa position.
*/
PredateurVol::PredateurVol(std::string nom, int pos): Creature(nom, pos)
{
    this->etatPred_ = new EtatEnVol();
}
PredateurVol::~PredateurVol()
{
    delete etatPred_;
    etatPred_ = NULL;
}

/**
Fonction renvoyant un string représentant l'objet, pour tests.
*/
std::string PredateurVol::presentation()
{
	return "Je suis un prédateur Aérien, je tue mes cibles Depuis les airs. Crôa.";
}

/**
Constructeur de prédateurEau qui prend un string pour modifier le nom
de la créature et un int pour initialiser sa position.
*/
PredateurEau::PredateurEau(std::string nom, int pos): Creature(nom, pos)
{
    this->etatPred_ = new EtatSurEau();
}
PredateurEau::~PredateurEau()
{
    delete etatPred_;
    etatPred_ = NULL;
}

/**
Fonction renvoyant un string représentant l'objet, pour tests.
*/
std::string PredateurEau::presentation()
{
	return "Je suis un prédateur aquatique, je manges mes repas Lorsqu'elles s'aventurent sur l'eau. Bloup.";
}
