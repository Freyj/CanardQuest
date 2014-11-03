#ifndef CANETON_HPP
#define CANETON_HPP

#include "Creature.hpp"
#include "Canard.hpp"
#include "CompCaneton.hpp"

//le caneton est la version de départ 
class Caneton: public Canard 
{

	public:
		Caneton(std::string nom);
		~Caneton();
		void manger();		
		std::string presentation();// ...
		void cancaner();
		void nager();
		void voler();
};
#endif