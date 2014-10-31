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
	/** Représente le nom du canard*/
	std::string nom_; 
	/**donne la position du canard sur la carte */
	int pos_;
	/**définit le vol et la nage du canard*/
	Comportement* comp;


public:
	/**
	Constructeur du canard, qui prend un string pour le nom_
	*/
	Canard(std::string nom);
	~Canard();
	/**
	*/
	std::string getNom();
	void setNom(std::string nom);
	int getPos();
	void setPos(int p);
	
	void deplacement(int a) override;
	std::string presentation() override;
	void manger();		
	void cancaner();

};

#endif