#include "Creature.hpp"

/**
Renvoie un string avec le nom de la créature.
*/
std::string Creature::getNom()
{
	return this->nom_;
}

/**
Permet d'affecter un string nom comme nouveau nom de la créature
*/
void Creature::setNom(std::string nom)
{
	this->nom_ = nom;
}
/** 
Renvoie un entier représentant la position de la créature
*/
int Creature::getPos()
{
	return this->pos_;
}

/**
Permet de définir un entier p comme nouvelle position de la créature
*/
void Creature::setPos(int p)
{
	this->pos_ = p;
}

void Creature::setEtatCourant(int i)
{
	etatCourant = i;
}

int Creature::getEtatCourant()
{
	return this->etatCourant;
}

int Creature::getEtatVivant()
{
	return etatVivant;
}

int Creature::getEtatMort()
{
	return etatMort;
}