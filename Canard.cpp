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
	//^ 0
	//> 1
	//v 2
	//< 3
	if (a == 0)
	{
		this->pos_ -=16;
	}
	else if (a == 1)
	{
		this->pos_ +=1;
	}
	else if (a == 2)
	{
		this->pos_ +=16;
		//std::cout << "TESTING FOR ERRORS" << std::endl;
	}
	else if (a == 3)
	{
		this->pos_ -=1;
	}
	else
	{
		std::cout << "Déplacement dans cette direction impossible.";
	}
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
