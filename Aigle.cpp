#include <string>
#include "Aigle.hpp"
#include <iostream>
#include <random>

Aigle::Aigle() : Predateur("aigle", 110)/*placement totalement hasardeux !*/
{
	
}

Aigle::~Aigle()
{

}

std::string Aigle::presentation()
{
	return("Je suis un aigle !");
}

//créer une mathode adjacent pour que l'aigle puisse attaquer le canard si il est sur la case à coter.
//c'est quand meme le prédateur ultime quoi ...

void Aigle::tuer(Canard can)
{
	if(this->getPos() == can.getPos())
	{
		can.setEtatCourant(can.getEtatMort());
		std::cout << "Un aigle fond sur sa proie, et il se trouve que cette proie c'est toi !" << std::endl;
	}
	else
	{
		/*
		On crée l'aléatoire (cf cplusplus.com/reference/random)
		*/
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(0,255);
		/*
		choisi une nouvelle position où faire apparaitre l'aigle (comme il vole, on considère qu'il peut arriver n'importe où)
		*/
		this->setPos(distribution(generator));
	}
}