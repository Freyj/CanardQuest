#include "Affichage.hpp"
#include <iostream>

Affichage::Affichage(Carte *c)
{
	this->carte_ = c;
}

Affichage::~Affichage()
{
	delete carte_;
	carte_ = NULL;
}

void Affichage::debut()
{
	etoiles();
	std::cout << "Bienvenue sur CanardQuest. Un jeu d'un suspense insoutenable !" << std::endl;
	std::cout << "\nQuel sera le nom de votre canard ?" << std::endl;
}

bool Affichage::relancer()
{
	char a;
	etoiles();
	std::cout << "Voulez-vous relancer une partie ?\nTapez 1 pour recommencer, toute autre caractere arrêtera le programme." << std::endl;
	std::cin >> a;
	etoiles();
	return a=='1';
}

void Affichage::vue(int i)
{
	etoiles();
	std::cout << "\nVoici ce que tu vois autour de toi :" << std::endl;
	legende();
	int* vue = new int[9];
	vue = this->carte_->getVue(vue, i);
	std::cout << " " << affichTerr(vue[0]) << " " << affichTerr(vue[1]) << " "<< affichTerr(vue[2]) << std::endl;
	std::cout << " " << affichTerr(vue[3]) << " C " << affichTerr(vue[5]) << std::endl;
	std::cout << " " << affichTerr(vue[6]) << " " << affichTerr(vue[7]) << " " << affichTerr(vue[8]) << "\n" << std::endl;
	delete[] vue;
	affichOcc(i);
}

char Affichage::affichTerr(int i)
{
	switch(i)
	{
		case 0:
		return '@';
		
		case 1:
		return '~';

		case 2:
		return '!';

		case 3:
		return '.';

		case 4:
		return '-';
		
		case 5:
		return '#';
		
		case 6:
		return '*';
		
		default:
		return '@';
	}
}

void Affichage::affichOcc(int o)
{
	int occ = this->carte_->getOccupation(o);
	switch(occ)
	{
		case 0:
		etoiles();
		std::cout << "Il n'y a rien ici.\n" << std::endl;
		etoiles();
		break;

		case 1:
		etoiles();
		if (this->carte_->getType(o) != 1)
		{
			std::cout << "Il y a des graines au sol.\n" << std::endl;
		}
		else
		{
			std::cout << "Il y a des poissons ici.\n" << std::endl;
		}
		etoiles();
		break;

		case 2:
		etoiles();
		if (this->carte_->getType(o) != 1)
		{
			std::cout << "Il y a des brindilles au sol.\n" << std::endl;
		}
		else
		{
			std::cout << "Il y a des brindilles qui flottent sur l'eau\n" << std::endl;
		}
		etoiles();
		break;

		default:
		etoiles();
		std::cout << "Erreur d'occupation.\n" << std::endl;
		etoiles();
		break;
	}
}

void Affichage::legende()
{
	std::cout << " \nC : ton canard . : un peu d'herbe ! : un arbre" << std::endl;
	std::cout << "~ : de l'eau # : un rocher - : du sable" << std::endl;
	std::cout << "@ : inaccessible * : un nid P : un prédateur\n"	<< std::endl;
}

void Affichage::gameOver()
{
	etoiles();
	std::cout << "Malgré tous tes fiers efforts, ton canard est mort." << std::endl;
}

void Affichage::victoire()
{
	etoiles();
	std::cout << "* Bravo, ton canard a réussi à évoluer et à survivre, tu as gagné ! *" << std::endl;
	etoiles();
}

void Affichage::etoiles()
{
	std::cout << "\n***************************************************" << std::endl;
}

void Affichage::setCarte(Carte *c)
{
	this->carte_ = c;
}

void Affichage::tour(int t)
{
	std::cout << "Tu en es a " << t << " tour de jeu." << std::endl;
}

void Affichage::bienvenue(std::string nom)
{
	std::cout << "Bienvenue, " << nom << std::endl;
}

void Affichage::evolNageVol()
{
	std::cout << "Mais ! Tu as des ailes ! Tu pouvais voler depuis tout ce temps ?" << std::endl;
	std::cout << "Et tes pattes ! Elles sont palmées, tu peux donc nager !" << std::endl;
	std::cout << "Pourquoi ne pas l'avoir dit plus tôt ?" << std::endl;
}

void Affichage::evolCancan()
{
	std::cout << "Cancane un peu pour voir ? Ah, tu as un très joli chant" << std::endl;
	//texte pour le moment pas adapté vu qu'on ne peut jamais croiser d'autre canard.
	/*c'est très bien, si tu le fais régulièrement" << std::endl;
	std::cout <<"peut etre qu'un autre canard te rejoindra et que tu ne seras plus seul."<< std::endl; */
}

void Affichage::presentation(std::string pres)
{
	std::cout << pres << std::endl;
}
