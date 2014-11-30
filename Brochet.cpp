#include "Brochet.hpp"

Brochet::Brochet(int a) : PredateurEau("brochet", a)
{
}

Brochet::~Brochet()
{
}

void Brochet::tuer(Canard* can)
{
	if (this->getPos() == can->getPos())
	{
		can->setEtatCourant(can->getEtatMort());
		std::cout << "Un renard t'a attrap�, tu es son nouveau go�ter." << std::endl;
	}
}
