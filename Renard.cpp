#include <string>
#include "Renard.hpp"
#include <iostream>
#include <random>

Renard::Renard(int a) : Predateur("renard", a)
{

}

Renard::~Renard()
{

}

std::string Renard::presentation()
{
	return ("Je suis un renard !");
}


void Renard::tuer(Canard* can)
{
	if (this->getPos() == can->getPos())
	{
		can->setEtatCourant(can->getEtatMort());
		std::cout << "Un renard t'a attrapé, tu es son nouveau goûter." << std::endl;
	}
}
