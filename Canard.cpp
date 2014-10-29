#include "Canard.hpp"
#include <iostream>

Canard::Canard(std::string nom)
{
	this->nom_ = nom;
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

std::string Canard::getNom()
{
	return this->nom_;
}

void Canard::setNom(std::string nom)
{
	this->nom_ = nom;
}
void Canard::cancaner()
{
	std::cout << "Coin. Coin." << std::endl;
}