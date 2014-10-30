#ifndef AFFICHAGE_HPP
#define AFFICHAGE_HPP

#include <string>
#include "Carte.hpp"

class Affichage
{
	private:
		Carte* carte_;
	public:
		//constructeur& destructeur
		Affichage(Carte *c);
		~Affichage();

		//méthodes
		void debut(); //blabla de départ
		bool relancer(); //détermine si le joueur veut recommencer
		void vue(int i);
		char affichTerr(int i);

};
#endif