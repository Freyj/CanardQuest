#include "Affichage.hpp"
#include <iostream>
#include "Carte.hpp"

/**
Constructeur qui donne la carte à l'affichage
*/
Affichage::Affichage(Carte *c)
{
	this->carte_ = c;
}

Affichage::~Affichage()
{
	delete this->carte_;
}
/**
Permet de simplifier l'affichage initial en une fonction
*/
void Affichage::debut()
{
   etoiles();
	std::cout << "Bienvenue sur CanardQuest. Un jeu d'un suspense insoutenable !" << std::endl;
	std::cout << "\nQuel sera le nom de votre canard ?" << std::endl;
}
/**
Fonction permettant de savoir si le joueur décide de relancer une
partie. Renvoie vrai si il tape 1, faux dans tous les autres cas.
*/
bool Affichage::relancer()
{
	int a;
	etoiles();
	std::cout << "Voulez-vous relancer une partie ?\nTapez 1 pour recommencer, toute autre caractere arrêtera le programme." << std::endl;
	std::cin >> a;
	return a==1;
}
/**
Affiche la vue autour de la position i (à une case de diamètre)
(le tableau est créé et détruit à chaque affichage)
*/
void Affichage::vue(int i)
{
    etoiles();
	std::cout << "\nVoici ce que tu vois autour de toi :" << std::endl;
	legende();
	int* vue = new int[9];
	vue = this->carte_->getVue(vue, i);
	std::cout << "  " << affichTerr(vue[0]) << " " << affichTerr(vue[1]) << " "<< affichTerr(vue[2]) << std::endl;
	std::cout << "  " << affichTerr(vue[3]) << " C " << affichTerr(vue[5]) << std::endl;
	std::cout << "  " << affichTerr(vue[6]) << " " << affichTerr(vue[7]) << " " << affichTerr(vue[8]) << "\n" << std::endl;
	delete[] vue;
	affichOcc(i);

}
/** renvoie le char à afficher en fonction du type de terrain
hors map @ 0
eau ~  1
arbre ! 2
herbe . 3
sable - 4
rocher # 5
nid * 6
*/
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
/**
Fonction permettant l'affichage d'une ligne décrivant la case à la position a
*/
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
/**
Fonction permettant l'affichage d'une explication des symboles
*/
void Affichage::legende()
{
	std::cout << " \nC : ton canard    . : un peu d'herbe  ! : un arbre" << std::endl;
	std::cout << "~ : de l'eau      # : un rocher       - : du sable" << std::endl;
	std::cout << "@ : inaccessible  * : un nid          P : un prédateur\n"	<< std::endl;
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
	std::cout << "\n***************************************************\n" << std::endl;
}
