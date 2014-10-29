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