#include "Carte.hpp"
#include <iostream>
#include <fstream>

Carte::Carte()
{
	this->tab_ = new int[256];
}

Carte::~Carte()
{
	delete[] this->tab_;
}

void Carte::creerCarte()
{
	std::ifstream f ("carte");
	char a;

	//petit message d'erreur en cas d'absence de fichier
	if (!f.is_open())
		{
			std::cerr << "Impossible d'ouvrir le fichier en lecture !" << std::endl;
	  	}
	//sinon, on lit
	else
	{	
		int cpt = 0;
		//tant qu'il y a à lire & qu'on a pas atteint le bout de la carte
		while(!f.eof() && (cpt <256))
		{
			f.get(a);
			//comme get récupère un char, 0 = 48 en ascii
			this->setTab(cpt, (a-48));
			++cpt;
		}

		f.close();
	}	
}

void Carte::setTab(int a, int b)
{
	if ((0 <= a) && (a < 256))
	{
		this->tab_[a] = b;
	}


}
//avec une petite vérification, si le chiffre n'est pas compris 
//dans les bonnes valeurs, -1
int Carte::getTab(int i)
{
	if ((0 <= i) && (i < 256))
	{
		return this->tab_[i];
	}
	return -1;
}