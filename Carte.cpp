#include "Carte.hpp"
#include <iostream>

Carte::Carte()
{
	this->tab_ = new int[256];
}

Carte::~Carte()
{
	delete[] this->tab_;
}

void Carte::creerCarte()
{
	
}