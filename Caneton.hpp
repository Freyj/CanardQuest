#ifndef CANETON_HPP
#define CANETON_HPP

#include "Creature.hpp"
#include "Canard.hpp"

//le caneton est la version de départ 
class Caneton: public Canard
{

	public:
		Caneton(std::string nom);
		~Caneton();
		void deplacement(int a);	//méthode de la classe abstraite
		void manger();		
		std::string presentation();// ...
		void cancaner();
};
#endif