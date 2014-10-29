#ifndef CARTE_HPP
#define CARTE_HPP

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

};
#endif