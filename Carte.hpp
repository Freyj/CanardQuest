#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>
/**
Classe qui gère la carte du jeu représentée par un tableau 
d'entiers pour le moment (un entier représente un type de terrain)
(deux tableaux d'entiers ? un pour les terrains, un pour l'occupation
avec genre 0 rien, 1 : prédateur, 2 : brindilles, 3 : nourriture
4 : predateur et brindilles, 5 predateur et nourriture 
jamais brindilles et nourriture.) 
structure définie juste pour ça, qui ne sert QUE dans cette classe
*/
class Carte
{
protected:
	struct Terrain
	{
		int type;
		int occupation;
	};
	Terrain* tabl_;
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

	//fonction qui renvoit les cases que le canard voit (+1/-1)
	int* getVue(int* vue, int i);
	//Change l'occupation d'une case
	void setOccupation(int a, int b);
	//Affiche l'occupation d'une case
	int getOccupation(int a);

};
#endif