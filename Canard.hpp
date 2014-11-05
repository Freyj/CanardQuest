#ifndef CANARD_HPP
#define CANARD_HPP

#include "Creature.hpp"
#include "Comportement.hpp"
/**
Le canard est la classe abstraite  (pas encore très abstraite)
dont vont hériter toutes les étapes
de la vie d'un canard dans le jeu.
*/
class Canard: public Creature
{
protected:
	/**définit le vol et la nage du canard*/
	Comportement* comp;
	/** à 0 le canard est mort de faim*/
	int faim;


public:
	/**
	Constructeur du canard, qui prend un string pour le nom_
	*/
	Canard(std::string nom);
	~Canard();
	/**
	*/
	void deplacement(int a) override;
	std::string presentation() override;

	int getFaim();
	void setFaim(int n);
	void manger();
	void cancaner();
	void statut();
	/**Méthode permettant de définir le vol*/
	virtual void voler() = 0;
	/**Méthode permettant de définir la nage*/
	virtual void nager() = 0;

	bool estVivant();

};

#endif
