#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include "Comportement.hpp"

class Creature
{
	protected:
		/** Représente le nom de la créature*/
		std::string nom_; 
		/**donne la position de la créature sur la carte */
		int pos_;

	public:
		//Constructeur/Destructeur
		Creature(){};
		~Creature(){};

		//Méthodes relatives à toutes les créatures du jeu
		virtual void deplacement(int a) = 0;  //Gestion du déplacement
		virtual std::string presentation() = 0; //fonction pour tester
		//méthodes qui changent pas
		std::string getNom();
		void setNom(std::string nom);
		int getPos();
		void setPos(int p);	
};
#endif