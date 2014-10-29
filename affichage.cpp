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
	std::cout << "/ " << vue[0] << " " << vue[1] << " "<< vue[2] << " \\"<< std::endl;
	std::cout << "| " << vue[3] << " C " << vue[5] << " |"<< std::endl;
	std::cout << "\\ "<< vue[6] << " " << vue[7] << " " << vue[8] << " /" << std::endl;
	delete[] vue;

} 