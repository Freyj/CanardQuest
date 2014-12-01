#include "Brochet.hpp"

Brochet::Brochet(int a) : PredateurEau("brochet", a)
{
}

Brochet::~Brochet()
{
}

std::string Brochet::presentation()
{
	return ("Je suis un brochet ! un vil pr�dateur sous-marin !\nJe suis a la position : ");
}

void Brochet::tuer(Canard* can)
{
	if (this->getPos() == can->getPos())
	{
		//can->setEtatCourant(can->getEtatMort());
		//std::cout << "Un brochet s�vit dans ces eaux, tu le sais d�j� ? oups." << std::endl;
		std::cout << presentation() << std::endl;
	}
}
