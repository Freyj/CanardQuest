#include "Creature.hpp"

std::string Creature::getNom()
{
	return this->nom_;
}

void Creature::setNom(std::string nom)
{
	this->nom_ = nom;
}

int Creature::getPos()
{
	return this->pos_;
}

void Creature::setPos(int p)
{
	this->pos_ = p;
}