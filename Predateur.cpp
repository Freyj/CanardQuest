#include "Predateur.hpp"
#include <iostream>
#include <string>

Predateur::Predateur(std::string nom)
{
	this->nom_ = nom;
}

Predateur::~Predateur()
{
}

std::string Predateur::presentation()
{
	return "Je suis un prédateur. Grrr.";
}

void Predateur::deplacement(int a)
{
	
}