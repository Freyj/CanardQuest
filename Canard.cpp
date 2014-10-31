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
int Canard::getPos()
{
	return this->pos_;
}
void Canard::setPos(int p)
{
	this->pos_ = p;
}