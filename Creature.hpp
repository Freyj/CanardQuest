#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include "Comportement.hpp"

class Creature
{
public:
	//Constructeur/Destructeur
	Creature(){};
	~Creature(){};

	//Méthodes relatives à toutes les créatures du jeu
	virtual void deplacement(int a) = 0;  //Gestion du déplacement
	virtual std::string presentation() = 0; //fonction pour tester
};
#endif