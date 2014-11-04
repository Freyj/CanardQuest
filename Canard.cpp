#include "Canard.hpp"
#include <iostream>

Canard::Canard(std::string nom):Creature(nom)
{
	this->setPos(101); //à peu près le milieu de la carte
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
		if (this->getPos() < 16)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else 
		{
			this->setPos(this->getPos()-16);
		}
		
	}
	else if (a == 1)
	{
		if ((this->getPos() == 255) || (this->getPos()%16 == 15))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else
		{
			this->setPos(this->getPos()+1);
		}
	}
	else if (a == 2)
	{
		if (this->getPos() > 239)
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else 
		{
			this->setPos(this->getPos()+16);
		}
		
	}
	else if (a == 3)
	{
		if ((this->getPos() <1) || (this->getPos()%16 == 0))
		{
			std::cout << "Déplacement hors carte interdit. Vilain canard ! " << std::endl;
		}
		else 
		{
			this->setPos(this->getPos()-1);
		}
	}
	else
	{
		std::cout << "Erreur d'entrée, déplacement impossible.";
	}
}

void Canard::manger()
{
	faim = 5;
}

std::string Canard::presentation()
{
	return "Tu es un canard qui cancanne.";
}
void Canard::cancaner()
{
	std::cout << "Coin. Coin." << std::endl;
}

int Canard::getFaim()
{
    return this->faim;
}

void Canard::setFaim(int n)
{
    this->faim = n;
}

bool Canard::estVivant()
{
	return (!((this->getFaim() == 0) && this->getEtatCourant()== 0));
}