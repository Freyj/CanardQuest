#include "Carte.hpp"
#include <iostream>
#include <fstream>
#include <random>

Carte::Carte()
{
	this->tabl_ = new Case[256];
	creerCarte();
	triParType();
}

Carte::~Carte()
{
	delete[] tabl_;
	//delete les tableaux créer dans triParType
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
			//à la création de la carte, il n'y a rien dessus mais
			//on initialise l'occupation tout de même
			this->setOccupation(cpt, 0);
			++cpt;
		}

		f.close();
	}
	remplirCarte();
}

void Carte::creerCarteAlea()
{
	/*
	On crée l'aléatoire (cf cplusplus.com/reference/random)
	(de 1 à 5 pour tous les types de terrains, sauf le nid, et l'hors carte)
	*/
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,5);

	for (int i = 0; i < 256 ; ++i)
	{
		this->tabl_[i].type = distribution(generator);
	}
	//on remplit l'occupation des cases
	remplirCarte();
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
	vue[0] = getTab(i-17);
	vue[1] = getTab(i-16);
	vue[2] = getTab(i-15);
	vue[3] = getTab(i-1);
	vue[4] = getTab(i);
	vue[5] = getTab(i+1);
	vue[6] = getTab(i+15);
	vue[7] = getTab(i+16);
	vue[8] = getTab(i+17);
	//gestion des bords de la carte
	if (i%16 == 0)
	{
		vue[0] = 0;
		vue[3] = 0;
		vue[6] = 0;
	}
	if (i%16 == 15)
	{
		vue[2] = 0;
		vue[5] = 0;
		vue[8] = 0;
	}
	if (i < 15)
	{
		vue[0] = 0;
		vue[1] = 0;
		vue[2] = 0;
	}
	if (i > 239)
	{
		vue[6] = 0;
		vue[7] = 0;
		vue[8] = 0;
	}
	return vue;
}

void Carte::setOccupation(int a, int b)
{
	if ((0 <= a) && (a < 256))
	{
		this->tabl_[a].occupation = b;
	}
}

int Carte::getOccupation(int a)
{
	return this->tabl_[a].occupation;
}

bool Carte::getObstacleSol(int a)
{
	//1 / 2 / 5 = obstacles (eau, arbre, rocher)
	if ((this->getType(a) == 1) || (this->getType(a) == 2) || (this->getType(a) == 5))
	{
		return true;
	}
	return false;
}

bool Carte::getObstacleVol()
{
	//il n'y a pas d'obstacles pour le vol
	return false;
}

bool Carte::getObstacleEau(int a)
{
	//3 / 5 = obstacles (sol, rocher)
	if ((this->getType(a) == 3) || (this->getType(a) == 5))
	{
		return true;
	}
	return false;
}

int Carte::getType(int i)
{
	return this->tabl_[i].type;
}


void Carte::setType(int i, int a)
{
	this->tabl_[i].type = a;
}

void Carte::remplirCarte()
{
	{
		/*Ancienne méthode
		On crée l'aléatoire (cf cplusplus.com/reference/random)
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(0,2);
		D'abord on remplit la carte de nourriture et de brindilles (et de rien) [de 0 à 2]
		*/
		std::random_device rd;//nouvelle methode pour l'aléatoire, merci Charles-Eric! [Meilleure car elle prend le temps passé sur le système depuis une certaine date]
		std::mt19937 rng(rd());
		for (int i = 0 ; i < 256 ; ++i)
		{
		this->tabl_[i].occupation = rng()%3;
		}
	}
}

void Carte::triParType()
{
//je parcours le tableau, dès que je rencontre un type particulier, je l'insère dans son tableau (liste ou vecteur)
    for(int i(0); i<256; ++i)
    {
        if(tabl_[i].type == 1)
        {
            caseEau.push_back(i);
        }
        else if(tabl_[i].type == 3 || tabl_[i].type == 4)
        {
            caseSol.push_back(i);
        }
    }
}


std::vector<int> Carte::getCaseEau()
{
    return caseEau;
}

std::vector<int> Carte::getCaseSol()
{
    return caseSol;
}
