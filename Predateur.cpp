#include "Predateur.hpp"
#include <iostream>
#include <string>

Predateur::Predateur(std::string nom) : Creature(nom, 0)
{

}

/**
Constructeur de prédateur qui prend un string pour modifier le nom
de la créature et un int pour initialiser sa position.
*/
Predateur::Predateur(std::string nom, int pos): Creature(nom, pos)
{

}

Predateur::~Predateur()
{
}

/**
Fonction renvoyant un string représentant l'objet, pour tests.
*/
std::string Predateur::presentation()
{
	return "Je suis un prédateur. Grrr.";
}

/**
Fonction gérant le déplacement du prédateur

void Predateur::deplacement(int a)
{

}
*/
