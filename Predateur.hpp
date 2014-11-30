#ifndef PREDATEUR_HPP
#define PREDATEUR_HPP

#include "Creature.hpp"
#include "Canard.hpp"
#include <string>

/** La classe abstraite Predateur sera la classe mère de tous les prédateurs du jeu, elle est hérite de Creature, et a principalement une fonction utile, tuer().*/

class Predateur: public Creature
{
	private:

	public:
		/** Constructeur de prédateur qui prend un string pour le nom de la créature et initialise sa position à 0 de base. */
		Predateur(std::string nom);
		/** Constructeur de prédateur qui prend un string pour le nom de la créature et un int pour initialiser sa position. */
		Predateur(std::string nom, int p);
		virtual ~Predateur();
		/** Fonction renvoyant un string de présentation pour permettre des tests */
		std::string presentation() override;
		/** Procédure permettant au prédateur de tuer le canard, variable suivant les prédateurs */
		virtual void tuer(Canard* can) = 0;
};


#endif
