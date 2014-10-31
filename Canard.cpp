#include "Canard.hpp"
#include <iostream>

Canard::Canard(std::string nom)
{
	this->nom_ = nom;
	this->pos_ = 101; //à peu près le milieu de la carte
}

Canard::~Canard()
{
}

void Canard::deplacement(int a) 
{
}

void Canard::manger()
{
}

std::string Canard::presentation() 
{
	return "Tu es un canard qui cancanne.";
}
void Canard::cancaner()
{
	std::cout << "Coin. Coin." << std::endl;
}