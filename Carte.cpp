#include "Carte.hpp"
#include <iostream>
#include <fstream>

Carte::Carte()
{
	this->tabl_ = new Terrain[256];
	creerCarte();
}

Carte::~Carte()
{
	delete[] this->tabl_;
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
			f >> a;
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
		this->tabl_[a].type = b;
	}


}
//avec une petite vérification, si le chiffre n'est pas compris 
//dans les bonnes valeurs, -1
int Carte::getTab(int i)
{
	if ((0 <= i) && (i < 256))
	{
		return this->tabl_[i].type;
	}
	return -1;
}

/** renvoit ce que le canard voit
// -17 -16 -15
//  -1  X  +1
// +15 +16 +17
// ou vue est un pointeur vers un tableau de 9 cases créées avant
*/
int* Carte::getVue(int* vue, int i)
{
	//ça mettra des -1 dans les cases "hors tableau"
	vue[0] = getTab(i-17);
	vue[1] = getTab(i-16);
	vue[2] = getTab(i-15);
	vue[3] = getTab(i-1);
	vue[4] = getTab(i);
	vue[5] = getTab(i+1);
	vue[6] = getTab(i+15);
	vue[7] = getTab(i+16);
	vue[8] = getTab(i+17);
	return vue;
}
