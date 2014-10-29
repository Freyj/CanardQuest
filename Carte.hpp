#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>
/**
Classe qui gère la carte du jeu représentée par un tableau 
d'entiers pour le moment (un entier représente un type de terrain)
*/
class Carte
{
protected:
	int* tab_; 
public:
	Carte();
	~Carte();

	/** 
	méthode qui va créer la carte à partir d'un fichier
	*/
	void creerCarte();
	/**
	méthode qui renvoit un string pour savoir quoi afficher ?
	*/
	std::string sendAff();

	//permet de mettre un entier donné (b)sur la case voulue(a)
	void setTab(int a, int b);
	//permet d'accéder à l'entier dans une case voulue
	int getTab(int i);

};
#endif