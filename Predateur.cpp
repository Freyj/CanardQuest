#include "Predateur.hpp"
#include <iostream>
#include <string>
/**
Constructeur de prédateur qui prend un string pour modifier le nom
de la créature
*/
Predateur::Predateur(std::string nom): Creature(nom)
{
	
}
/**
Constructeur alternatif donnant un nom et une position à la créature
*/
Predateur::Predateur(std::string nom, int p): Creature(nom)
{
	this->pos_ = p;
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
*/
void Predateur::deplacement(int a)
{
	
}