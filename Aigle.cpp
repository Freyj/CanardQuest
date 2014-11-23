#include <string>
#include "Aigle.hpp"
#include <iostream>
#include <random>

Aigle::Aigle() : Predateur("aigle", 101)/*placement totalement hasardeux !*/
{
	
}

Aigle::~Aigle()
{

}

std::string Aigle::presentation()
{
	return("Je suis un aigle !");
}

void Aigle::tuer(Canard can)
{
	if(this->getPos() == can.getPos())
	{
		can.setEtatCourant(0);
	}
	else
	{
		/*
		On crée l'aléatoire (cf cplusplus.com/reference/random)
		*/
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(0,255);
		/*
		choisi une nouvelle position où faire pop l'aigle
		*/
		this->setPos(distribution(generator));
	}
}