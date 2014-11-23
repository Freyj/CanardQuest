#include "Canard.hpp"
#include <iostream>

Canard::Canard(std::string nom):Creature(nom, 101),faim(5)
{
}

Canard::~Canard()
{
}


void Canard::manger()
{
    faim += 5;
}

int Canard::getFaim()
{
	return faim;
}

void Canard::setFaim(int n)
{
	faim = n;
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

std::string Canard::presentation()
{
    return "Juste un mot, PRESENTATION .";
}

/**
Méthode qui fait cancaner le canard
*/
bool Canard::cancaner()
{
    return compCan->cancaner();
}

/**
Méthode qui va chercher dans le comportement du Canard
pour déterminer la nage
*/
bool Canard::nager()
{
	return compNage->nager();
}

/**
Méthode qui va chercher dans le comportement du Canard
pour déterminer le vol
*/
bool Canard::voler()
{
	return compVol->voler();
}

CompetenceVol* Canard::getCompVol()
{
	return compVol;
}

void Canard::setCompVol(CompetenceVol* c)
{
    delete compVol;
	compVol = c;
}

CompetenceCancan* Canard::getCompCan()
{
	return compCan;
}

void Canard::setCompCan(CompetenceCancan* c)
{
    delete compCan;
	compCan = c;
}

CompetenceNage* Canard::getCompNage()
{
	return compNage;
}

void Canard::setCompNage(CompetenceNage* c)
{
    delete compNage;
	compNage = c;
}

bool Canard::estVivant()
{
	return (etatCourant != 1 || faim == 0)? false:true;
}
