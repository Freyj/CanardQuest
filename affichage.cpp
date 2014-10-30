#include "affichage.hpp"
#include <iostream>
#include "Carte.hpp"

Affichage::Affichage(Carte *c)
{
	this->carte_ = c;
}

Affichage::~Affichage()
{
	delete this->carte_;
}
//le blabla du départ
void Affichage::debut()
{
	std::cout << "Bienvenue sur CanardQuest." << std::endl;
	std::cout << "Quel sera le nom de votre canard ?" << std::endl;
}
//renvoie 1 si on tape 1, et 0 autrement. Ca évite les "accidents"
bool Affichage::relancer()
{
	int a;
	std::cout << "Voulez-vous relancer une partie ?\n Tapez 1 pour recommencer, toute autre touche arrêtera le programme." << std::endl;
	std::cin >> a;
	return a==1;
}
//renvoie la vue du canard
void Affichage::vue(int i)
{
	int* vue = new int[9];
	vue = this->carte_->getVue(vue, i);
	std::cout << "/ " << affichTerr(vue[0]) << " " << affichTerr(vue[1]) << " "<< affichTerr(vue[2]) << " \\"<< std::endl;
	std::cout << "| " << affichTerr(vue[3]) << " C " << affichTerr(vue[5]) << " |"<< std::endl;
	std::cout << "\\ "<< affichTerr(vue[6]) << " " << affichTerr(vue[7]) << " " << affichTerr(vue[8]) << " /" << std::endl;
	delete[] vue;

} 

//renvoie le char à afficher à partir d'un type de terrain
// error E (en dehors de l'intervalle)
// hors map @ 0
// eau # 1
// arbre ! 2
// herbe . 3
// sable - 4
// nid * 5
char Affichage::affichTerr(int i)
{
	switch(i)
	{
		case 0:
			return '@';

		case 1:
			return '#';

		case 2:
			return '!';
		
		case 3:
			return '.';

		case 4: 
			return '-';

		case 5:
			return '*';

		default:
			return 'E';

	}
}
