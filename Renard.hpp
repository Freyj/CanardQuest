#ifndef RENARD_HPP
#define RENARD_HPP

#include "Creature.hpp"
#include <string>
#include "Predateur.hpp"
#include "Canard.hpp"

/**La classe Renard hérite de Prédateur et représente un prédateur terrestre capable de manger le canard et de marcher uniquement là où il n'y a pas d'eau ni d'obstacles */


class Renard:public PredateurSol
{
	public:
		Renard(int a);
		~Renard();
		std::string presentation() override;
		void tuer(Canard* can);
		//void deplacement(int a);
};

#endif
