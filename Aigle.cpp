#include <string>
#include "Aigle.hpp"
#include <iostream>
#include <random>

Aigle::Aigle() : PredateurVol("aigle", 110)/*placement totalement hasardeux !*/
{
}

Aigle::~Aigle()
{
}

std::string Aigle::presentation()
{
	return("Je suis un aigle ! Le prédateur ultime !");
}

//créer une mathode adjacent pour que l'aigle puisse attaquer le canard si il est sur la case à coter.
//c'est quand meme le prédateur ultime quoi ...

void Aigle::tuer(Canard* can)
{
	if(this->getPos() == can->getPos())
	{
		can->setEtatCourant(can->getEtatMort());
		std::cout << "Un aigle fond sur sa proie, et il se trouve que cette proie c'est toi !" << std::endl;
	}
	else
	{
		std::random_device rd;//nouvelle methode pour l'aléatoire, merci Charles-Eric! [Meilleure car elle prend le temps passé sur le système depuis une certaine date]
		
		/*
		choisi une nouvelle position où faire apparaitre l'aigle (comme il vole, on considère qu'il peut arriver n'importe où)
		*/
		this->setPos(rd()%256);
	}
}
