#include "Canard.hpp"
#include <iostream>

//Canard::Canard(std::string nom):Creature(nom), Creature::pos_(101), faim(5)
//{
//	//this->setPos(101); //à peu près le milieu de la carte
//	//this->setFaim(5);
//}

Canard::~Canard()
{
}


void Canard::manger()
{
	faim += 5;
	std::cout << "\n---------------------------------------------------\n" << std::endl;
	std::cout << "Tu manges des graines." << std::endl;
}

std::string Canard::presentation()
{
	return "Tu es un canard qui cancanne.";
}

void Canard::nager()
{

}

void Canard::cancaner()
{
	this->comp->cancaner();
}

void Canard::voler()
{
	this->comp->voler();
}

int Canard::getFaim()
{
    return this->faim;
}

void Canard::setFaim(int n)
{
    this->faim = n;
}

bool Canard::estMort()
{
	return ((this->getFaim() == 0) && this->getEtatCourant()== 0);
}

void Canard::statut()
{
    std::cout << "\n---------------------------------------------------\n" << std::endl;
    if (getFaim()>1)
    {
    	std::cout << "Tu as encore " << getFaim()-1 << " tours avant de mourir de faim.\n" << std::endl;
    }
    else
    {
    	std::cout << "C'est ton dernier tour avant de mourir de faim !\n" << std::endl;
    }
}

