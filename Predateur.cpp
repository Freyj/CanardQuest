#include "Predateur.hpp"
#include <iostream>
#include <string>

Predateur::Predateur(std::string nom) : Creature(nom, 0)
{

}

Predateur::Predateur(std::string nom, int pos): Creature(nom, pos)
{

}

Predateur::~Predateur()
{
}

std::string Predateur::presentation()
{
	return "Je suis un prédateur. Grrr.";
}