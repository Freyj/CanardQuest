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
		/**Constructeur*
		\param a un int pour la position*/
		Renard(int a);
		/**Destructeur*/
		~Renard();
		/** \brief Fonction de test
		\return un string*/
		std::string presentation() override;
		/** fonction qui permettra au renard de tuer le canard
		\param can un pointeur vers canard*/
		void tuer(Canard* can);
};

#endif
